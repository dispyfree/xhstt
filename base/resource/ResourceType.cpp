/* 
 * File:   ResourceType.cpp
 * 
 */

#include "ResourceType.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "ResourceGroup.h"
#include "Resource.h"
using namespace khe;


ResourceType::ResourceType(Instance inst, const std::string &id, const std::string &name, bool hasPartitions){
 if(!KheResourceTypeMake(inst, Util::sTc(id), Util::sTc(name), hasPartitions, &type))
     throw ObjectCreation("Unable to create object of type ResourceType");
}

ResourceType::ResourceType(KHE_RESOURCE_TYPE type){
    Util::rnn(type);
    this->type = type;
}

ResourceType::~ResourceType() {
}

void ResourceType::setBack(void *back){
    KheResourceTypeSetBack(type, back);
}

Instance ResourceType::getInstance() const{
    return KheResourceTypeInstance(type);
}

int ResourceType::getIndex() const{
    return KheResourceTypeIndex(type);
}

std::string ResourceType::getId() const{
    return KheResourceTypeId(type);
}

std::string ResourceType::getName() const{
    return KheResourceTypeName(type);
}

bool ResourceType::hasPartitions() const{
    return KheResourceTypeHasPartitions(type);
}
    
IR<ResourceGroup> ResourceType::getGroups() const{
    return createIter<ResourceGroup>(*this);
}

ResourceGroup ResourceType::getGroup(const std::string &id) const{
    return Util::retrieve<ResourceGroup>(type, &KheResourceTypeRetrieveResourceGroup, id);
}

    
IR<ResourceGroup> ResourceType::getPartitions() const{
    /*return Util::toArray<ResourceGroup>(&KheResourceTypePartition, type, 
            KheResourceTypePartitionCount(type));*/
    
    auto iter = KheObjIter<ResourceGroup>(*this, 
            &KheResourceTypePartitionCount, 
            &KheResourceTypePartition);
    return IR<ResourceGroup>(iter, iter.getEnd());
}

ResourceGroup ResourceType::getFullResourceGroup() const{
    return KheResourceTypeFullResourceGroup(type);
}

ResourceGroup ResourceType::getEmptyResourceGroup() const{
    return KheResourceTypeEmptyResourceGroup(type);
}
    
IR<Resource> ResourceType::getResources() const{
    return createIter<Resource>(*this);
}

std::vector<Resource> ResourceType::getResourcesWithDummy() const{
    auto tmp = Util::toArray<Resource>(&KheResourceTypeResource, type, 
        KheResourceTypeResourceCount(type));
    std::vector<Resource> modRes(tmp.begin(), tmp.end());
    modRes.push_back(Resource::getDummy());

    return std::move(modRes);
}
    
bool ResourceType::demandsAllArePreassigned() const{
    return KheResourceTypeDemandIsAllPreassigned(type);
}

bool ResourceType::demandsAvoidSplitAssignmentsCount() const{
    return KheResourceTypeAvoidSplitAssignmentsCount(type);
}

