/* 
 * File:   Instance.cpp
 * 
 */

#include <string>
#include <map>

#include "Instance.h"
#include "InstanceMetaData.h"
#include "Archive.h"

#include "Constraint.h"

#include "Time.h"
#include "TimeGroup.h"

#include "Event.h"
#include "EventGroup.h"
#include "EventResource.h"


#include "Resource.h"
#include "ResourceType.h"
#include "ResourceGroup.h"
#include "KheObjIter.h"

using namespace khe;


Instance::Instance(const std::string &id, InstanceMetaData meta){
    inst = KheInstanceMakeBegin(Util::sTc(id.c_str()), meta);
}

void Instance::end(bool inferResourcePartitions){
    KheInstanceMakeEnd(inst, inferResourcePartitions);
}

Instance::Instance(const Instance& orig){
    inst = orig.inst;
}

Instance::Instance(KHE_INSTANCE inst){
    this->inst = inst;
}

Instance::~Instance() {}


void Instance::setBack(void *back){
     KheInstanceSetBack(inst, back);
 }


std::string Instance::getId() const{
    return std::string(KheInstanceId(inst));
}

std::string Instance::getName() const{
    return std::string(KheInstanceName(inst));
}

InstanceMetaData Instance::getMeta() const{
    return InstanceMetaData(KheInstanceMetaData(inst));
}

IR<Archive> Instance::getContainingArchives() const{
    return createIter<Archive>(*this);
}

IR<TimeGroup> Instance::getTimeGroups() const{
    return createIter<TimeGroup>(*this);
}

TimeGroup Instance::getTimeGroup(const std::string &name) const{
    return Util::retrieve<TimeGroup, KHE_TIME_GROUP>(
            inst, &KheInstanceRetrieveTimeGroup, Util::cc(name.c_str()));
}

TimeGroup Instance::getTimeGroup(int id) const{
    return KheInstanceTimeGroup(inst, id);
}

IR<Time> Instance::getTimes() const{
    return createIter<Time>(*this);
}

std::vector<Time> Instance::getTimesWithDummy() const{
        auto times = getTimes();
        std::vector<Time> modTimes(times.begin(), times.end());
        modTimes.push_back(Time::getDummy());
        
        return std::move(modTimes);
 }

Time Instance::getTime(const std::string &id) const{
    return Util::retrieve<Time>(
            inst, &KheInstanceRetrieveTime, Util::cc(id.c_str()));
}

Time Instance::getTime(int timeId) const{
    return KheInstanceTime(inst, timeId);
}

TimeGroup Instance::getFullTimeGroup(){
    return TimeGroup(KheInstanceFullTimeGroup(inst));
}

TimeGroup Instance::getEmptyTimeGroup(){
    return TimeGroup(KheInstanceEmptyTimeGroup(inst));
}


IR<ResourceType>   Instance::getResourceTypes() const{
    return createIter<ResourceType>(*this);
}

ResourceType    Instance::getResourceType(const std::string &name) const{
    return Util::retrieve<ResourceType>(inst, &KheInstanceRetrieveResourceType, Util::cc(name.c_str()));
}

ResourceType    Instance::getResourceType(int id) const{
    return KheInstanceResourceType(inst, id);
}

ResourceGroup   Instance::getResourceGroup(const std::string &name) const{
    return Util::retrieve<ResourceGroup>(inst, &KheInstanceRetrieveResourceGroup, Util::cc(name.c_str()));
}

Resource        Instance::getResource(const std::string &name) const{
    return Util::retrieve<Resource>(inst, &KheInstanceRetrieveResource, Util::cc(name.c_str()));
}

Resource        Instance::getResource(int id) const{
    return KheInstanceResource(inst, id);
}

IR<Resource>   Instance::getResources() const{
    return createIter<Resource>(*this);
}

std::vector<Resource> Instance::getResourcesWithDummy() const{
        auto resources = getResources();
        std::vector<Resource> modResources(resources.begin(), resources.end());
        modResources.push_back(Resource::getDummy());
        return std::move(modResources);
}
        
IR<Resource> Instance::getResources(const ResourceType &type) const{
    return type.getResources();
}


IR<EventGroup> Instance::getEventGroups() const{
    return createIter<EventGroup>(*this);
}

EventGroup  Instance::getEventGroup(const std::string &name) const{
     return Util::retrieve<EventGroup>(inst, &KheInstanceRetrieveEventGroup, Util::cc(name.c_str()));
}

EventGroup  Instance::getEventGroup(int id) const{
     return KheInstanceEventGroup(inst, id);
}
    
EventGroup  Instance::getFullEventGroup() const{
    return EventGroup(KheInstanceFullEventGroup(inst));
}

EventGroup  Instance::getEmptyEventGroup() const{
    return EventGroup(KheInstanceEmptyEventGroup(inst));
}
    
IR<Event>   Instance::getEvents() const{
    return createIter<Event>(*this);
}

Event       Instance::getEvent(const std::string &name) const{
    return Util::retrieve<Event>(inst, &KheInstanceRetrieveEvent, Util::cc(name.c_str()));
}

Event       Instance::getEvent(int id) const{
    return KheInstanceEvent(inst, id);
}
    
IR<EventResource> Instance::getEventResources() const{
    return createIter<EventResource>(*this);
}

EventResource Instance::getEventResource(int id) const{
    return KheInstanceEventResource(inst, id);
}


IR<Constraint> Instance::getConstraints() const{
    return createIter<Constraint>(*this);
}

Constraint  Instance::getConstraint(const std::string &id) const{
    return Util::retrieve<Constraint>(inst, &KheInstanceRetrieveConstraint, Util::cc(id));
}

Constraint  Instance::getConstraint(int id) const{
    return KheInstanceConstraint(inst, id);
}

int Instance::constraintDensityCount(Constraint::Tag tag) const{
    return KheInstanceConstraintDensityCount(inst, static_cast<KHE_CONSTRAINT_TAG>(tag));
}

int Instance::constraintDensityTotal(Constraint::Tag tag) const{
    return KheInstanceConstraintDensityTotal(inst, static_cast<KHE_CONSTRAINT_TAG>(tag));
}
