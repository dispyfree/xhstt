/* 
 * File:   LimitIdleTimesConstraint.cpp
 * 
 */

#include "LimitIdleTimesConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"
using namespace khe;
        
using litc = LimitIdleTimesConstraint;

litc::LimitIdleTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, int min, int max){
    if(!KheLimitIdleTimesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, min, max, &constr))
        throw ObjectCreation("Unable to create LimitIdleTimesConstraint");
}

litc::LimitIdleTimesConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, int min, int max):
    LimitIdleTimesConstraint(inst, id, name, required, weight, CostFunction::getLinearFunction(),
        min, max){
}

int litc::getMinimum() const{
    return KheLimitIdleTimesConstraintMinimum(constr);
}

int litc::getMaximum() const{
    return KheLimitIdleTimesConstraintMaximum(constr);
}

bool litc::isTimeGroupDisjoint() const{
    return KheLimitIdleTimesConstraintTimeGroupsDisjoint(constr);
}

bool litc::TimeGroupCoversHoleCycle() const{
    return KheLimitIdleTimesConstraintTimeGroupsCoverWholeCycle(constr);
}
