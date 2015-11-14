/* 
 * File:   DistributeSplitEventsConstraint.cpp
 * 
 */

#include "DistributeSplitEventsConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
#include "Util.h"

#include "Event.h"

using namespace khe;
using dse = DistributeSplitEventsConstraint;

dse::DistributeSplitEventsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, int duration, int min, int max){
    if(!KheDistributeSplitEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, func, duration, min, max, &constr))
        throw ObjectCreation("Unable to create DistributesplitEventsConstraint");
}

dse::DistributeSplitEventsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, int duration, int min, int max){
    if(!KheDistributeSplitEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), duration, min, max, &constr))
        throw ObjectCreation("Unable to create DistributesplitEventsConstraint");
}

dse::DistributeSplitEventsConstraint(KheType raw) : Constraint(raw){
    Util::rnn(raw);
    constr = raw;
}

dse::~DistributeSplitEventsConstraint(){}

int dse::getDuration() const{
    return KheDistributeSplitEventsConstraintDuration(constr);
}

int dse::getMinimum() const{
    return KheDistributeSplitEventsConstraintMinimum(constr);
}

int dse::getMaximum() const{
    return KheDistributeSplitEventsConstraintMaximum(constr);
}

