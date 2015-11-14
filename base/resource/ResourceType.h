/* 
 * File:   ResourceType.h
 * 
 */

#ifndef RESOURCETYPE_H
#define	RESOURCETYPE_H

#include "global.h"
#include "Resource.h"
#include "ResourceGroup.h"

namespace khe{
    class Instance;
    
class ResourceType {
public:
    using KheType = KHE_RESOURCE_TYPE;
    ResourceType(Instance inst, const std::string &id, const std::string &name, bool hasPartitions = false);
    ResourceType(KheType type);
    virtual ~ResourceType();
    
     /**
     * Miscellaneous and ubiquitous methods
     */
    void setBack(void *back);
    void *getBack() const {
         return KheResourceTypeBack(type);
    }
    
    Instance getInstance() const;
    int getIndex() const;
    std::string getId() const;
    std::string getName() const;
    bool hasPartitions() const;
    
    IR<ResourceGroup> getGroups() const;
    ResourceGroup getGroup(const std::string &id) const;
    
    /**
     * The following have not been implemented because they are not XML features:
     * KheResourceTypePartitionCount
     * KheResourceTypePartition
     */
    
    IR<ResourceGroup> getPartitions() const;
    ResourceGroup getFullResourceGroup() const;
    ResourceGroup getEmptyResourceGroup() const;
    
    IR<Resource>            getResources() const;
    std::vector<Resource>   getResourcesWithDummy() const;
    
    bool demandsAllArePreassigned() const;
    bool demandsAvoidSplitAssignmentsCount() const;
    
    operator KheType() const{
        return type;
    }
    
    bool operator==(const ResourceType &rt2) const{
        return getId() == rt2.getId();
    }
    
protected:
    KheType type;
};
}

#endif	/* RESOURCETYPE_H */

