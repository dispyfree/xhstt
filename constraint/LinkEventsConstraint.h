/* 
 * File:   LinkEventsConstraint.h
 * 
 */

#ifndef LINKEVENTSCONSTRAINT_H
#define	LINKEVENTSCONSTRAINT_H

#include "global.h"
#include "AbstractEventGroupConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    
class LinkEventsConstraint : 
public AbstractEventGroupConstraint<KHE_LINK_EVENTS_CONSTRAINT,
         LinkEventsConstraint>
{
    
public:
    
    using KheType           = KHE_LINK_EVENTS_CONSTRAINT;
    const static Tag tag    = LinkEvents;
    
    LinkEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf);
    LinkEventsConstraint(KheType raw) : Constraint(raw), constr(raw) {Util::rnn(raw);}
    virtual ~LinkEventsConstraint(){}
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const LinkEventsConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    constexpr static const addEventGroupFunc *addEventGroup   = &KheLinkEventsConstraintAddEventGroup;
    
    constexpr static const EventGroupCountFunc       *eventGroupCount = &KheLinkEventsConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc         *getEventGroup   = &KheLinkEventsConstraintEventGroup;
    

};

}

#endif	/* LINKEVENTSCONSTRAINT_H */

