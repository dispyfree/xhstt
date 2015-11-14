/* 
 * File:   LimitBusyTimesConstraint.h
 * 
 */

#ifndef LIMITBUSYTIMESCONSTRAINT_H
#define	LIMITBUSYTIMESCONSTRAINT_H

#include "global.h"
#include "AbstractTimeGroupConstraint.h"
#include "AbstractResourceConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    class TimeGroup;
    
    using lbtct = KHE_LIMIT_BUSY_TIMES_CONSTRAINT;
    
class LimitBusyTimesConstraint :
    public AbstractResourceConstraint<lbtct, LimitBusyTimesConstraint>,
    public AbstractTimeGroupConstraint<lbtct, LimitBusyTimesConstraint> 
{
public:
    
    using KheType           = lbtct;
    const static Tag tag    = LimitBusyTimes;
    
    LimitBusyTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max);
    LimitBusyTimesConstraint(KheType raw) : Constraint(raw), constr(raw){Util::rnn(raw);}
    virtual ~LimitBusyTimesConstraint(){}
    
    int getMinimum() const;
    int getMaximum() const;
    
    TimeGroup getDomain() const;
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const LimitBusyTimesConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    
    constexpr static const addResourceFunc              *addResource        = &KheLimitBusyTimesConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KheLimitBusyTimesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KheLimitBusyTimesConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KheLimitBusyTimesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KheLimitBusyTimesConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KheLimitBusyTimesConstraintResourceGroup;
    
    
    constexpr static const addTimeGroupFuncT         *addTimeGroupFunc   = &KheLimitBusyTimesConstraintAddTimeGroup;
    
    constexpr static const TimeGroupCountFuncT       *timeGroupCountFunc = &KheLimitBusyTimesConstraintTimeGroupCount; 
    constexpr static const getTimeGroupFuncT         *getTimeGroupFunc   = &KheLimitBusyTimesConstraintTimeGroup;
};

}

#endif	/* LIMITBUSYTIMESCONSTRAINT_H */

