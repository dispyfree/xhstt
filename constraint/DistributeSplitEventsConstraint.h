/* 
 * File:   DistributeSplitEventsConstraint.h
 * 
 */

#ifndef DISTRIBUTESPLITEVENTSCONSTRAINT_H
#define	DISTRIBUTESPLITEVENTSCONSTRAINT_H


#include "AbstractEventAndEventGroupConstraint.h"

namespace khe {
    
    class Instance;
    class CostFunction;
    
    using dsec = KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT;
    
class DistributeSplitEventsConstraint : 
    public AbstractEventAndEventGroupConstraint<dsec, DistributeSplitEventsConstraint>        
{
public:
    friend class AbstractEventConstraint<dsec, DistributeSplitEventsConstraint>;
    friend class AbstractEventGroupConstraint<dsec, DistributeSplitEventsConstraint>;
    
    using KheType           = dsec;
    const static Tag tag    = DistributeSplitEvents;
    
    DistributeSplitEventsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, int duration, int min, int max);
    
    DistributeSplitEventsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, int duration, int min, int max);
    DistributeSplitEventsConstraint(KheType raw);
    virtual ~DistributeSplitEventsConstraint();
    
    int getDuration() const;
    int getMinimum() const;
    int getMaximum() const;
    
    operator KheType() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromDistributeSplitEventsConstraint(constr);
    }
    
    bool operator< (const DistributeSplitEventsConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
   KheType constr;
    
    constexpr static const addEventFunc        *addEvent        = &KheDistributeSplitEventsConstraintAddEvent;
    constexpr static const addEventGroupFunc   *addEventGroup   = &KheDistributeSplitEventsConstraintAddEventGroup;
    
    constexpr static const EventCountFunc      *eventCount      = &KheDistributeSplitEventsConstraintEventCount;
    constexpr static const getEventFunc        *getEvent        = &KheDistributeSplitEventsConstraintEvent;
    
    constexpr static const EventGroupCountFunc *eventGroupCount = &KheDistributeSplitEventsConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc   *getEventGroup   = &KheDistributeSplitEventsConstraintEventGroup;

};

}

#endif	/* DISTRIBUTESPLITEVENTSCONSTRAINT_H */

