/* 
 * File:   AbstractEventResourceConstraint.h
 * 
 */

#ifndef ABSTRACTEVENTRESOURCECONSTRAINT_H
#define	ABSTRACTEVENTRESOURCECONSTRAINT_H

#include "Constraint.h"

#include "EventResource.h"

namespace khe{
    
    class EventResource;
/**
 * The withGroupIndex = true (last template parameter) is only needed for
 * AvoidSplitAssignmentsConstraint
 * to denote the EventGroupIndex. 
 * 
 * The second specialization is at the bottom of this file.
 * This is not a particularly nifty implementation but proved to be more readable
 * than std::conditional + mumbo-jumbo
 */
    template <class PKheType, class DerivedClass, bool withGroupIndex = false>
    class AbstractEventResourceConstraint : virtual public Constraint{
    };
    
template <class PKheType, class DerivedClass>
    class AbstractEventResourceConstraint<PKheType, DerivedClass, true> : virtual public Constraint{
public:
    
    typedef void (addEventResourceFunc)(PKheType constr, int egIndex, KHE_EVENT_RESOURCE e);
    typedef int (EventResourceCountFunc)(PKheType constr, int egIndex);
    typedef KHE_EVENT_RESOURCE (getEventResourceFunc)(PKheType constr, int egIndex, int i);

    
    virtual void addEvtRes(const EventResource &er, int egIndex){
        (*DerivedClass::addEventResource)(getConstr(), egIndex, er);
    }

    std::vector<EventResource> getEventResources(int egIndex) const{
        if(allowCaching){
            if(cachedER.empty())
                cachedER = Util::toArray<EventResource>(DerivedClass::getEventResource, getConstr(), egIndex
                    (*DerivedClass::eventResourceCount)(getConstr()), egIndex);
            return cachedER;
        }
        return std::move(Util::toArray<EventResource>(DerivedClass::getEventResource, getConstr(), egIndex
            (*DerivedClass::eventResourceCount)(getConstr()), egIndex));
    }


    
protected:
    
    const addEventResourceFunc              *addEventResource        = 0;
    
    const EventResourceCountFunc            *eventResourceCount      = 0;
    const getEventResourceFunc              *getEventResource        = 0;

    mutable std::vector<EventResource> cachedER;
    
    PKheType getConstr() const{
        return static_cast<PKheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractEventResourceConstraint(){}
    
public:     
   virtual ~AbstractEventResourceConstraint(){}

};


/**
 * ---------------------------------------------------------------------------------------
 */
template <class PKheType, class DerivedClass>
    class AbstractEventResourceConstraint<PKheType, DerivedClass, false> : virtual public Constraint{
public:
    
    typedef void (addEventResourceFunc)(PKheType constr, KHE_EVENT_RESOURCE e);
    typedef int (EventResourceCountFunc)(PKheType constr);
    typedef KHE_EVENT_RESOURCE (getEventResourceFunc)(PKheType constr, int i);

    
    virtual void add(const EventResource &er){
        (*DerivedClass::addEventResource)(getConstr(), er);
    }

     std::vector<EventResource> getEventResources() const{
         EventResourceCountFunc *func = DerivedClass::eventResourceCount;
         
        if(allowCaching){
            if(cachedER.empty())
                cachedER = Util::toArray<EventResource>(DerivedClass::getEventResource, this->getConstr(),
                        func(this->getConstr()));
            return cachedER;
        }
        return std::move(Util::toArray<EventResource>(DerivedClass::getEventResource, this->getConstr(),
            func(this->getConstr())));
    }

    
protected:
    
    constexpr static const addEventResourceFunc              *addEventResource        = 0;
    
    constexpr static const EventResourceCountFunc            *eventResourceCount      = 0;
    constexpr static const getEventResourceFunc              *getEventResource        = 0;
    
    mutable std::vector<EventResource> cachedER;
    
    PKheType getConstr() const{
        return static_cast<typename DerivedClass::KheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractEventResourceConstraint(){}
    
public:     
    AbstractEventResourceConstraint(const AbstractEventResourceConstraint& orig){}
    virtual ~AbstractEventResourceConstraint(){}

};

}
#endif	/* ABSTRACTEVENTRESOURCECONSTRAINT_H */

