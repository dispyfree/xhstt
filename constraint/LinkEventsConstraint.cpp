/* 
 * File:   LinkEventsConstraint.cpp
 * 
 */

#include "LinkEventsConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"

#include "EventGroup.h"

using namespace khe;

LinkEventsConstraint::LinkEventsConstraint(Instance inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf){
    if(!KheLinkEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, &constr))
        throw ObjectCreation("Unable to create LinkEventsConstraint");
}
