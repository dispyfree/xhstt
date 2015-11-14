/* 
 * File:   AvoidSplitAssignment.h
 * 
 */

#ifndef AVOIDSPLITASSIGNMENTCONSTRAINT_H
#define	AVOIDSPLITASSIGNMENTCONSTRAINT_H

#include "AbstractEventGroupConstraint.h"
#include "AbstractEventResourceConstraint.h"
#include <string>

namespace khe{
    
    using asac = KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT;
    
    class Instance;

class AvoidSplitAssignmentsConstraint :
    public AbstractEventGroupConstraint<asac, AvoidSplitAssignmentsConstraint, true>,
    public AbstractEventResourceConstraint<asac, AvoidSplitAssignmentsConstraint, true>    
{
public:
    
    using KheType           = asac;
    const static Tag tag    = AvoidSplitAssignments;
    
    AvoidSplitAssignmentsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role);
    AvoidSplitAssignmentsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role);
    AvoidSplitAssignmentsConstraint(KheType raw);
    virtual ~AvoidSplitAssignmentsConstraint(){}
    
    std::string getRole() const;

    operator KheType() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromAvoidSplitAssignmentsConstraint(constr);
    }
    
    bool operator< (const AvoidSplitAssignmentsConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    
    constexpr static const addEventResourceFunc    *addEventResource  = &KheAvoidSplitAssignmentsConstraintAddEventResource;
    constexpr static const EventResourceCountFunc  *eventResourceCount= &KheAvoidSplitAssignmentsConstraintEventResourceCount;
    constexpr static const getEventResourceFunc    *getEventResource   = &KheAvoidSplitAssignmentsConstraintEventResource;

    
    constexpr static const addEventGroupFunc   *addEventGroup   = &KheAvoidSplitAssignmentsConstraintAddEventGroup;
    constexpr static const EventGroupCountFunc *eventGroupCount = &KheAvoidSplitAssignmentsConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc   *getEventGroup   = &KheAvoidSplitAssignmentsConstraintEventGroup;
};
}

#endif	/* AVOIDSPLITASSIGNMENTCONSTRAINT_H */

