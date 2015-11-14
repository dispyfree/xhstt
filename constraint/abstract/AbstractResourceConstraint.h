/* 
 * File:   AbstractResourceConstraint.h
 * 
 * 
 * In order to understand this class, please
 * @see AbstractResourceConstraint
 *
 */

#ifndef ABSTRACTRESOURCECONSTRAINT_H
#define	ABSTRACTRESOURCECONSTRAINT_H

#include "Constraint.h"
#include <set>

#include "Resource.h"
#include "ResourceGroup.h"

namespace khe{
    
    /**
     * addReturnIsBoolean sets the return type of add* functions to boolean
     */
template <class PKheType, class DerivedClass, bool addReturnIsBoolean = false> 
    class AbstractResourceConstraint : 
        virtual public Constraint
{
public:
    virtual ~AbstractResourceConstraint(){}
    
    
    /**
     * These are the functions provided by KHE
     * In subclasses, overwrite the const members accordingly
     * 
     * For the meaning of the boolean return value of add* functions,
     * please refer to the documentation
     * 
     * (note: we need typename because this is a dependent scope)
     */
    typedef typename std::conditional<addReturnIsBoolean, bool, void>::type addReturnType;
    typedef addReturnType (addResourceFunc)(PKheType constr, KHE_RESOURCE r);
    typedef addReturnType (addResourceGroupFunc)(PKheType constr, KHE_RESOURCE_GROUP);
    
    typedef int (ResourceCountFunc)(PKheType constr);
    typedef KHE_RESOURCE (getResourceFunc)(PKheType constr, int i);
    
    typedef int (ResourceGroupCountFunc)(PKheType constr);
    typedef KHE_RESOURCE_GROUP (getResourceGroupFunc)(PKheType constr, int i);
    

    addReturnType addRes(const Resource &e){
        (*DerivedClass::addResource)(getConstr(), e);
    }
    
    /**
     * Important: getResources just returns the resources AS INDICATED BY THE XML
     * If you really wish to get _all_ resources, 
     * @see getAllResources
     */
    std::vector<Resource> getResources() const{
        if(allowCaching){
            if(cachedR.empty())
                cachedR = Util::toArray<Resource>(DerivedClass::getResource, getConstr(), 
                    (*DerivedClass::resourceCount)(getConstr()));
            return cachedR;
        }
        return std::move(Util::toArray<Resource>(DerivedClass::getResource, getConstr(), 
            (*DerivedClass::resourceCount)(getConstr())));
    }
    
    std::vector<Resource> getAllResources() const{
        if(allowCaching){
            if(cachedAR.empty())
                cachedAR = getAllResourcesUncached();
            return cachedAR;
        }
        return std::move(getAllResourcesUncached());
    }

    addReturnType addResGrp(const ResourceGroup &eg){
        return (*DerivedClass::addResourceGroup)(getConstr(), eg);
    }

    std::vector<ResourceGroup> getResourceGroups() const{
        if(allowCaching){
            if(cachedEG.empty())
                cachedEG = Util::toArray<ResourceGroup>(DerivedClass::getResourceGroup, getConstr(), 
                    (*DerivedClass::resourceGroupCount)(getConstr()));
            return cachedEG;
        }
        
        return std::move(Util::toArray<ResourceGroup>(DerivedClass::getResourceGroup, getConstr(), 
           (*DerivedClass::resourceGroupCount)(getConstr())));
    }
    
protected:
    
    const addResourceFunc              *addResource        = 0;
    const addResourceGroupFunc         *addResourceGroup   = 0;
    
    const ResourceCountFunc            *resourceCount      = 0;
    const getResourceFunc              *getResource        = 0;
    
    const ResourceGroupCountFunc       *resourceGroupCount = 0; 
    const getResourceGroupFunc         *getResourceGroup   = 0;
    
    mutable std::vector<Resource> cachedR;
    mutable std::vector<Resource> cachedAR;
    mutable std::vector<ResourceGroup> cachedEG;
    
    std::vector<Resource> getAllResourcesUncached() const{
        auto direct = this->getResources();
        auto groups = this->getResourceGroups();
        std::set<Resource> ret;
        ret.insert(direct.begin(), direct.end());
        
        for(auto &group : groups){
            auto newRes = group.getResources();
            ret.insert(newRes.begin(), newRes.end());
        }
        
        std::vector<Resource> vec;
        vec.insert(vec.end(), ret.begin(), ret.end());
        
        return std::move(vec);
    }
    
    PKheType getConstr() const{
        return static_cast<typename DerivedClass::KheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    /**
     * This class is not meant to be explicitely instantiated
     */
    AbstractResourceConstraint(){}
    

};

}

#endif	/* ABSTRACTRESOURCECONSTRAINT_H */

