/* 
 * File:   SpreadEventsConstraint.cpp
 * 
 */

#include "SpreadEventsConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
#include "TimeSpread.h"
using namespace khe;

using sec = SpreadEventsConstraint;

sec::SpreadEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf, const TimeSpread &ts){
    if(!KheSpreadEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, ts, &constr))
        throw ObjectCreation("Unable to create SpreadEventsConstraint");
}

sec::SpreadEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const TimeSpread &ts){
    if(!KheSpreadEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), ts, &constr))
        throw ObjectCreation("Unable to create SpreadEventsConstraint");
}

TimeSpread sec::getTimeSpread() const{
    return KheSpreadEventsConstraintTimeSpread(constr);
}

