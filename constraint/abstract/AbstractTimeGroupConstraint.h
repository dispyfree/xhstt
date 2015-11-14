/* 
 * File:   AbstractTimeGroupConstraint.h
 * 
 */

#ifndef ABSTRACTTIMEGROUPCONSTRAINT_H
#define	ABSTRACTTIMEGROUPCONSTRAINT_H

#include "Constraint.h"

namespace khe{
    class TimeGroup;
    
template <class PKheType, class DerivedClass> class AbstractTimeGroupConstraint 
    : virtual public Constraint
{
public: 
    virtual ~AbstractTimeGroupConstraint(){}
    
    /**
     * These are the functions provided by KHE
     * In Subclasses, overwrite the const members accordingly
     * 
     */
    typedef void (addTimeGroupFuncT)(PKheType constr, KHE_TIME_GROUP);
    
    typedef int (TimeGroupCountFuncT)(PKheType constr);
    typedef KHE_TIME_GROUP (getTimeGroupFuncT)(PKheType constr, int i);
    
    
    void addTimeGrp(const TimeGroup &eg){
        return (*DerivedClass::addTimeGroupFunc)(getConstr(), eg);
    }

    std::vector<TimeGroup> getTimeGroups() const{
        if(allowCaching){
            if(cachedTG.empty())
                cachedTG = Util::toArray<TimeGroup>(DerivedClass::getTimeGroupFunc, getConstr(), 
                    (*DerivedClass::timeGroupCountFunc)(getConstr()));
            return cachedTG;
        }
        return std::move(Util::toArray<TimeGroup>(DerivedClass::getTimeGroupFunc, getConstr(), 
           (*DerivedClass::timeGroupCountFunc)(getConstr())));
    }
    
    PKheType getConstr() const{
        return static_cast<PKheType>(*dynamic_cast<const DerivedClass*>(this));
    }
    
protected:
    /**
      * This class is not meant to be instantiated explicitely as it 
      * only provides callable functionality
      */
    AbstractTimeGroupConstraint(){}
    
    const addTimeGroupFuncT         *addTimeGroupFunc   = 0;
    
    const TimeGroupCountFuncT       *timeGroupCountFunc = 0; 
    const getTimeGroupFuncT         *getTimeGroupFunc   = 0;
    
    
    mutable std::vector<TimeGroup> cachedTG;

};

}
#endif	/* ABSTRACTTIMEGROUPCONSTRAINT_H */

