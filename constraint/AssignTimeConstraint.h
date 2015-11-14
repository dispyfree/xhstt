/* 
 * File:   AssignTimeConstraint.h
 * 
 */

#ifndef ASSIGNTIMECONSTRAINT_H
#define	ASSIGNTIMECONSTRAINT_H

#include "AbstractEventAndEventGroupConstraint.h"

namespace khe{

    class Instance;
    class CostFunction;
    class Event;
    class EventGroup;
    
class AssignTimeConstraint : 
    virtual public AbstractEventAndEventGroupConstraint<KHE_ASSIGN_TIME_CONSTRAINT, AssignTimeConstraint, false>
{
public:
    
    using KheType           = KHE_ASSIGN_TIME_CONSTRAINT;
    const static Tag tag    = AssignTime;
    
    AssignTimeConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func);
    AssignTimeConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight);
    AssignTimeConstraint(KHE_ASSIGN_TIME_CONSTRAINT constr);
    virtual ~AssignTimeConstraint();
    
    operator KHE_ASSIGN_TIME_CONSTRAINT() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromAssignTimeConstraint(constr);
    }
    
    bool operator<(const AssignTimeConstraint &c2)const{
        return getId() < c2.getId();
    }
    
public: 
    
    KHE_ASSIGN_TIME_CONSTRAINT constr;
    
    constexpr static const addEventFunc        *addEvent        = &KheAssignTimeConstraintAddEvent;
    constexpr static const addEventGroupFunc   *addEventGroup   = &KheAssignTimeConstraintAddEventGroup;
    
    constexpr static const EventCountFunc      *eventCount      = &KheAssignTimeConstraintEventCount;
    constexpr static const getEventFunc        *getEvent        = &KheAssignTimeConstraintEvent;
    
    constexpr static const EventGroupCountFunc *eventGroupCount = &KheAssignTimeConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc   *getEventGroup   = &KheAssignTimeConstraintEventGroup;

};

}

#endif	/* ASSIGNTIMECONSTRAINT_H */

