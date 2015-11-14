/* 
 * File:   LimitIdleTimesConstraint.h
 * 
 */

#ifndef LIMITIDLETIMESCONSTRAINT_H
#define	LIMITIDLETIMESCONSTRAINT_H

#include "global.h"
#include "AbstractTimeGroupConstraint.h"
#include "AbstractResourceConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    
    using lit = KHE_LIMIT_IDLE_TIMES_CONSTRAINT;
class LimitIdleTimesConstraint :
    public AbstractResourceConstraint<lit, LimitIdleTimesConstraint>,
    public AbstractTimeGroupConstraint<lit, LimitIdleTimesConstraint> 
{
public:
    
    using KheType           = lit;
    const static Tag tag    = LimitIdleTimes;
    
    LimitIdleTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max);
    LimitIdleTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, int min, int max);
    LimitIdleTimesConstraint(KheType raw): Constraint(raw), constr(raw) {Util::rnn(raw);}
    virtual ~LimitIdleTimesConstraint(){}
    
    int getMinimum() const;
    int getMaximum() const;
    
    bool isTimeGroupDisjoint() const;
    bool TimeGroupCoversHoleCycle() const;
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const LimitIdleTimesConstraint &c2) const{
        return getId() < c2.getId();
    }
        
protected:
    KheType constr;
    
public:
    constexpr static const addResourceFunc              *addResource        = &KheLimitIdleTimesConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KheLimitIdleTimesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KheLimitIdleTimesConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KheLimitIdleTimesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KheLimitIdleTimesConstraintResourceGroupCount;
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KheLimitIdleTimesConstraintResourceGroup;
    
    
    constexpr static const addTimeGroupFuncT         *addTimeGroupFunc   = &KheLimitIdleTimesConstraintAddTimeGroup;
    
    constexpr static const TimeGroupCountFuncT       *timeGroupCountFunc = &KheLimitIdleTimesConstraintTimeGroupCount;
    constexpr static const getTimeGroupFuncT         *getTimeGroupFunc   = &KheLimitIdleTimesConstraintTimeGroup;
};

}

#endif	/* LIMITIDLETIMESCONSTRAINT_H */

