/* 
 * File:   Instance.h
 * 
 */

#ifndef INSTANCE_H
#define INSTANCE_H

#include "global.h"
#include "InstanceMetaData.h"
#include "ResourceGroup.h"
#include "Resource.h"
#include "Constraint.h"

#include "KheObjIter.h"

#include <map>

namespace khe{

    class Archive;
    class Time;
    class TimeGroup;
    class ResourceType;
    class Event;
    class EventGroup; 
    class EventResource;
    
class Instance {
public:
    
    using KheType = KHE_INSTANCE;
    
     /**
     * After creating a new instance, end _must_ be called 
     * @see KheInstanceMakeBegin
     * @see KheInstanceMakeEnd
     * @see end
     * @param id
     * @param meta
     */
    Instance(const std::string &id, InstanceMetaData meta);
    void end(bool inferResourcePartitions);
    Instance(const Instance& orig);
    Instance(KheType inst);
    virtual ~Instance();
    
    
    /**
     * Miscellaneous and ubiquitous methods
     * @return 
     */
    std::string getId() const;
    std::string getName() const;
    InstanceMetaData     getMeta() const;
    IR<Archive> getContainingArchives() const;
    
    void setBack(void *back);
    void *getBack() const {
         return KheInstanceBack(inst);
    }
    
    
    
    
    /**
     * time related functionality
     */

    IR<TimeGroup>  getTimeGroups() const;
    TimeGroup getTimeGroup(const std::string &name) const;
    TimeGroup getTimeGroup(int id) const;
    
    IR<Time>        getTimes() const;
    std::vector<Time> getTimesWithDummy() const;
    Time getTime(const std::string &id) const;
    Time getTime(int timeId) const;
    
    /**
     * Those two are necessary special groups:
     * the full time group encompasses _all_ times while
     * the empty time group is just empty
     * @return 
     */
    TimeGroup getFullTimeGroup();
    TimeGroup getEmptyTimeGroup();
    
    
    /**
     * Resource related methods
     */
    IR<ResourceType>     getResourceTypes() const;
    ResourceType         getResourceType(const std::string &name) const;
    ResourceType         getResourceType(int id) const;
   
    ResourceGroup        getResourceGroup(const std::string &name) const;
    Resource             getResource(const std::string &name) const;
    Resource             getResource(int id) const;
    
    IR<Resource>            getResources() const;
    std::vector<Resource>   getResourcesWithDummy() const;
    IR<Resource>            getResources(const ResourceType &type) const;
    
    
    /**
     * Event related functionality
     */
    IR<EventGroup>          getEventGroups() const;
    EventGroup              getEventGroup(const std::string &name) const;
    EventGroup              getEventGroup(int id) const;
    
    EventGroup              getFullEventGroup() const;
    EventGroup              getEmptyEventGroup() const;
    
    IR<Event>               getEvents() const;
    Event                   getEvent(const std::string &name) const;
    Event                   getEvent(int evtId) const;
    
    IR<EventResource>       getEventResources() const;
    EventResource           getEventResource(int id) const;
    
    
    
    /**
     * Constraint related functionality
     * @return 
     */
    IR<Constraint>          getConstraints() const;
    Constraint              getConstraint(const std::string &name) const;
    Constraint              getConstraint(int id) const;
    int                     constraintDensityCount(Constraint::Tag tag) const;
    int                     constraintDensityTotal(Constraint::Tag tag) const;
    
    operator KheType() const{
        return inst;
    }
    
    bool operator==(const Instance &inst2) const{
        return getId() == inst2.getId();
    }
    
protected:
    KheType inst;

};
}

#endif	/* INSTANCE_H */

