/* 
 * File:   Event.cpp
 * 
 */


#include "Event.h"
#include "EventResource.h"
#include "EventGroup.h"
#include "Instance.h"
#include "Time.h"
#include "ObjectCreation.h"
#include "RequestedObjectNotFound.h"
#include "Resource.h"
#include "EventResourceGroup.h"

using namespace khe;

Event::Event(Instance inst, const std::string &id, const std::string &name, const std::string &color,
            int duration, int workload, Time preassignedTime){
    if(!KheEventMake(inst, Util::sTc(id), Util::sTc(name), Util::sTc(color), duration, workload,
            preassignedTime, &evt))
        throw ObjectCreation("Unable to create Event");
}

Event::Event(Instance inst, const std::string &id, const std::string &name, const std::string &color,
            int duration, int workload){
    if(!KheEventMake(inst, Util::sTc(id), Util::sTc(name), Util::sTc(color), duration, workload,
            NULL, &evt))
        throw ObjectCreation("Unable to create Event");
}

Event::Event(Instance inst, const std::string &id, const std::string &name,
            int duration, int workload){
    static std::string color("none");
    if(!KheEventMake(inst, Util::sTc(id), Util::sTc(name), Util::sTc(color), duration, workload,
            NULL, &evt))
        throw ObjectCreation("Unable to create Event");
}

Event::Event(KHE_EVENT raw){
    Util::rnn(raw);
    evt = raw;
}

Event::~Event() {
}

void Event::setBack(void *back){
    KheEventSetBack(evt, back);
}

Instance Event::getInstance() const{
    return KheEventInstance(evt);
}

std::string Event::getId() const{
    return KheEventId(evt);
}

std::string Event::getName() const{
    return KheEventName(evt);
}

std::string Event::getColor() const{
    return KheEventColor(evt);
}

int Event::getDuration() const{
    return KheEventDuration(evt);
}

int Event::getWorkload() const{
    return KheEventWorkload(evt);
}

bool Event::hasPreassignedTime() const{
    return KheEventPreassignedTime(evt) != NULL;
}

Time Event::getPreassignedTime() const{
    auto time = KheEventPreassignedTime(evt);
    
    if(time == NULL)
        throw RequestedObjectNotFound("Does not have a preassigned time");
    return time;
}

int Event::getIndex() const{
    return KheEventIndex(evt);
}

int Event::getDemand() const{
    return KheEventDemand(evt);
}

IR<EventResource> Event::getResources() const{
    return createIter<EventResource>(*this);
}

EventResource Event::getResource(const std::string &role) const{
    return Util::retrieve<EventResource>(evt, &KheEventRetrieveEventResource, Util::sTc(role));
}

IR<EventResourceGroup> Event::getResourceGroups() const{
    return createIter<EventResourceGroup>(*this);
}

EventGroup Event::getSingletonEventGroup() const{
    return KheEventSingletonEventGroup(evt);
}

IR<Constraint> Event::getConstraints() const{
    return createIter<Constraint>(*this);
}

bool Event::isSimilarTo(const Event &e) const{
    return KheEventSimilar(evt, e);
}

bool Event::isMergeableWith(const Event &e, int slack) const{
    return KheEventMergeable(evt, e, slack);
}

bool Event::sharesPreassignedResourceWith(const Event &e) const{
    KHE_RESOURCE r;
    return KheEventSharePreassignedResource(evt, e, &r);
}
Resource Event::getSharedPreassignedResourceWith(const Event &e) const{
    KHE_RESOURCE r;
    if(!KheEventSharePreassignedResource(evt, e, &r))
        throw RequestedObjectNotFound("SharedPreassignedResource not found");
    
    return r;
}