/* 
 * File:   AvoidUnavailableTimesConstraint.h
 * 
 */

#ifndef AVOIDUNAVAILABLETIMESCONSTRAINT_H
#define	AVOIDUNAVAILABLETIMESCONSTRAINT_H

#include "global.h"
#include "AbstractResourceConstraint.h"
#include "AbstractTimeAndTimeGroupConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    class TimeGroup;
    
    using autct =  KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT;
 
class AvoidUnavailableTimesConstraint :
    public AbstractResourceConstraint<autct, AvoidUnavailableTimesConstraint>,
    public AbstractTimeAndTimeGroupConstraint<autct, AvoidUnavailableTimesConstraint>  
{
public:
    
    using KheType           = autct;
    const static Tag tag    = AvoidUnavailableTimes;
    
    AvoidUnavailableTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf);
    AvoidUnavailableTimesConstraint(KheType raw): Constraint(raw), constr(raw){Util::rnn(raw);}
    virtual ~AvoidUnavailableTimesConstraint(){}
    
    TimeGroup getUnavailableTimes() const;
    TimeGroup getAvailableTimes() const;
    
    operator KheType() const{
      return constr;  
    };
    
    bool operator< (const AvoidUnavailableTimesConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    
    constexpr static const addResourceFunc              *addResource        = &KheAvoidUnavailableTimesConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KheAvoidUnavailableTimesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KheAvoidUnavailableTimesConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KheAvoidUnavailableTimesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KheAvoidUnavailableTimesConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KheAvoidUnavailableTimesConstraintResourceGroup;
    
    
    constexpr static const addTimeFuncT              *addTimeFunc        = &KheAvoidUnavailableTimesConstraintAddTime;
    constexpr static const addTimeGroupFuncT         *addTimeGroupFunc   = &KheAvoidUnavailableTimesConstraintAddTimeGroup;
    
    constexpr static const TimeCountFuncT            *timeCountFunc      = &KheAvoidUnavailableTimesConstraintTimeCount;
    constexpr static const getTimeFuncT              *getTimeFunc        = &KheAvoidUnavailableTimesConstraintTime;
    
    constexpr static const TimeGroupCountFuncT       *timeGroupCountFunc = &KheAvoidUnavailableTimesConstraintTimeGroupCount; 
    constexpr static const getTimeGroupFuncT         *getTimeGroupFunc   = &KheAvoidUnavailableTimesConstraintTimeGroup;

};

}

#endif	/* AVOIDUNAVAILABLETIMESCONSTRAINT_H */

