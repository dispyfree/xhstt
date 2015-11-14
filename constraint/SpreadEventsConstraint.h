/* 
 * File:   SpreadEventsConstraint.h
 * 
 */

#ifndef SPREADEVENTSCONSTRAINT_H
#define	SPREADEVENTSCONSTRAINT_H

#include "global.h"
#include "AbstractEventGroupConstraint.h"

#include "EventGroup.h"

namespace khe{
    
    
    class Instance;
    class CostFunction;
    class TimeSpread;
    

class SpreadEventsConstraint :
public AbstractEventGroupConstraint<KHE_SPREAD_EVENTS_CONSTRAINT, SpreadEventsConstraint, false>
{
public:
    static const Tag tag = Constraint::Tag::SpreadEvents;
    using KheType = KHE_SPREAD_EVENTS_CONSTRAINT;
    
    SpreadEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, const TimeSpread &ts);
    SpreadEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const TimeSpread &ts);
    SpreadEventsConstraint(KheType raw) : Constraint(raw), constr(raw){}
    virtual ~SpreadEventsConstraint(){}
    
    TimeSpread getTimeSpread() const;
    

    operator KheType() const{
        return constr;
    }
    
    bool operator<(const SpreadEventsConstraint &constr2) const{
        return getId() < constr2.getId();
    }
    
protected:
    KheType constr;
    
public:
    constexpr static const addEventGroupFunc   *addEventGroup   = &KheSpreadEventsConstraintAddEventGroup;
    
    constexpr static const EventGroupCountFunc *eventGroupCount = &KheSpreadEventsConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc   *getEventGroup   = &KheSpreadEventsConstraintEventGroup;

};

}

#endif	/* SPREADEVENTSCONSTRAINT_H */

