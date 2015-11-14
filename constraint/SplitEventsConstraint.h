/* 
 * File:   SplitEventsConstraint.h
 * 
 */

#ifndef SPLITEVENTSCONSTRAINT_H
#define	SPLITEVENTSCONSTRAINT_H

#include "global.h"
#include "Constraint.h"

#include "AbstractEventAndEventGroupConstraint.h"

namespace khe{ 
    
    class Event;
    class EventGroup;
    
class SplitEventsConstraint :
        public AbstractEventAndEventGroupConstraint<KHE_SPLIT_EVENTS_CONSTRAINT, SplitEventsConstraint>
{
public:
    using KheType           = KHE_SPLIT_EVENTS_CONSTRAINT;
    const static Tag tag    = SplitEvents;
    
    SplitEventsConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func,
            int minDuration, int maxDuration, int minAmount, int maxAmount);
    SplitEventsConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight,
            int minDuration, int maxDuration, int minAmount, int maxAmount);
    SplitEventsConstraint(KheType constr);
    virtual ~SplitEventsConstraint();
    
    int getMinDuration() const;
    int getMaxDuration() const;
    int getMinAmount() const;
    int getMaxAmount() const;
   
   
    
    operator KheType() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromSplitEventsConstraint(constr);
    }
    
    bool operator< (const SplitEventsConstraint &c2) const{
        return getId() < c2.getId();
    }
    
public:
    KheType constr;
    
    constexpr static const addEventFunc        *addEvent        = &KheSplitEventsConstraintAddEvent;
    constexpr static const addEventGroupFunc   *addEventGroup   = &KheSplitEventsConstraintAddEventGroup;
    
    constexpr static const EventCountFunc      *eventCount      = &KheSplitEventsConstraintEventCount;
    constexpr static const getEventFunc        *getEvent        = &KheSplitEventsConstraintEvent;
    
    constexpr static const EventGroupCountFunc *eventGroupCount = &KheSplitEventsConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc   *getEventGroup   = &KheSplitEventsConstraintEventGroup;

};

}

#endif	/* SPLITEVENTSCONSTRAINT_H */

