/* 
 * File:   Resource.h
 * 
 */

#ifndef RESOURCE_H
#define	RESOURCE_H

#include "global.h"
#include "ResourceGroup.h"
#include "PossibleDummy.h"
#include "ObjectCreation.h"
#include "TimeGroup.h"

#include <iostream>

namespace khe{
    
    class EventResource;
    class Cost;
    class Constraint;
    class ResourceType;
    class Instance;
    class Event;
    
class Resource : public PossibleDummy{
public:
    using KheType = KHE_RESOURCE;
    
    Resource(ResourceType t, const std::string &id, const std::string name, ResourceGroup partition);
    Resource(ResourceType t, const std::string &id, const std::string name);
    Resource(KheType res);
    virtual ~Resource();
    
    friend class ModelInitalizer;
    
    std::string getObjType() const {return "Resource"; }
    
    void setBack(void *back);
    void *getBack() const {
         return KheResourceBack(res);
    }
    
    Instance getInstance() const;
    int getInstanceIndex() const;
    ResourceType getType() const;
    int getTypeIndex() const;
    std::string getId() const;
    std::string getName() const;
    ResourceGroup getPartition() const;
    ResourceGroup getSingletonResourceGroup() const;
    
    IR<EventResource> getPreassignedEventResources() const;
    IR<Constraint> getConstraints() const;
    
    TimeGroup getHardUnavailableTimeGroup() const;
    
    /**
     * Returns hard and softly unavailable times
     * @return 
     */
    TimeGroup getUnavailableTimeGroup() const;
    
    IR<Event> getResourceLayerEvents() const;
    int getResourceLayerDuration() const;
    
    bool avoidClashes(Cost cost) const;
    int getPreassignedEventsDuration(Cost cost) const;
    
    bool isSimilar(const Resource &r) const;
    
    static Resource getDummy(){
        return Resource();
    }
    
    bool operator<(const Resource &r2) const;
    bool operator!=(const Resource &r2) const;
    bool operator==(const Resource &r2) const;
    operator int() const;
    operator std::string() const;
    operator KheType() const;
    
    
    //Used to instantiate dummies
    explicit Resource(): PossibleDummy(true), res(NULL){};
    
    
    static void setDummyId(int id);
    
protected:
    KheType res;
    
    static int dummyId;
};

}

#endif	/* RESOURCE_H */

