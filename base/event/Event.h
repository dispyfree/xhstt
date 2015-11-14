/* 
 * File:   Event.h
 * 
 */

#ifndef EVENT_H
#define	EVENT_H

#include "global.h"
#include "EventGroup.h"
#include "EventResourceGroup.h"
#include "Constraint.h"

namespace khe{
    

    class Instance;
    class Event;
    class EventResource;
    class Resource;
    class Time;
    
class Event{
public:
    using KheType = KHE_EVENT;
    
    Event(Instance inst, const std::string &id, const std::string &name, const std::string &color,
            int duration, int workload, Time preassignedTime);
    
    Event(Instance inst, const std::string &id, const std::string &name, const std::string &color,
            int duration, int workload);
    /**
     * CAUTION: other order for parameters, omitted color!
     */
    Event(Instance inst, const std::string &id, const std::string &name,
            int duration, int workload);
    
    Event(KHE_EVENT evt);
    virtual ~Event();
    
    void setBack(void *back);
    void *getBack() const {
         return KheEventBack(evt);
    }
    
    Instance getInstance() const;
    std::string getId() const;
    std::string getName() const;
    std::string getColor() const;
    int getDuration() const;
    int getWorkload() const;
    bool hasPreassignedTime() const;
    Time getPreassignedTime() const;
    
    int getIndex() const;
    int getDemand() const;
    
    IR<EventResource> getResources() const;
    EventResource getResource(const std::string &role) const;
    
    IR<EventResourceGroup> getResourceGroups() const;
    EventGroup getSingletonEventGroup() const;
    
    IR<Constraint> getConstraints() const;
    
    bool isSimilarTo(const Event &e) const;
    bool isMergeableWith(const Event &e, int slack) const;
    bool sharesPreassignedResourceWith(const Event &e) const;
    Resource getSharedPreassignedResourceWith(const Event &e) const;
    
    
    bool operator==(const Event &evt2) const{
        return getId() == evt2.getId();
    }
    
    bool operator<(const Event &evt2) const{
        return getId() < evt2.getId();
    }
    
    operator KheType() const{
        return evt;
    }
    
    operator int() const{
        return getIndex();
    }
    
    operator std::string() const{
        return getId();
    }
    
    virtual std::string getObjType() const{
        return "Event";
    }
    
    
protected:
    KheType evt;
};

}

#endif	/* EVENT_H */

