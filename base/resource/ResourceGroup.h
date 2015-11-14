/* 
 * File:   ResourceGroup.h
 * 
 */

#ifndef RESOURCEGROUP_H
#define	RESOURCEGROUP_H

#include "global.h"

namespace khe{
    
    class ResourceType;
    class Instance;
    class Resource;
    
class ResourceGroup {
public:
    using KheType = KHE_RESOURCE_GROUP;
    ResourceGroup(ResourceType t, const std::string &id, const std::string &name, bool isPartition = false);
    ResourceGroup(KheType t);
    virtual ~ResourceGroup();
    
    /**
     * Miscellaneous and ubiquitous methods
     */
    void setBack(void *back);
    void *getBack() const {
         return KheResourceGroupBack(grp);
    }
    
    ResourceType    getType() const;
    Instance        getInstance() const;
    std::string     getId() const;
    std::string     getName() const;
    
    bool isPartition() const;
    void add(Resource r);
    ResourceGroup &operator+=(const Resource &r);
    void sub(Resource r);
    ResourceGroup &operator-=(const Resource &r);
    void doUnion(ResourceGroup b);
    void intersect(ResourceGroup b);
    void difference(ResourceGroup b);
    
    IR<Resource> getResources() const;
    bool contains(const Resource &r) const;
    bool equals(const ResourceGroup &r) const;
    bool isSubSet(const ResourceGroup &b) const;
    bool operator<=(const ResourceGroup &b) const;
    bool isDisjoint(const ResourceGroup &b) const;
    
    ResourceGroup getPartition() const;
    
    void debug(int verbosity, int indent);
    
    operator KheType() const{
        return grp;
    }
    
    /**
     * Beware: this does not follow the "equals" relation but simply compares
     * KHE references for storage in containers
     * @param rg2
     * @return 
     */
    bool operator==(const ResourceGroup &gr2) const{
        return getId() == gr2.getId();
    }
    
protected:
    KheType grp;
    

};
}
#endif	/* RESOURCEGROUP_H */

