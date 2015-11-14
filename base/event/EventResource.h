/* 
 * File:   EventResource.h
 * 
 */

#ifndef EVENTRESOURCE_H
#define	EVENTRESOURCE_H

#include "global.h"

namespace khe{
    
    class ResourceGroup;
    class Event;
    class ResourceType;
    class Resource;
    class Instance;
    class Constraint;
    
class EventResource{
public:
    using KheType = KHE_EVENT_RESOURCE;
    EventResource(Event evt, ResourceType rt, Resource preassigned, const std::string &role, int workload);
    EventResource(Event evt, ResourceType rt, const std::string &role, int workload);
    EventResource(KheType res);
    virtual ~EventResource(){}
    
    std::string getObjType() const {return "EventResource"; }
    
    void setBack(void *back);
    void *getBack() const {
         return KheEventResourceBack(er);
    }
    
    Instance getInstance() const;
    int getInstanceIndex() const;
    Event getEvent() const;
    int getEventIndex() const;
    ResourceType getType() const;
    bool hasPreassignedResource() const;
    Resource getPreassignedResource() const;
    std::string getRole() const;
    int getWorkload() const;
    
    IR<Constraint> getConstraints() const;
    int getConstraintEventGroupIndex(int i) const; 
    
    ResourceGroup getHardDomain() const;
    ResourceGroup getSoftDomain() const;
    
    bool operator<(const EventResource &er2) const;
    
    //This will return the EVENT index 
    operator int() const;
    operator std::string() const;
    operator KheType() const;
     
    
    std::string getId() const;
    
protected:
    KheType er;
    

};

}
#endif	/* EVENTRESOURCE_H */

