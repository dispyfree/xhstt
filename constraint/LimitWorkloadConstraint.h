/* 
 * File:   LimitWorkloadConstraint.h
 * 
 */

#ifndef LIMITWORKLOADCONSTRAINT_H
#define	LIMITWORKLOADCONSTRAINT_H

#include "AbstractResourceConstraint.h"
#include <string>

namespace khe{
    
    class Instance;
    class CostFunction;
    class TimeGroup;
    
    using lwct = KHE_LIMIT_WORKLOAD_CONSTRAINT;
    
class LimitWorkloadConstraint :
    public AbstractResourceConstraint<lwct, LimitWorkloadConstraint>
{
public:
    
    using KheType           = lwct;
    const static Tag tag    = LimitWorkload;
    
    LimitWorkloadConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max);
    LimitWorkloadConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, int min, int max);
    LimitWorkloadConstraint(KheType raw) : Constraint(raw), constr(raw){Util::rnn(raw);}
    virtual ~LimitWorkloadConstraint(){}
    
    int getMinimum() const;
    int getMaximum() const;
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const LimitWorkloadConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    
    constexpr static const addResourceFunc              *addResource        = &KheLimitWorkloadConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KheLimitWorkloadConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KheLimitWorkloadConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KheLimitWorkloadConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KheLimitWorkloadConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KheLimitWorkloadConstraintResourceGroup;
    

};

}
#endif	/* LIMITWORKLOADCONSTRAINT_H */

