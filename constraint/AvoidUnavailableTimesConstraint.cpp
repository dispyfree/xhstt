/* 
 * File:   AvoidUnavailableTimesConstraint.cpp
 * 
 */

#include "AvoidUnavailableTimesConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
#include "TimeGroup.h"

using namespace khe;

using autc = AvoidUnavailableTimesConstraint;

autc::AvoidUnavailableTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf) {
    if(!KheAvoidUnavailableTimesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, &constr))
        throw ObjectCreation("Unable to create AvoidUnavailableTimesConstraint");
}

TimeGroup autc::getUnavailableTimes() const{
    return KheAvoidUnavailableTimesConstraintUnavailableTimes(constr);
}

TimeGroup autc::getAvailableTimes() const{
    return KheAvoidUnavailableTimesConstraintAvailableTimes(constr);
}


