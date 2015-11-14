/* 
 * File:   Resource.cpp
 * 
 */

#include "Resource.h"
#include "EventResource.h"
#include "ObjectCreation.h"
#include "ResourceType.h"
#include "ResourceGroup.h"
#include "Instance.h"
#include "TimeGroup.h"
#include "Cost.h"
#include "Event.h"
#include "Ident.h"
#include <map>
using namespace khe;

int Resource::dummyId = -1;

Resource::Resource(ResourceType t, const std::string &id, const std::string name, ResourceGroup partition){
    if(!KheResourceMake(t, Util::sTc(id), Util::sTc(name), partition, &res))
        throw ObjectCreation("Unable to create object of type Resource");
}

Resource::Resource(ResourceType t, const std::string &id, const std::string name){
    if(!KheResourceMake(t, Util::sTc(id), Util::sTc(name), NULL, &res))
        throw ObjectCreation("Unable to create object of type Resource");
}

Resource::Resource(KHE_RESOURCE res){
    Util::rnn(res);
    this->res = res;
}

Resource::~Resource(){}
    
void Resource::setBack(void *back){
    KheResourceSetBack(res, back);
}
    
Instance Resource::getInstance() const{
    return KheResourceInstance(res);
}

int Resource::getInstanceIndex() const{
    if(isDummy())
        return dummyId;
    return KheResourceInstanceIndex(res);
}

ResourceType Resource::getType() const{
    return KheResourceResourceType(res);
}

int Resource::getTypeIndex() const{
    return KheResourceInstanceIndex(res);
}

std::string Resource::getId() const{
    if(isDummy())
        return "ResourceDummy";
    return KheResourceId(res);
}

std::string Resource::getName() const{
    return KheResourceName(res);
}

ResourceGroup Resource::getPartition() const{
    return KheResourcePartition(res);
}

ResourceGroup Resource::getSingletonResourceGroup() const{
    return KheResourceSingletonResourceGroup(res);
}
    
IR<EventResource> Resource::getPreassignedEventResources() const{
    return createIter<EventResource>(*this);
}

IR<Constraint> Resource::getConstraints() const{
    return createIter<Constraint>(*this);
}
    
TimeGroup Resource::getHardUnavailableTimeGroup() const{
    return KheResourceHardUnavailableTimeGroup(res);
}
    
TimeGroup Resource::getUnavailableTimeGroup() const{
    return KheResourceHardAndSoftUnavailableTimeGroup(res);
}
    
bool Resource::avoidClashes(Cost cost) const{
    return KheResourceHasAvoidClashesConstraint(res, cost);
}

int Resource::getPreassignedEventsDuration(Cost cost) const{
    return  KheResourcePreassignedEventsDuration(res, cost);
}

IR<Event> Resource::getResourceLayerEvents() const{
    return createIter<Event>(*this);
}

int Resource::getResourceLayerDuration() const{
    return KheResourceLayerDuration(res);
}

bool Resource::isSimilar(const Resource &r) const{
    return KheResourceSimilar(res, r);
}

bool Resource::operator<(const Resource &r2) const{
    return getInstanceIndex()  < r2.getInstanceIndex();
}

bool Resource::operator!=(const Resource &r2) const{
    return getInstanceIndex() != r2.getInstanceIndex();
}

bool Resource::operator==(const Resource &r2) const{
    return getInstanceIndex() == r2.getInstanceIndex();
}

Resource::operator int() const{
    return getInstanceIndex();
}

Resource::operator std::string() const{
    return getId();
}

Resource::operator KHE_RESOURCE() const{
    if(isDummy())
        throw ObjectCreation("Tried to convert dummy obj to KHE");
    return res;
}

void Resource::setDummyId(int id){
    dummyId = id;
}
