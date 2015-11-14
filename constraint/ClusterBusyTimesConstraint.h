/* 
 * File:   ClusterBusyTimesConstraint.h
 * 
 */

#ifndef CLUSTERBUSYTIMESCONSTRAINT_H
#define	CLUSTERBUSYTIMESCONSTRAINT_H

#include "global.h"
#include "AbstractTimeGroupConstraint.h"
#include "AbstractResourceConstraint.h"

namespace khe{
    
    class Instance;
    class CostFunction;
    
    using cbtct = KHE_CLUSTER_BUSY_TIMES_CONSTRAINT;
    
class ClusterBusyTimesConstraint :
    public AbstractResourceConstraint<cbtct, ClusterBusyTimesConstraint>,
    public AbstractTimeGroupConstraint<cbtct, ClusterBusyTimesConstraint>   
{
public:
    
    using KheType           = cbtct;
    const static Tag tag    = ClusterBusyTimes;
    
    ClusterBusyTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max);
    ClusterBusyTimesConstraint(KheType raw) : Constraint(raw), constr(raw){Util::rnn(raw);}
    virtual ~ClusterBusyTimesConstraint(){}
    
    int getMinimum() const;
    int getMaximum() const;
    
    operator KheType() const{
        return constr;
    }
    
    bool operator< (const ClusterBusyTimesConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
public:
    
    constexpr static const addResourceFunc              *addResource        = &KheClusterBusyTimesConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KheClusterBusyTimesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KheClusterBusyTimesConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KheClusterBusyTimesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KheClusterBusyTimesConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KheClusterBusyTimesConstraintResourceGroup;
    
    
    constexpr static const addTimeGroupFuncT         *addTimeGroupFunc   = &KheClusterBusyTimesConstraintAddTimeGroup;
    
    constexpr static const TimeGroupCountFuncT       *timeGroupCountFunc = &KheClusterBusyTimesConstraintTimeGroupCount; 
    constexpr static const getTimeGroupFuncT         *getTimeGroupFunc   = &KheClusterBusyTimesConstraintTimeGroup;
};

}

#endif	/* CLUSTERBUSYTIMESCONSTRAINT_H */

