/* 
 * File:   SplitEventsConstraint.cpp
 * 
 */

#include "SplitEventsConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
#include "Event.h"
#include "EventGroup.h"

using namespace khe;
using sec = SplitEventsConstraint;

sec::SplitEventsConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func,
            int minDuration, int maxDuration, int minAmount, int maxAmount){
    if(!KheSplitEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, func, minDuration, maxDuration, minAmount, maxAmount, &constr))
        throw ObjectCreation("Unable to create SplitEventsConstraint");
}

sec::SplitEventsConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight,
            int minDuration, int maxDuration, int minAmount, int maxAmount):
    SplitEventsConstraint(inst, id, name, required, weight, CostFunction::getLinearFunction(),
        minDuration, maxDuration, minAmount, maxAmount){
}

sec::SplitEventsConstraint(KHE_SPLIT_EVENTS_CONSTRAINT constr) : Constraint(constr){
    Util::rnn(constr);
    this->constr = constr;
}

sec::~SplitEventsConstraint(){}
    
int sec::getMinDuration() const{
    return KheSplitEventsConstraintMinDuration(constr);
}

int sec::getMaxDuration() const{
    return KheSplitEventsConstraintMaxDuration(constr);
}

int sec::getMinAmount() const{
    return KheSplitEventsConstraintMinAmount(constr);
}

int sec::getMaxAmount() const{
    return KheSplitEventsConstraintMaxAmount(constr);
}


