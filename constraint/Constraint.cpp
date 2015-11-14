/* 
 * File:   Constraint.cpp
 * 
 */

#include "Constraint.h"
#include "Cost.h"
#include "CostFunction.h"
#include "Instance.h"
#include "InvalidObjectConversion.h"

#include "AssignResourceConstraint.h"
#include "Ident.h"
#include <map>

#include <algorithm>

using namespace khe;

Constraint::Constraint() {
}

Constraint::Constraint(KHE_CONSTRAINT cons){
    Util::rnn(cons);
    constr = cons;
}

Constraint::Constraint(KHE_ASSIGN_RESOURCE_CONSTRAINT cons){
    constr = KheFromAssignResourceConstraint(cons);
}
Constraint::Constraint(KHE_ASSIGN_TIME_CONSTRAINT cons){
    constr = KheFromAssignTimeConstraint(cons);
}
Constraint::Constraint(KHE_SPLIT_EVENTS_CONSTRAINT cons){
    constr = KheFromSplitEventsConstraint(cons);
}
Constraint::Constraint(KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT cons){
    constr = KheFromDistributeSplitEventsConstraint(cons);
}
Constraint::Constraint(KHE_PREFER_RESOURCES_CONSTRAINT cons){
    constr = KheFromPreferResourcesConstraint(cons);
}
Constraint::Constraint(KHE_PREFER_TIMES_CONSTRAINT cons){
    constr = KheFromPreferTimesConstraint(cons);
}
Constraint::Constraint(KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT cons){
    constr = KheFromAvoidSplitAssignmentsConstraint(cons);
}                                                                  
Constraint::Constraint(KHE_SPREAD_EVENTS_CONSTRAINT cons){
    constr = KheFromSpreadEventsConstraint(cons);
}
Constraint::Constraint(KHE_LINK_EVENTS_CONSTRAINT cons){
    constr = KheFromLinkEventsConstraint(cons);
}
Constraint::Constraint(KHE_ORDER_EVENTS_CONSTRAINT cons){
    constr = KheFromOrderEventsConstraint(cons);
}
Constraint::Constraint(KHE_AVOID_CLASHES_CONSTRAINT cons){
    constr = KheFromAvoidClashesConstraint(cons);
}
Constraint::Constraint(KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT cons){
    constr = KheFromAvoidUnavailableTimesConstraint(cons);
}
Constraint::Constraint(KHE_LIMIT_IDLE_TIMES_CONSTRAINT cons){
    constr = KheFromLimitIdleTimesConstraint(cons);
}
Constraint::Constraint(KHE_CLUSTER_BUSY_TIMES_CONSTRAINT cons){
    constr = KheFromClusterBusyTimesConstraint(cons);
}
Constraint::Constraint(KHE_LIMIT_BUSY_TIMES_CONSTRAINT cons){
    constr = KheFromLimitBusyTimesConstraint(cons);
}
Constraint::Constraint(KHE_LIMIT_WORKLOAD_CONSTRAINT cons){
    constr = KheFromLimitWorkloadConstraint(cons);
}


Constraint::~Constraint() {
}

void Constraint::setBack(void *back){
    KheConstraintSetBack(constr, back);
}


Instance Constraint::getInstance() const{
    return KheConstraintInstance(constr);
}

std::string Constraint::getId() const{
    return KheConstraintId(constr);
}

std::string Constraint::getName() const{
    return KheConstraintName(constr);
}

bool Constraint::isRequired() const{
    return KheConstraintRequired(constr);
}

int Constraint::getWeight() const{
    return KheConstraintWeight(constr);
}

Cost Constraint::getCombinedWeight() const{
    return KheConstraintCombinedWeight(constr);
}

CostFunction Constraint::getCostFunction() const{
    return KheConstraintCostFunction(constr);
}

int Constraint::getIndex() const{
    return KheConstraintIndex(constr);
}

Constraint::Tag Constraint::getTag() const{
    return static_cast<Constraint::Tag>(KheConstraintTag(constr));
}

int Constraint::appliesToCount() const{
    KheConstraintAppliesToCount(constr);
}

std::string Constraint::showTag(Tag tag){
    return KheConstraintTagShow(static_cast<KHE_CONSTRAINT_TAG>(tag));
}

std::string Constraint::showTagSpaced(Tag tag){
    return KheConstraintTagShowSpaced(static_cast<KHE_CONSTRAINT_TAG>(tag));
}

Constraint::Tag Constraint::getTag(const std::string &str){
    return static_cast<Constraint::Tag>(KheStringToConstraintTag(Util::sTc(str)));
}

std::string Constraint::showCostFunction(const CostFunction &f) const{
    return KheCostFunctionShow(f);
}

void Constraint::requireTag(Tag tag) const{
    if(getTag() != tag){
        std::string err = "Tag mismatch for constraint conversion" ;
        err += showTag(getTag()) + " <-> " + showTag(tag);
        throw InvalidObjectConversion(err);
    }
}

Constraint::operator KHE_ASSIGN_RESOURCE_CONSTRAINT() const{
    requireTag(Tag::AssignResource);
    return KheToAssignResourceConstraint(constr);
}

Constraint::operator KHE_ASSIGN_TIME_CONSTRAINT() const{
    requireTag(Tag::AssignTime);
    return KheToAssignTimeConstraint(constr);
}

Constraint::operator KHE_SPLIT_EVENTS_CONSTRAINT() const{
    requireTag(Tag::SplitEvents);
    return KheToSplitEventsConstraint(constr);
}

Constraint::operator KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT() const{
    requireTag(Tag::DistributeSplitEvents);
    return KheToDistributeSplitEventsConstraint(constr);
}

Constraint::operator KHE_PREFER_RESOURCES_CONSTRAINT() const{
    requireTag(Tag::PreferResources);
    return KheToPreferResourcesConstraint(constr);
}

Constraint::operator KHE_PREFER_TIMES_CONSTRAINT() const{
    requireTag(Tag::PreferTimes);
    return KheToPreferTimesConstraint(constr);
}

Constraint::operator KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT() const{
    requireTag(Tag::AvoidSplitAssignments);
    return KheToAvoidSplitAssignmentsConstraint(constr);
}

Constraint::operator KHE_SPREAD_EVENTS_CONSTRAINT() const{
    requireTag(Tag::SpreadEvents);
    return KheToSpreadEventsConstraint(constr);
}

Constraint::operator KHE_LINK_EVENTS_CONSTRAINT() const{
    requireTag(Tag::LinkEvents);
    return KheToLinkEventsConstraint(constr);
}

Constraint::operator KHE_ORDER_EVENTS_CONSTRAINT() const{
    requireTag(Tag::OrderEvents);
    return KheToOrderEventsConstraint(constr);
}

Constraint::operator KHE_AVOID_CLASHES_CONSTRAINT() const{
    requireTag(Tag::AvoidClashes);
    return KheToAvoidClashesConstraint(constr);
}

Constraint::operator KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT() const{
    requireTag(Tag::AvoidUnavailableTimes);
    return KheToAvoidUnavailableTimesConstraint(constr);
}

Constraint::operator KHE_LIMIT_IDLE_TIMES_CONSTRAINT() const{
    requireTag(Tag::LimitIdleTimes);
    return KheToLimitIdleTimesConstraint(constr);
}

Constraint::operator KHE_CLUSTER_BUSY_TIMES_CONSTRAINT() const{
    requireTag(Tag::ClusterBusyTimes);
    return KheToClusterBusyTimesConstraint(constr);
}

Constraint::operator KHE_LIMIT_BUSY_TIMES_CONSTRAINT() const{
    requireTag(Tag::LimitBusyTimes);
    return KheToLimitBusyTimesConstraint(constr);
}

Constraint::operator KHE_LIMIT_WORKLOAD_CONSTRAINT() const{
    requireTag(Tag::LimitWorkload);
    return KheToLimitWorkloadConstraint(constr);
}


std::vector<Constraint> Constraint::getByTag(const Instance &inst, Tag tag){
    auto constraints = inst.getConstraints();
    std::vector<Constraint> constrs(constraints.begin(), constraints.end());
    return std::move(getByTag(constrs, tag));
}

std::vector<Constraint> Constraint::getByTag(const std::vector<Constraint> &constraints, Tag tag){
    std::vector<Constraint> res;
    
    for(auto constraint: constraints){
        if(constraint.getTag() == tag)
            res.push_back(constraint);
    }
    return std::move(res);
}

bool Constraint::operator<(const Constraint &constr) const{
    return getIndex() < constr.getIndex();
}

Constraint::operator int() const{
    return getIndex();
}

Constraint::operator std::string() const{
    return getId();
}

Constraint::operator KHE_CONSTRAINT() const{
    return constr;
}

