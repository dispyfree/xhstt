/* 
 * File:   Meet.cpp
 * 
 */

#include "Meet.h"
#include "ObjectCreation.h"
#include "RequestedObjectNotFound.h"
#include "Solution.h"
#include "Time.h"
#include "Resource.h"
using namespace khe;

Meet::Meet(Solution &sol, int duration, Event &evt){
    if(duration < 1)
        throw ObjectCreation("Duration must be at least 1");
    meet = KheMeetMake(sol, duration, evt);
}

Meet::Meet(Solution &sol, int duration){
    if(duration < 1)
        throw ObjectCreation("Duration must be at least 1");
    
    meet = KheMeetMake(sol, duration, NULL);
}

void Meet::setBack(void *back){
    KheMeetSetBack(meet, back);
}

Solution Meet::getSolution() const{
    return KheMeetSoln(meet);
}

int Meet::getSolutionIndex() const{
    return KheMeetSolnIndex(meet);
}

int Meet::getDuration() const{
    return KheMeetDuration(meet);
}

std::pair<Meet, Meet> Meet::split(int duration, bool recursive){
    if(!KheMeetSplitCheck(meet, duration, recursive))
        throw std::runtime_error("Unable to split meet");
    
    KHE_MEET meet1, meet2;
    KheMeetSplit(meet, duration, recursive, &meet1, &meet2);
    
    return std::make_pair(Meet(meet1), Meet(meet2));
}

bool Meet::hasAssignedEvent() const{
    return KheMeetEvent(meet) != NULL; 
}

Event Meet::getEvent() const{
    KHE_EVENT evt = KheMeetEvent(meet);
    
    if(evt == NULL)
        throw RequestedObjectNotFound("there is no assigned Event");
    return evt;
}

Time Meet::getAssignedTime() const{
    KHE_TIME time = KheMeetAsstTime(meet);
    if(time == NULL)
        throw RequestedObjectNotFound("The meet's upper chain does not contain a cycle meet");
    return time;
}

bool Meet::moveTime(const Time &time){
    return KheMeetMoveTime(meet, time);
}

bool Meet::assignTime(const Time &time){
    return KheMeetAssignTime(meet, time);
}

bool Meet::unaAssignTime(){
    return KheMeetUnAssignTime(meet);
}

bool Meet::hasPreassignedTime() const{
    return KheMeetIsPreassigned(meet, NULL);
}

Time Meet::getPreassignedtime() const{
    KHE_TIME tmp;
    bool success = KheMeetIsPreassigned(meet, &tmp);
    
    if(!success)
        throw RequestedObjectNotFound("there is no preassigned time");
    return tmp;
}

std::vector<Task> Meet::getTasks() const{
    return Util::toArray<Task>(&KheMeetTask, meet, KheMeetTaskCount(meet));
}

Task Meet::getTask(const std::string &role) const{
    return Util::retrieve<Task>(meet, &KheMeetRetrieveTask, Util::sTc(role));
}
Task Meet::findTask(const EventResource &er) const{
    return Util::retrieve<Task>(meet, &KheMeetFindTask, static_cast<KHE_EVENT_RESOURCE>(er));
}

bool Meet::preassignsResource(const Resource &r) const{
    KHE_TASK task;
    return KheMeetContainsResourcePreassignment(meet, r, &task);
}
bool Meet::assignsResource(const Resource &r) const{
    KHE_TASK task;
    return KheMeetContainsResourceAssignment(meet, r, &task);
}

bool Meet::assignCheck(const Meet &target, int offset) const{
    return KheMeetAssignCheck(meet, target, offset);
}

bool Meet::assign(const Meet &target, int offset){
    return KheMeetAssign(meet, target, offset);
}

bool Meet::unassignCheck() const{
    return KheMeetAssignCheck(meet, NULL, 0);
}

bool Meet::unassign(){
    return KheMeetAssign(meet, NULL, 0);
}

bool Meet::hasAssignment() const{
    return KheMeetAsst(meet) != NULL;
}

Meet Meet::getAssignment() const{
    KHE_MEET assign = KheMeetAsst(meet);
    if(assign == NULL)
        throw RequestedObjectNotFound("Meet is not assigned");
    return assign;
}

int Meet::getOffset() const{
    return KheMeetAsstOffset(meet);
}

bool Meet::isCyclic() const{
    return KheMeetIsCycleMeet(meet);
}

void Meet::debug( int verbosity, int indent, FILE *fp) const{
    KheMeetDebug(meet, verbosity, indent, fp);
}
    
void Meet::remove(){
    KheMeetDelete(meet);
}


