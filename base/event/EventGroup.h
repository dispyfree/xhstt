/* 
 * File:   EventGroup.h
 * 
 */

#ifndef EVENTGROUP_H
#define	EVENTGROUP_H

#include "Instance.h"
#include "Event.h"
#include "EventGroupKind.h"
#include "CachedObj.h"

#include <string>
#include <vector>

namespace khe{
    
    class Instance;
    class EventGroupKind;
    class Event;
    class Constraint;
    
class EventGroup : CachedObj<EventGroup>{
public:
    using KheType = KHE_EVENT_GROUP;
    
    EventGroup(Instance inst, EventGroupKind kind, const std::string &id, 
            const std::string &name);
    EventGroup(Instance inst, const std::string &id, 
            const std::string &name);
    EventGroup(KHE_EVENT_GROUP grp);
    virtual ~EventGroup();
    
    void setBack(void *back);
    void *getBack() const {
         return KheEventGroupBack(grp);
    }
    
    std::string getObjType() const;
    
    Instance getInstance() const;
    EventGroupKind getKind() const;
    std::string getId() const;
    std::string getName() const;
    
    void add(Event e);
    void sub(Event e);
    void doUnion(const EventGroup &grp2);
    void intersect(const EventGroup &grp2);
    void difference(const EventGroup &grp2);
    
    IR<Event> getEvents() const;
    
    bool contains(const Event &e) const;
    bool equals(const EventGroup &gr) const;
    bool isSubSet(const EventGroup gr) const;
    bool isDisjoint(const EventGroup &gr) const;
    
    IR<Constraint> getConstraints() const;
    
    
    operator int() const;
    operator KheType() const;
    
    /**
     * Caution: this does NOT use the equivalence relation as implied by 
     * "equals". It just compares on the KHE object level for storage in containers.
     * @param eg2
     * @return 
     */
    bool operator==(const EventGroup &eg2) const;
    bool operator<(const EventGroup &eg2) const;
    
protected:
    KheType grp;

};

}

#endif	/* EVENTGROUP_H */

