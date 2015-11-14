/* 
 * File:   AbstractEventConstraint.h
 * 
 * 
 * This class abstracts the features attached to events and event groups if 
 * a constraint uses them. 
 * I.e.: adding events and groups and listing them. 
 *
 * for the template magic, see here:
 * http://stackoverflow.com/questions/13340074/c-static-const-members-overriding
 * 
 * You could even think of abstracting this further; however, C++ does _not_ allow
 * for abstraction of method names, i.e. while getAll<EventGroup>() is possible, this is ugly
 * and getEventGroups() is _not_ abstractable using templates. 
 */

#ifndef ABSTRACTEVENTCONSTRAINT_H
#define	ABSTRACTEVENTCONSTRAINT_H

#include "Constraint.h"
#include <type_traits>

#include "Event.h"
#include "EventGroup.h"

namespace khe{
    
    /**
     * addReturnIsBoolean sets the return type of add* functions to boolean
     * and adds "*problemEvent" as a special parameter; see below 
     */
template <class PKheType, class DerivedClass, bool addReturnIsBoolean = false>
    class AbstractEventConstraint : virtual public Constraint{
public:
    
    /**
     * These are the functions provided by KHE
     * In Subclasses, overwrite the const members accordingly
     * 
     * For the meaning of the boolean return value of add* functions,
     * please refer to the documentation; as most do require void function,
     * we use type traints to handle this
     * 
     * (note: we need typename because this is a dependent scope)
     */
    typedef typename std::conditional<addReturnIsBoolean, bool, void>::type addReturnType;
    typedef addReturnType (addEventFunc)(PKheType constr, KHE_EVENT e);
    
    
    typedef int (EventCountFunc)(PKheType constr);
    typedef KHE_EVENT (getEventFunc)(PKheType constr, int i);

    virtual void addEvt(const Event &e){
        (*DerivedClass::addEvent)(getConstr(), e);
    }
    
    std::vector<Event> getEvents() const{
        if(allowCaching){
            if(cachedEvents.size() == 0)
                cachedEvents = Util::toArray<Event>(DerivedClass::getEvent, getConstr(), 
                    (*DerivedClass::eventCount)(getConstr()));
            return cachedEvents;
        }
        return std::move(Util::toArray<Event>(DerivedClass::getEvent, getConstr(), 
                (*DerivedClass::eventCount)(getConstr())));
    }

    
protected:
    
    const addEventFunc              *addEvent        = 0;
    
    const EventCountFunc            *eventCount      = 0;
    const getEventFunc              *getEvent        = 0;
    
    mutable std::vector<Event> cachedEvents;
    
    PKheType getConstr() const{
        return static_cast<PKheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractEventConstraint(){}
    
public:     
    virtual ~AbstractEventConstraint(){}

};

}

#endif	/* ABSTRACTEVENTCONSTRAINT_H */

