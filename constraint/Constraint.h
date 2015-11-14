/* 
 * File:   Constraint.h
 * 
 */

#ifndef CONSTRAINT_H
#define	CONSTRAINT_H

#include "ResourceType.h"
#include "KheObjIter.h"
#include <iostream>

namespace khe{
    class Instance;
    class Cost;
    class CostFunction;
    
class Constraint{
public:
    //for cached Obj
    virtual std::string getObjType() const{ return "Constraint";}
    
    //Cannot be constructed directly; this is a virtual class
protected:
    Constraint();
public:
    using KheType = KHE_CONSTRAINT;
    
    Constraint(KHE_CONSTRAINT constr);
    Constraint(KHE_ASSIGN_RESOURCE_CONSTRAINT constr);
    Constraint(KHE_ASSIGN_TIME_CONSTRAINT constr);
    Constraint(KHE_SPLIT_EVENTS_CONSTRAINT constr);
    Constraint(KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT constr);
    Constraint(KHE_PREFER_RESOURCES_CONSTRAINT constr);
    Constraint(KHE_PREFER_TIMES_CONSTRAINT constr);
    Constraint(KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT constr);
    Constraint(KHE_SPREAD_EVENTS_CONSTRAINT constr);
    Constraint(KHE_LINK_EVENTS_CONSTRAINT constr);
    Constraint(KHE_ORDER_EVENTS_CONSTRAINT constr);
    Constraint(KHE_AVOID_CLASHES_CONSTRAINT constr);
    Constraint(KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT constr);
    Constraint(KHE_LIMIT_IDLE_TIMES_CONSTRAINT constr);
    Constraint(KHE_CLUSTER_BUSY_TIMES_CONSTRAINT constr);
    Constraint(KHE_LIMIT_BUSY_TIMES_CONSTRAINT constr);
    Constraint(KHE_LIMIT_WORKLOAD_CONSTRAINT constr);
    virtual ~Constraint();
    
    enum Tag{
        AssignResource      = KHE_ASSIGN_RESOURCE_CONSTRAINT_TAG,
        AssignTime          = KHE_ASSIGN_TIME_CONSTRAINT_TAG,
        SplitEvents         = KHE_SPLIT_EVENTS_CONSTRAINT_TAG,
        DistributeSplitEvents=KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT_TAG,
        PreferResources     = KHE_PREFER_RESOURCES_CONSTRAINT_TAG,
        PreferTimes         = KHE_PREFER_TIMES_CONSTRAINT_TAG,
        AvoidSplitAssignments=KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT_TAG,
        SpreadEvents        = KHE_SPREAD_EVENTS_CONSTRAINT_TAG,
        LinkEvents          = KHE_LINK_EVENTS_CONSTRAINT_TAG,
        OrderEvents         = KHE_ORDER_EVENTS_CONSTRAINT_TAG,
        AvoidClashes        = KHE_AVOID_CLASHES_CONSTRAINT_TAG,
        AvoidUnavailableTimes=KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT_TAG,
        LimitIdleTimes      = KHE_LIMIT_IDLE_TIMES_CONSTRAINT_TAG,
        ClusterBusyTimes    = KHE_CLUSTER_BUSY_TIMES_CONSTRAINT_TAG,
        LimitBusyTimes      = KHE_LIMIT_BUSY_TIMES_CONSTRAINT_TAG,
        LimitWorkload       = KHE_LIMIT_WORKLOAD_CONSTRAINT_TAG,
        ConstraintCount     = KHE_CONSTRAINT_TAG_COUNT
    };

    void setBack(void *back);
    void *getBack() const{
         return KheConstraintBack(constr);
    }
    
    Instance getInstance() const;
    virtual std::string getId() const;
    std::string getName() const;
    
    bool isRequired() const;
    int getWeight() const;
    Cost getCombinedWeight() const;
    CostFunction getCostFunction() const;
    int getIndex() const;
    Tag getTag() const;
    
    int appliesToCount() const;
    
    static std::string showTag(Tag tag);
    static std::string showTagSpaced(Tag tag);
    static Tag getTag(const std::string &str);
    std::string showCostFunction(const CostFunction &f) const;
    
    /**
     * Utility functions
     */
    static std::vector<Constraint> getByTag(const Instance &inst, Tag tag);
    static std::vector<Constraint> getByTag(const std::vector<Constraint> &constr, Tag tag);
    
    template <class T> static std::vector<T> getByType(const Instance &inst);
    template <class T> static std::vector<T> getByType(std::vector<Constraint> constraints);
    template <class T> static std::vector<T> getByType(IR<Constraint> constraints);
    template <class T> static std::vector<T> getByResourceType(const ResourceType &t, 
        const std::vector<T> &constraints);
    template <class T> static std::vector<T> conv(const std::vector<T> &constraints);
    
    
    bool operator<(const Constraint &constr) const;  
    operator int() const;
    operator std::string() const;
    operator KHE_CONSTRAINT() const;
    
    explicit operator KHE_ASSIGN_RESOURCE_CONSTRAINT() const;
    explicit operator KHE_ASSIGN_TIME_CONSTRAINT() const;
    explicit operator KHE_SPLIT_EVENTS_CONSTRAINT() const;
    explicit operator KHE_DISTRIBUTE_SPLIT_EVENTS_CONSTRAINT() const;
    explicit operator KHE_PREFER_RESOURCES_CONSTRAINT() const;
    explicit operator KHE_PREFER_TIMES_CONSTRAINT() const;
    explicit operator KHE_AVOID_SPLIT_ASSIGNMENTS_CONSTRAINT() const;
    explicit operator KHE_SPREAD_EVENTS_CONSTRAINT() const;
    explicit operator KHE_LINK_EVENTS_CONSTRAINT() const;
    explicit operator KHE_ORDER_EVENTS_CONSTRAINT() const;
    explicit operator KHE_AVOID_CLASHES_CONSTRAINT() const;
    explicit operator KHE_AVOID_UNAVAILABLE_TIMES_CONSTRAINT() const;
    explicit operator KHE_LIMIT_IDLE_TIMES_CONSTRAINT() const;
    explicit operator KHE_CLUSTER_BUSY_TIMES_CONSTRAINT() const;
    explicit operator KHE_LIMIT_BUSY_TIMES_CONSTRAINT() const;
    explicit operator KHE_LIMIT_WORKLOAD_CONSTRAINT() const;
    
    KHE_CONSTRAINT getConstr() const{
        return constr;
    }
    
protected:
    KHE_CONSTRAINT constr;
    
    void requireTag(Tag tag) const;
};

template <class T> std::vector<T> Constraint::getByType(const Instance &inst){
    Tag tag = T::tag;
    std::vector<T> res;
    auto constraints = getByTag(inst, tag);

    return std::move(getByType<T>(constraints));
}

template <class T> std::vector<T> Constraint::getByType(IR<Constraint> constraints){
    return Constraint::getByType<T>(constraints);
}

template <class T> std::vector<T> Constraint::getByType(std::vector<Constraint> constraints){
    Tag tag = T::tag;
    std::vector<T> res;
    std::vector<Constraint> filtered = getByTag(constraints, tag);

    for(auto constraint: filtered){
        res.push_back( T( static_cast<typename T::KheType>(constraint) ));
    }
    return std::move(res);
}

template <class T> std::vector<T> Constraint::getByResourceType(const ResourceType &t, 
    const std::vector<T> &constraints){
     std::vector<T> res;

     for(auto &constr : constraints){
         if(constr.getDomain().getType() == t)
             res.push_back(constr);
     }
     return std::move(res);
}

template <class T> std::vector<T> Constraint::conv(const std::vector<T> &constraints){
    std::vector<T> res;

    for(auto constraint : constraints){
        res.push_back( T( static_cast<typename T::KheType>(constraint) ) );
    }

    return std::move(res);
}

}
#endif	/* CONSTRAINT_H */

