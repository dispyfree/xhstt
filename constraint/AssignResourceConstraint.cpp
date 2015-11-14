/* 
 * File:   AssignResourceConstraint.cpp
 * 
 */

#include "AssignResourceConstraint.h"
#include "Instance.h"
#include "CostFunction.h"
#include "Event.h"
#include "EventResource.h"
#include "EventGroup.h"
#include "ObjectCreation.h"
using namespace khe;

using arc = AssignResourceConstraint;

arc::AssignResourceConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role){
    if(!KheAssignResourceConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, func, Util::sTc(role), &constr))
        throw ObjectCreation("Unable to create AssignResourceConstraint");
}

arc::AssignResourceConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role){
    if(!KheAssignResourceConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), Util::sTc(role), &constr))
        throw ObjectCreation("Unable to create AssignResourceConstraint");
}

arc::AssignResourceConstraint(KHE_ASSIGN_RESOURCE_CONSTRAINT constr) : Constraint(constr){
    Util::rnn(constr);
    this->constr = constr;
}

arc::~AssignResourceConstraint(){}

std::string arc::getRole() const{
    return KheAssignResourceConstraintRole(constr);
}

