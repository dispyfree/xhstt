/* 
 * File:   AbstractEventGroupConstraint.h
 * 
 */

#ifndef ABSTRACTEVENTGROUPCONSTRAINT_H
#define	ABSTRACTEVENTGROUPCONSTRAINT_H

#include "Constraint.h"
#include "ObjectTypeMismatch.h"
#include "Util.h"
#include <type_traits>

namespace khe{
    
    class Event;
    class EventGroup;
    
    /**
     * addReturnIsBoolean sets the return type of add* functions to boolean
     * and adds "*problemEvent" as a special parameter; see below 
     * 
     * Note: this design is not particularly nice, but does prevent 
     * the class hierarchy from bloating even more
     */
template <class PKheType, class DerivedClass, bool addReturnIsTrue = false>
    class AbstractEventGroupConstraint : virtual public Constraint{
public:
    
    /**
     * These are the functions provided by KHE
     * In Subclasses, overwrite the const members accordingly
     * 
     * For the meaning of the boolean reaturn value of add* functions,
     * please refer to the documentation; as most do require void function,
     * we use type traints to handle this
     * 
     */
    typedef void (addEventGroupFunc)(PKheType constr, KHE_EVENT_GROUP);

    typedef int (EventGroupCountFunc)(PKheType constr);
    typedef KHE_EVENT_GROUP (getEventGroupFunc)(PKheType constr, int i);
    
    /**
     * todo: think of a solution on how to overload add!
     * @param eg
     */
    virtual void addEvtGrp(const EventGroup &eg){
        (*DerivedClass::addEventGroup)(getConstr(), eg);
    }

    std::vector<EventGroup> getEventGroups() const{
        if(allowCaching){
            if(cachedEventGroups.empty())
                cachedEventGroups = Util::toArray<EventGroup>(DerivedClass::getEventGroup, getConstr(), 
                    (*DerivedClass::eventGroupCount)(getConstr()));
            return cachedEventGroups;
        }
        return std::move(Util::toArray<EventGroup>(DerivedClass::getEventGroup, getConstr(), 
           (*DerivedClass::eventGroupCount)(getConstr())));
    }
    
protected:
    
    const addEventGroupFunc *addEventGroup   = 0;
    
    const EventGroupCountFunc       *eventGroupCount = 0; 
    const getEventGroupFunc         *getEventGroup   = 0;
    
    mutable std::vector<EventGroup> cachedEventGroups;
    
    PKheType getConstr() const{
        return static_cast<typename DerivedClass::KheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractEventGroupConstraint(){}
    
public:     
    virtual ~AbstractEventGroupConstraint(){}

};

template <class PKheType, class DerivedClass>
    class AbstractEventGroupConstraint<PKheType, DerivedClass, true> : virtual public Constraint{
public:
    /**
     * This is a special type just for 
     * KhePreferResourcesConstraintAddEventGroup
     * KheAvoidSplitAssignmentsConstraintAddEventGroup
     */
    typedef bool (addEventGroupFunc)(PKheType constr, KHE_EVENT_GROUP, 
            KHE_EVENT *problemEvt);
    
    typedef int (EventGroupCountFunc)(PKheType constr);
    typedef KHE_EVENT_GROUP (getEventGroupFunc)(PKheType constr, int i);
    
    
    virtual void addEvtGrp(const EventGroup &eg){
            /**
             * throw exception if the Event Group could not be added because of a conflicting event
             * this is typically to an object type mismatch; using several objects of incompatible type
             * together will cause this exception to be thrown.
             * 
             * Note: for some reason you can _not_ partially specialize a method 
             * in C++ without specializing the entire class 
             */
            KHE_EVENT evt;
            bool result = (*DerivedClass::addEventGroup)(getConstr(), eg, &evt);

            if(!result)
                throw ObjectTypeMismatch<KHE_EVENT>("Error adding EventGroup", evt);
    }

    std::vector<EventGroup> getEventGroups() const{
        if(allowCaching){
            if(cachedEventGroups.empty())
                cachedEventGroups = Util::toArray<EventGroup>(DerivedClass::getEventGroup, getConstr(), 
                    (*DerivedClass::eventGroupCount)(getConstr()));
            return cachedEventGroups;
        }
        return std::move(Util::toArray<EventGroup>(DerivedClass::getEventGroup, getConstr(), 
           (*DerivedClass::eventGroupCount)(getConstr())));
    }
    
protected:
    
    const addEventGroupFunc *addEventGroup   = 0;
    
    const EventGroupCountFunc       *eventGroupCount = 0; 
    const getEventGroupFunc         *getEventGroup   = 0;
    
    mutable std::vector<EventGroup> cachedEventGroups;
    
    PKheType getConstr() const{
        return static_cast<typename DerivedClass::KheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractEventGroupConstraint(){}
    
public:     
    virtual ~AbstractEventGroupConstraint(){}

};


}

#endif	/* ABSTRACTEVENTGROUPCONSTRAINT_H */

