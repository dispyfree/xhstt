/* 
 * File:   LimitWorkloadConstraint.cpp
 * 
 */

#include "LimitWorkloadConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
#include "Util.h"

using namespace khe;
using lwc = LimitWorkloadConstraint;

lwc::LimitWorkloadConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max){
    if(!KheLimitWorkloadConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, min, max, &constr))
        throw ObjectCreation("Unable to create LimitWorkloadConstraint");
    
}

lwc::LimitWorkloadConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, int min, int max){
    if(!KheLimitWorkloadConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), min, max, &constr))
        throw ObjectCreation("Unable to create LimitWorkloadConstraint");
    
}

int lwc::getMinimum() const{
    return KheLimitWorkloadConstraintMinimum(constr);
}

int lwc::getMaximum() const{
    return KheLimitWorkloadConstraintMaximum(constr);
}
