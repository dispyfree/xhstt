/* 
 * File:   EventGroup.cpp
 * 
 */

#include "EventGroup.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "Constraint.h"
#include "EventGroupKind.h"
#include "Event.h"

using namespace khe;

EventGroup::EventGroup(Instance inst, EventGroupKind kind, const std::string &id, 
            const std::string &name){
    if(!KheEventGroupMake(inst, kind, Util::sTc(id), Util::sTc(name), &grp))
        throw ObjectCreation("Unable to create EventGroup");
}

EventGroup::EventGroup(Instance inst, const std::string &id, 
            const std::string &name){
    if(!KheEventGroupMake(inst, EventGroupKind::getOrdinary(), Util::sTc(id), Util::sTc(name), &grp))
        throw ObjectCreation("Unable to create EventGroup");
}


EventGroup::EventGroup(KHE_EVENT_GROUP grp){
    Util::rnn(grp);
    this->grp = grp;
}

EventGroup::~EventGroup() {
}

void EventGroup::setBack(void *back){
    KheEventGroupSetBack(grp, back);
}


Instance EventGroup::getInstance() const{
    return KheEventGroupInstance(grp);
}

EventGroupKind EventGroup::getKind() const{
    return KheEventGroupKind(grp);
}

std::string EventGroup::getId() const{
    return KheEventGroupId(grp);
}

std::string EventGroup::getName() const{
    return KheEventGroupName(grp);
}

void EventGroup::add(Event e){
    KheEventGroupAddEvent(grp, e);
}

void EventGroup::sub(Event e){
    KheEventGroupSubEvent(grp, e);
}

void EventGroup::doUnion(const EventGroup &grp2){
    KheEventGroupUnion(grp, grp2);
}

void EventGroup::intersect(const EventGroup &grp2){
    KheEventGroupIntersect(grp, grp2);
}

void EventGroup::difference(const EventGroup &grp2){
    KheEventGroupDifference(grp, grp2);
}

IR<Event> EventGroup::getEvents() const{
    return createIter<Event>(*this);
}

bool EventGroup::contains(const Event &e) const{
    return KheEventGroupContains(grp, e);
}

bool EventGroup::equals(const EventGroup &grp2) const{
    return KheEventGroupEqual(grp, grp2);
}


bool EventGroup::isSubSet(const EventGroup grp2) const{
    return KheEventGroupSubset(grp, grp2);
}

bool EventGroup::isDisjoint(const EventGroup &grp2) const{
    return KheEventGroupDisjoint(grp, grp2);
}

IR<Constraint> EventGroup::getConstraints() const{
    return createIter<Constraint>(*this);
}

EventGroup::operator int() const{
    return getNumId(getId());
}

EventGroup::operator KHE_EVENT_GROUP() const{
    return grp;
}

bool EventGroup::operator==(const EventGroup &eg2) const{
    return getId() == eg2.getId();
}

bool EventGroup::operator<(const EventGroup &eg2) const{
    return getId() < eg2.getId();
}

std::string EventGroup::getObjType() const{
    return "EventGroup";
}
