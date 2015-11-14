/* 
 * File:   AssignTimeConstraint.cpp
 * 
 */

#include "AssignTimeConstraint.h"
#include "Event.h"
#include "EventGroup.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ObjectCreation.h"

using namespace khe;

using atc = AssignTimeConstraint;

atc::AssignTimeConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func){
    if(!KheAssignTimeConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, func, &constr))
        throw ObjectCreation("Unable to create AssignTime Constraint");
}

atc::AssignTimeConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight){
    if(!KheAssignTimeConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), &constr))
        throw ObjectCreation("Unable to create AssignTime Constraint");
}

atc::AssignTimeConstraint(KHE_ASSIGN_TIME_CONSTRAINT constr) : Constraint(constr){
    Util::rnn(constr);
    this->constr = constr;
}

atc::~AssignTimeConstraint(){}

