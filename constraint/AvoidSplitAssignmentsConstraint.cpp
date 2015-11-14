/* 
 * File:   AvoidSplitAssignment.cpp
 * 
 */

#include "AvoidSplitAssignmentsConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
#include "Util.h"

#include "EventGroup.h"

using namespace khe;
using asa = AvoidSplitAssignmentsConstraint;

 asa::AvoidSplitAssignmentsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role){
     if(!KheAvoidSplitAssignmentsConstraintMake(inst, Util::sTc(id), Util::sTc(name), 
             required, weight, func, Util::sTc(role), &constr))
         throw ObjectCreation("Unable to create AvoidSplitAssignmentConstraint");
 }
 
  asa::AvoidSplitAssignmentsConstraint(Instance &inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role){
     if(!KheAvoidSplitAssignmentsConstraintMake(inst, Util::sTc(id), Util::sTc(name), 
             required, weight,  CostFunction::getLinearFunction(), Util::sTc(role), &constr))
         throw ObjectCreation("Unable to create AvoidSplitAssignmentConstraint");
 }
  
 asa::AvoidSplitAssignmentsConstraint(KheType raw): Constraint(raw), constr(raw){
     Util::rnn(raw);
 }
 
 std::string asa::getRole() const{
     return KheAvoidSplitAssignmentsConstraintRole(constr);
 }
 

