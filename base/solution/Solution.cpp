/* 
 * File:   Solution.cpp
 * 
 */

#include "Solution.h"
#include "Event.h"
#include <stdexcept>
#include <cstdio>
#include "Instance.h"

using namespace khe;

Solution::Solution(Instance inst){
    sol = KheSolnMake(inst);
}

void Solution::setBack(void *back){
    KheSolnSetBack(sol, back);
}

Instance Solution::getInstance() const{
    return KheSolnInstance(sol);
}

Solution Solution::clone() const{
    return KheSolnCopy(sol);
}

int Solution::getCost() const{
    return KheSolnCost(sol);
}
int Solution::getHardCost() const{
    return KheHardCost(KheSolnCost(sol));
}
int Solution::getSoftCost() const{
    return KheSoftCost(KheSolnCost(sol));
}

std::vector<SolutionGroup> Solution::getSolutionGroups() const{
    return Util::toArray<SolutionGroup>(&KheSolnSolnGroup, sol, KheSolnSolnGroupCount(sol));
}

Meet Solution::createMeet(int duration, const Event &evt){
    return KheMeetMake(sol, duration, evt);
}

std::vector<Meet> Solution::getMeets() const{
    return Util::toArray<Meet>(&KheSolnMeet, sol, KheSolnMeetCount(sol));
}

std::vector<Meet> Solution::getMeets(const Event &evt) const{
    return Util::toArray2<Meet>(&KheEventMeet, sol, static_cast<KHE_EVENT>(evt), 
            KheEventMeetCount(sol, static_cast<KHE_EVENT>(evt)));
}

std::vector<Meet> Solution::getCycleMeets() const{
    //todo: follow the proposed optimization (see documentation)
    std::vector<Meet> cycles;
    
    for(auto &meet : getMeets())
        if(meet.isCyclic())
            cycles.push_back(meet);
    return cycles;
}

void Solution::remove(const Meet &meet){
    KheMeetDelete(meet);
}

std::vector<Task> Solution::getTasks() const{
    return Util::toArray<Task>(&KheSolnTask, sol, KheSolnTaskCount(sol));
}

std::vector<Task> Solution::getTasks(const EventResource &er) const{
    return Util::toArray2<Task>(&KheEventResourceTask, sol, static_cast<KHE_EVENT_RESOURCE>(er), 
                KheEventResourceTaskCount(sol, static_cast<KHE_EVENT_RESOURCE>(er)));
}

void Solution::setDescription(const std::string &desc){
    KheSolnSetDescription(sol, Util::sTc(desc));
}

std::string Solution::getDescription() const{
    return KheSolnDescription(sol);
}

void Solution::setRunningTime(float time){
   return KheSolnSetRunningTime(sol, time); 
}

float Solution::getRunningTime() const{
    return KheSolnRunningTime(sol);
}

float Solution::getSoftTimeLimit() const{
    return KheSolnTimeLimit(sol);
}
void Solution::setSoftTimeLimit(float limit){
    KheSolnSetTimeLimit(sol, limit);
}

bool Solution::reachedSoftTimeLimit() const{
    return KheSolnTimeLimitReached(sol);
}

void Solution::debug(int verbosity, int indent, FILE *fp) const{
    KheSolnDebug(sol, verbosity, indent, fp);
}

int Solution::getDiversifier() const{
    return KheSolnDiversifier(sol);
}

void Solution::setDiversifier(int div){
    KheSolnSetDiversifier(sol, div);
}

int Solution::chooseDiversifier(int c){
    return KheSolnDiversifierChoose(sol, c);
}

float Solution::getElapsedTime() const{
    return KheSolnTimeNow(sol);
}

void Solution::complete(){
    KHE_EVENT prob;
    bool success = KheSolnMakeCompleteRepresentation(sol, &prob);
    
    if(!success)
        throw std::runtime_error(std::string("Failed to complete solution due to event") + (Event(prob)).getId());
}


void Solution::assignPreassignedTimes(){
    KheSolnAssignPreassignedTimes(sol);
}

void Solution::assignPreassignedResources(){
    for(auto rt : getInstance().getResourceTypes())
        assignPreassignedResources(rt);
}

void Solution::assignPreassignedResources(const ResourceType &rt){
    KheSolnAssignPreassignedResources(sol, rt);
}
