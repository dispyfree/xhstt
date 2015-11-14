/* 
 * File:   PreferResourcesConstraint.h
 * 
 */

#ifndef PREFERRESOURCESCONSTRAINT_H
#define	PREFERRESOURCESCONSTRAINT_H

#include "global.h"
#include "AbstractEventAndEventGroupConstraint.h"
#include "AbstractResourceConstraint.h"
#include "AbstractEventResourceConstraint.h"

namespace khe{
  
    class EventResource;
    
    using prct = KHE_PREFER_RESOURCES_CONSTRAINT;
    
class PreferResourcesConstraint :
        virtual public AbstractEventAndEventGroupConstraint<prct, PreferResourcesConstraint, true>,
        virtual public AbstractResourceConstraint<prct, PreferResourcesConstraint, true>,
        virtual public AbstractEventResourceConstraint<prct, PreferResourcesConstraint>
{
public:
    
    friend class AbstractEventConstraint<prct, PreferResourcesConstraint, true>;
    friend class AbstractEventGroupConstraint<prct, PreferResourcesConstraint, true>;
    friend class AbstractResourceConstraint<prct, PreferResourcesConstraint, true>;
    
    using KheType           = prct;
    const static Tag tag    = PreferResources;
    
    PreferResourcesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, CostFunction func, const std::string &role);
    PreferResourcesConstraint(Instance inst, const std::string &id, const std::string &name, 
            bool required, int weight, const std::string &role);
    
    PreferResourcesConstraint(KheType raw);
    virtual ~PreferResourcesConstraint();
    
    std::string getRole() const;
    ResourceGroup getDomain() const;
    
    
    
    static std::vector<PreferResourcesConstraint> getByRole(
        const std::string &role,const std::vector<PreferResourcesConstraint> &constraints); 
    
    operator KheType() const{
        return constr;
    }
    
    operator KHE_CONSTRAINT() const{
        return KheFromPreferResourcesConstraint(constr);
    }
    
    bool operator< (const PreferResourcesConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;
    
    constexpr static const addResourceFunc              *addResource        = &KhePreferResourcesConstraintAddResource;
    constexpr static const addResourceGroupFunc         *addResourceGroup   = &KhePreferResourcesConstraintAddResourceGroup;
    
    constexpr static const ResourceCountFunc            *resourceCount      = &KhePreferResourcesConstraintResourceCount;
    constexpr static const getResourceFunc              *getResource        = &KhePreferResourcesConstraintResource;
    
    constexpr static const ResourceGroupCountFunc       *resourceGroupCount = &KhePreferResourcesConstraintResourceGroupCount; 
    constexpr static const getResourceGroupFunc         *getResourceGroup   = &KhePreferResourcesConstraintResourceGroup;
    
    
   
    constexpr static const addEventFunc              *addEvent        = &KhePreferResourcesConstraintAddEvent;
    constexpr static const addEventGroupFunc         *addEventGroup   = &KhePreferResourcesConstraintAddEventGroup;
    
    constexpr static const EventCountFunc            *eventCount      = &KhePreferResourcesConstraintEventCount;
    constexpr static const getEventFunc              *getEvent        = &KhePreferResourcesConstraintEvent;
    
    constexpr static const EventGroupCountFunc       *eventGroupCount = &KhePreferResourcesConstraintEventGroupCount; 
    constexpr static const getEventGroupFunc         *getEventGroup   = &KhePreferResourcesConstraintEventGroup;
};

}

#endif	/* PREFERRESOURCESCONSTRAINT_H */

