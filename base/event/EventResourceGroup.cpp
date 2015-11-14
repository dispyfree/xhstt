/* 
 * File:   EventResourceGroup.cpp
 * 
 */

#include "Event.h"
#include "ResourceGroup.h"
#include "EventResourceGroup.h"
using namespace khe;

using erg = EventResourceGroup;

erg::EventResourceGroup(const Event &evt, const ResourceGroup &grp){
    erg = KheEventResourceGroupMake(evt, grp);
}

erg::EventResourceGroup(KHE_EVENT_RESOURCE_GROUP grp){
    Util::rnn(grp);
    erg = grp;
}

ResourceGroup erg::getResourceGroup() const{
    return KheEventResourceGroupResourceGroup(erg);
}


erg::~EventResourceGroup() {
}

