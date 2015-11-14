/* 
 * File:   EventResource.cpp
 * 
 */

#include "EventResource.h"
#include "EventResourceGroup.h"
#include "Event.h"
#include "ResourceType.h"
#include "Resource.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "Ident.h"
#include <sstream>
#include <map>
using namespace khe;

EventResource::EventResource(Event evt, ResourceType rt, Resource preassigned, const std::string &role, int workload){
    if(!KheEventResourceMake(evt, rt, preassigned, Util::sTc(role), workload, &er))
        throw ObjectCreation("Unable to create EventResource");
}

EventResource::EventResource(Event evt, ResourceType rt, const std::string &role, int workload){
    if(!KheEventResourceMake(evt, rt, NULL, Util::sTc(role), workload, &er))
        throw ObjectCreation("Unable to create EventResource");
}

EventResource::EventResource(KHE_EVENT_RESOURCE raw){
    Util::rnn(raw);
    er = raw;
}

void EventResource::setBack(void *back){
    KheEventResourceSetBack(er, back);
}

Instance EventResource::getInstance() const{
    return KheEventResourceInstance(er);
}

int EventResource::getInstanceIndex() const{
    return KheEventResourceInstanceIndex(er);
}

Event EventResource::getEvent() const{
    return KheEventResourceEvent(er);
}

int EventResource::getEventIndex() const{
    return KheEventResourceEventIndex(er);
}

ResourceType EventResource::getType() const{
    return KheEventResourceResourceType(er);
}

bool EventResource::hasPreassignedResource() const{
    return KheEventResourcePreassignedResource(er) != NULL;
}

Resource EventResource::getPreassignedResource() const{
    return KheEventResourcePreassignedResource(er);
}

std::string EventResource::getRole() const{
    char *str = KheEventResourceRole(er);
    /**
     * Some experts set Role = "0"
     * AustraliaBGHS98.xml
     */
    if(str == NULL)
        return "";
    return str;
}

int EventResource::getWorkload() const{
    return KheEventResourceWorkload(er);
}

IR<Constraint> EventResource::getConstraints() const{
    return createIter<Constraint>(*this);
}

int EventResource::getConstraintEventGroupIndex(int i) const{
    return KheEventResourceConstraintEventGroupIndex(er, i);
}

ResourceGroup EventResource::getHardDomain() const{
    return KheEventResourceHardDomain(er);
}

ResourceGroup EventResource::getSoftDomain() const{
    return KheEventResourceHardAndSoftDomain(er);
}


std::string EventResource::getId() const{
    //the event resource is unique as per eventID + index of er in event
    //todo: optimize heavily
    std::stringstream stream;
    stream << getEventIndex();
    std::string uniqueIndex;
    stream >> uniqueIndex;
    
    return getEvent().getId() + uniqueIndex + std::string("ER");
}

bool EventResource::operator<(const EventResource &er2) const{
    return getInstanceIndex() < er2.getInstanceIndex();
}

//This will return the EVENT index 
EventResource::operator int() const{
    return getEventIndex();
}

EventResource::operator std::string() const{
    return getId();
}

EventResource::operator KHE_EVENT_RESOURCE() const{
    return er;
}
