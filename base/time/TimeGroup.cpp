/* 
 * File:   TimeGroup.cpp
 * 
 */

#include "TimeGroup.h"
#include "Instance.h"
#include "ObjectCreation.h"
#include "Time.h"

using namespace khe;

TimeGroup::TimeGroup(Instance &inst, Kind kind, const std::string &id, const std::string &name){
    if(!KheTimeGroupMake(inst, static_cast<KHE_TIME_GROUP_KIND>(kind), Util::sTc(id), Util::sTc(name), &grp))
            throw ObjectCreation("Unable to create TimeGroup");
}
TimeGroup::TimeGroup(KHE_TIME_GROUP grp){
    Util::rnn(grp);
    this->grp = grp;
}


void TimeGroup::setBack(void *back){
    KheTimeGroupSetBack(grp, back);
}

Instance TimeGroup::getInstance() const{
    return KheTimeGroupInstance(grp);
}

TimeGroup::Kind TimeGroup::getKind() const{
    return static_cast<TimeGroup::Kind>(KheTimeGroupKind(grp));
}

std::string TimeGroup::getId() const{
    return KheTimeGroupId(grp);
}

std::string TimeGroup::getName() const{
    return KheTimeGroupName(grp);
}
    
void TimeGroup::add(Time &t){
    KheTimeGroupAddTime(grp, t);
}

void TimeGroup::sub(Time &t){
    KheTimeGroupSubTime(grp, t);
}

void TimeGroup::doUnion(TimeGroup &tg2){
    KheTimeGroupUnion(grp, tg2);
}

void TimeGroup::intersect(TimeGroup &tg2){
    KheTimeGroupIntersect(grp, tg2);
}

void TimeGroup::difference(TimeGroup &tg2){
    KheTimeGroupDifference(grp, tg2);
}
    
IR<Time> TimeGroup::getTimes() const{
    return createIter<Time>(*this);
}
    
bool TimeGroup::contains(const Time &t){
    return KheTimeGroupContains(grp, t);
}

bool TimeGroup::equals(const TimeGroup &tg2){
    return KheTimeGroupEqual(grp, tg2);
}

bool TimeGroup::isSubsetOf(const TimeGroup &tg2){
    return KheTimeGroupSubset(grp, tg2);
}

bool TimeGroup::isDisjoint(const TimeGroup &tg2){
    return KheTimeGroupDisjoint(grp, tg2);
}

bool TimeGroup::isCompact(){
    return KheTimeGroupIsCompact(grp);
}

bool TimeGroup::overlaps(const Time &t, int duration){
    return KheTimeGroupOverlap(grp, t, duration);
}

TimeGroup TimeGroup::neighbour(int delta){
    return KheTimeGroupNeighbour(grp, delta);
}

std::string TimeGroup::getObjType() const{
    return "TimeGroup";
}

bool TimeGroup::operator==(const TimeGroup &tg2) const{
    return getId() == tg2.getId();
}

bool TimeGroup::operator <(const TimeGroup &tg2) const{
    return getId() < tg2.getId();
}

TimeGroup::operator int() const{
    return getNumId(getId());
}

TimeGroup::operator KHE_TIME_GROUP() const{
    return grp;
}

