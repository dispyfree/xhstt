/* 
 * File:   LimitBusyTimesConstraint.cpp
 * 
 */

#include "LimitBusyTimesConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
#include "TimeGroup.h"


using namespace khe;
using lbtc = LimitBusyTimesConstraint;

lbtc::LimitBusyTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max){
    if(!KheLimitBusyTimesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, min, max, &constr))
        throw ObjectCreation("Unable to create LimitBusyTimesConstraint");
}

int lbtc::getMinimum() const{
    return KheLimitBusyTimesConstraintMinimum(constr);
}

int lbtc::getMaximum() const{
    return KheLimitBusyTimesConstraintMaximum(constr);
}

TimeGroup lbtc::getDomain() const{
    return KheLimitBusyTimesConstraintDomain(constr);
}


