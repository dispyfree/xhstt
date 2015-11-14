/* 
 * File:   ClusterBusyTimesConstraint.cpp
 * 
 */

#include "ClusterBusyTimesConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"

using namespace khe;
using cbtc = ClusterBusyTimesConstraint;

cbtc::ClusterBusyTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max){
    if(!KheClusterBusyTimesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, min, max, &constr))
        throw ObjectCreation("Unable to create ClusterBusyTimesConstraint");
}

    
int cbtc::getMinimum() const{
    return KheClusterBusyTimesConstraintMinimum(constr);
}

int cbtc::getMaximum() const{
    return KheClusterBusyTimesConstraintMaximum(constr);
}

