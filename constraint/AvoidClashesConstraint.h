/* 
 * File:   AvoidClashesConstraint.h
 * 
 */

#ifndef AVOIDCLASHESCONSTRAINT_H
#define	AVOIDCLASHESCONSTRAINT_H

#include "AbstractResourceConstraint.h"
#include "Util.h"
#include <string>

namespace khe{

    class CostFunction;
    class Instance;
    
class AvoidClashesConstraint :
public AbstractResourceConstraint<KHE_AVOID_CLASHES_CONSTRAINT, AvoidClashesConstraint>
{
public:
    
    using KheType           = KHE_AVOID_CLASHES_CONSTRAINT;
    const static Tag tag    = AvoidClashes;
    
    AvoidClashesConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction cf);
    AvoidClashesConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight);
    AvoidClashesConstraint(KheType raw) : Constraint(raw), constr(raw) {Util::rnn(raw);}
    virtual ~AvoidClashesConstraint(){}
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const AvoidClashesConstraint &c2) const{
        return getId() < c2.getId();
    }
        
protected:
    KheType constr;
    
public:
    constexpr static const addResourceFunc       *addResource        = &KheAvoidClashesConstraintAddResource;
    constexpr static const addResourceGroupFunc  *addResourceGroup   = &KheAvoidClashesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc     *resourceCount      = &KheAvoidClashesConstraintResourceCount;
    constexpr static const getResourceFunc       *getResource        = &KheAvoidClashesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc  *resourceGroupCount = &KheAvoidClashesConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc    *getResourceGroup   = &KheAvoidClashesConstraintResourceGroup;
};

}

#endif	/* AVOIDCLASHESCONSTRAINT_H */

