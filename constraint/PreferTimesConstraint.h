/* 
 * File:   PreferTimesConstraint.h
 * 
 */

#ifndef PREFERTIMESCONSTRAINT_H
#define	PREFERTIMESCONSTRAINT_H

#include "global.h"
#include "AbstractEventAndEventGroupConstraint.h"
#include "AbstractTimeAndTimeGroupConstraint.h"

namespace khe{
    
    using ptct = KHE_PREFER_TIMES_CONSTRAINT;

class Instance;
class CostFunction;
    
class PreferTimesConstraint :
        public AbstractEventAndEventGroupConstraint<ptct, PreferTimesConstraint>,
        public AbstractTimeAndTimeGroupConstraint<ptct, PreferTimesConstraint>
{
public:
    
    using KheType           = ptct;
    const static Tag tag    = PreferTimes;
    
    PreferTimesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, int duration);
    PreferTimesConstraint(KheType raw);
     ~PreferTimesConstraint();
     
    /**
     * Used to denote optional durations
     */
    static const decltype(KHE_ANY_DURATION) any = KHE_ANY_DURATION;
    
     
     int getDuration() const;
     TimeGroup getDomain() const;
     
    bool operator< (const PreferTimesConstraint &c2) const{
        return getId() < c2.getId();
    }

protected:
    KheType constr;

public:
    
     constexpr static const addTimeFuncT              *addTimeFunc        = &KhePreferTimesConstraintAddTime;
     constexpr static const addTimeGroupFuncT         *addTimeGroupFunc   = &KhePreferTimesConstraintAddTimeGroup;
    
     constexpr static const TimeCountFuncT            *timeCountFunc      = &KhePreferTimesConstraintTimeCount;
     constexpr static const getTimeFuncT              *getTimeFunc        = &KhePreferTimesConstraintTime;
    
     constexpr static const TimeGroupCountFuncT       *timeGroupCountFunc = &KhePreferTimesConstraintTimeGroupCount; 
     constexpr static const getTimeGroupFuncT         *getTimeGroupFunc   = &KhePreferTimesConstraintTimeGroup;
    
     
     constexpr static const addEventFunc              *addEvent        = &KhePreferTimesConstraintAddEvent;
     constexpr static const addEventGroupFunc         *addEventGroup   = &KhePreferTimesConstraintAddEventGroup;
    
     constexpr static const EventCountFunc            *eventCount      = &KhePreferTimesConstraintEventCount;
     constexpr static const getEventFunc              *getEvent        = &KhePreferTimesConstraintEvent;
    
     constexpr static const EventGroupCountFunc       *eventGroupCount = &KhePreferTimesConstraintEventGroupCount; 
     constexpr static const getEventGroupFunc         *getEventGroup   = &KhePreferTimesConstraintEventGroup;
    

};

}

#endif	/* PREFERTIMESCONSTRAINT_H */

