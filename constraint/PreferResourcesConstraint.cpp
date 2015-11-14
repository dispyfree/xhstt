/* 
 * File:   PreferResourcesConstraint.cpp
 * 
 */

#include "PreferResourcesConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
#include "ResourceGroup.h"
#include "EventResource.h"

using namespace khe;

using prc = PreferResourcesConstraint;

PreferResourcesConstraint::PreferResourcesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role) {
    if(!KhePreferResourcesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, func, Util::sTc(role), &constr))
        throw ObjectCreation("Unable to create PreferResourcesConstraint");
}

PreferResourcesConstraint::PreferResourcesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role) {
    if(!KhePreferResourcesConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, CostFunction::getLinearFunction(), Util::sTc(role), &constr))
        throw ObjectCreation("Unable to create PreferResourcesConstraint");
}

prc::PreferResourcesConstraint(KheType raw) : Constraint(raw){
    Util::rnn(raw);
    constr = raw;
}

PreferResourcesConstraint::~PreferResourcesConstraint() {
}

std::string prc::getRole() const{
    return KhePreferResourcesConstraintRole(constr);
}

ResourceGroup prc::getDomain() const{
    return KhePreferResourcesConstraintDomain(constr);
}

std::vector<PreferResourcesConstraint> PreferResourcesConstraint::getByRole(
    const std::string &role, const std::vector<PreferResourcesConstraint> &constraints){
    
    std::vector<PreferResourcesConstraint> res;
    for(auto constraint : constraints){
        if(constraint.getRole() == role)
            res.push_back(constraint);
    }
    return res;
}

