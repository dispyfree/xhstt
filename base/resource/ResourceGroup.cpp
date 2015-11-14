/* 
 * File:   ResourceGroup.cpp
 * 
 */

#include "ResourceGroup.h"
#include "ResourceType.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "Resource.h"
using namespace khe;

ResourceGroup::ResourceGroup(ResourceType t, const std::string &id, const std::string &name, bool isPartition){
    if(!KheResourceGroupMake(t, Util::sTc(id), Util::sTc(id), isPartition, &grp))
        throw ObjectCreation("Unable to create object of type ResourceGroup");
}

ResourceGroup::ResourceGroup(KHE_RESOURCE_GROUP t){
    Util::rnn(t);
    grp = t;
}

ResourceGroup::~ResourceGroup() {
}

void ResourceGroup::setBack(void *back){
    KheResourceGroupSetBack(grp, back);
}

 ResourceType    ResourceGroup::getType() const{
     return KheResourceGroupResourceType(grp);
 }
 
Instance        ResourceGroup::getInstance() const{
    return KheResourceGroupInstance(grp);
}

std::string     ResourceGroup::getId() const{
    return KheResourceGroupId(grp);
}

std::string     ResourceGroup::getName() const{
    return KheResourceGroupName(grp);
}
    
bool ResourceGroup::isPartition() const{
    return KheResourceGroupIsPartition(grp);
}

void ResourceGroup::add(Resource r){
    KheResourceGroupAddResource(grp, r);
}

ResourceGroup &ResourceGroup::operator+=(const Resource &r){
    add(r);
}

void ResourceGroup::sub(Resource r){
    KheResourceGroupSubResource(grp, r);
}

ResourceGroup &ResourceGroup::operator-=(const Resource &r){
    sub(r);
}

void ResourceGroup::doUnion(ResourceGroup b){
    KheResourceGroupUnion(grp, b);
}

void ResourceGroup::intersect(ResourceGroup b){
    KheResourceGroupIntersect(grp, b);
}

void ResourceGroup::difference(ResourceGroup b){
    KheResourceGroupDifference(grp, b);
}
    
IR<Resource> ResourceGroup::getResources() const{
    return createIter<Resource>(*this);
}

bool ResourceGroup::contains(const Resource &r) const{
    KheResourceGroupContains(grp, r);
}

bool ResourceGroup::equals(const ResourceGroup &r) const{
    KheResourceGroupEqual(grp, r);
}

bool ResourceGroup::isSubSet(const ResourceGroup &b) const{
    KheResourceGroupSubset(grp, b);
}

bool ResourceGroup::operator<=(const ResourceGroup &b) const{
    return isSubSet(b);
}

bool ResourceGroup::isDisjoint(const ResourceGroup &b) const{
    return KheResourceGroupDisjoint(grp, b);
}
    
ResourceGroup ResourceGroup::getPartition() const{
    return KheResourceGroupPartition(grp);
}

