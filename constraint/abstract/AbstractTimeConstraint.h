/* 
 * File:   AbstractTimeConstraint.h
 * 
 *
 * to understand the magic of this class, please
 * @see AbstractEventConstraint
 */

#ifndef ABSTRACTTIMECONSTRAINT_H
#define	ABSTRACTTIMECONSTRAINT_H

#include "Constraint.h"

#include "Time.h"
#include "TimeGroup.h"

namespace khe{
    
template <class PKheType, class DerivedClass> class AbstractTimeConstraint : virtual public Constraint{
public:
    
    /**
     * These are the functions provided by KHE
     * In Subclasses, overwrite the const members accordingly
     * 
     */
    typedef void (addTimeFuncT)(PKheType constr, KHE_TIME e);
    
    typedef int  (TimeCountFuncT)(PKheType constr);
    typedef KHE_TIME (getTimeFuncT)(PKheType constr, int i);
    
    void addTime(const Time &e){
        (*DerivedClass::addTimeFunc)(getConstr(), e);
    }

    std::vector<Time> getTimes() const{
        if(allowCaching){
            if(cachedT.empty())
                cachedT = Util::toArray<Time>(DerivedClass::getTimeFunc, getConstr(), 
                    (*DerivedClass::timeCountFunc)(getConstr()));
            return cachedT;
        }
        return std::move(Util::toArray<Time>(DerivedClass::getTimeFunc, getConstr(), 
            (*DerivedClass::timeCountFunc)(getConstr())));
    }
    
    
protected:
    const addTimeFuncT              *addTimeFunc        = 0;
    
    const TimeCountFuncT            *timeCountFunc      = 0;
    const getTimeFuncT              *getTimeFunc        = 0;
    
    
    mutable std::vector<Time> cachedT;
    
    PKheType getConstr() const{
        return static_cast<PKheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
    
    /**
     * This class is not meant to be instantiated explicitely as it 
     * only provides callable functionality
     */
    AbstractTimeConstraint(){}
    
public:
    virtual ~AbstractTimeConstraint(){}
    

};

}

#endif	/* ABSTRACTTIMECONSTRAINT_H */

