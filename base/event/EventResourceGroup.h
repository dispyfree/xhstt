/* 
 * File:   EventResourceGroup.h
 * 
 */

#ifndef EVENTRESOURCEGROUP_H
#define	EVENTRESOURCEGROUP_H

#include "global.h"
#include "ResourceGroup.h"
#include "EventResource.h"

namespace khe{

    class Event;
    class ResourceGroup;
    
class EventResourceGroup {
public:
    using KheType = KHE_EVENT_RESOURCE_GROUP;
    
    EventResourceGroup(const Event &evt, const ResourceGroup &grp); 
    EventResourceGroup(KheType grp);
    virtual ~EventResourceGroup();
    
    Event getEvent() const;
    ResourceGroup getResourceGroup() const;
    
    operator KheType() const{
        return erg;
    }
    
    
protected:
    KheType erg;

};

}

#endif	/* EVENTRESOURCEGROUP_H */

