/* 
 * File:   PreferTimesConstraint.cpp
 * 
 */

#include "PreferTimesConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
#include "TimeGroup.h"
using namespace khe;

using ptc = PreferTimesConstraint;
ptc::PreferTimesConstraint::PreferTimesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, int duration) {
    if(!KhePreferTimesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required, weight,
            func, duration, &constr))
        throw ObjectCreation("Unable to create PreferTimesConstraint");
}

ptc::PreferTimesConstraint(KheType raw) : Constraint(raw){
    Util::rnn(raw);
    constr = raw;
}

ptc::~PreferTimesConstraint() {
}

int ptc::getDuration() const{
    return KhePreferTimesConstraintDuration(constr);
}

TimeGroup ptc::getDomain() const{
    return KhePreferTimesConstraintDomain(constr);
}

