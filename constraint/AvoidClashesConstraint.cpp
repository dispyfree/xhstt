/* 
 * File:   AvoidClashesConstraint.cpp
 * 
 */

#include "AvoidClashesConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
using namespace khe;

using acc = AvoidClashesConstraint;
acc::AvoidClashesConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction cf){
    if(!KheAvoidClashesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, &constr))
        throw ObjectCreation("Unable to create AvoidClashesConstraint");
}

acc::AvoidClashesConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight):
AvoidClashesConstraint(inst, id, name, required, weight, CostFunction::getLinearFunction()){
}

