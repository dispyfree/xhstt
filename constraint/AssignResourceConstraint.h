/* 
 * File:   AssignResourceConstraint.h
 * 
 */

#ifndef ASSIGNRESOURCECONSTRAINT_H
#define	ASSIGNRESOURCECONSTRAINT_H

#include "AbstractEventAndEventGroupConstraint.h"
#include "AbstractEventResourceConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    class Event;
    class EventGroup;
    class EventResource; 
    
    using arcType = KHE_ASSIGN_RESOURCE_CONSTRAINT;
    
class AssignResourceConstraint : 
        virtual public AbstractEventAndEventGroupConstraint<arcType, AssignResourceConstraint, false>,
        virtual public AbstractEventResourceConstraint<arcType, AssignResourceConstraint>
{
public:
    using KheType   = KHE_ASSIGN_RESOURCE_CONSTRAINT;
    const static Tag tag  = AssignResource;
    
    AssignResourceConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role);
    AssignResourceConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role);
    
    AssignResourceConstraint(KheType constr);
    virtual ~AssignResourceConstraint();
    
    std::string getRole() const;
    
    
    operator KHE_ASSIGN_RESOURCE_CONSTRAINT() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromAssignResourceConstraint(constr);
    }
    
    bool operator<(const AssignResourceConstraint &c2)const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    constexpr static const addEventFunc              *addEvent        = &KheAssignResourceConstraintAddEvent;
    
    constexpr static const EventCountFunc            *eventCount      = &KheAssignResourceConstraintEventCount;
    constexpr static const getEventFunc              *getEvent        = &KheAssignResourceConstraintEvent;
    
    constexpr static const addEventGroupFunc         *addEventGroup   = &KheAssignResourceConstraintAddEventGroup;
    
    constexpr static const EventGroupCountFunc       *eventGroupCount = &KheAssignResourceConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc         *getEventGroup   = &KheAssignResourceConstraintEventGroup;
    
    
    constexpr static const addEventResourceFunc       *addEventResource        = &KheAssignResourceConstraintAddEventResource;
    
    constexpr static const EventResourceCountFunc     *eventResourceCount      = &KheAssignResourceConstraintEventResourceCount;
    constexpr static const getEventResourceFunc        *getEventResource        = &KheAssignResourceConstraintEventResource;

};

}

#endif	/* ASSIGNRESOURCECONSTRAINT_H */

