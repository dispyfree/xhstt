/* 
 * File:   AbstractEventAndEventGroupConstraint.h
 * 
 */

#ifndef ABSTRACTEVENTANDEVENTGROUPCONSTRAINT_H
#define	ABSTRACTEVENTANDEVENTGROUPCONSTRAINT_H

#include "AbstractEventConstraint.h"
#include "AbstractEventGroupConstraint.h"

#include <set>


namespace khe{
    
/**
 * For the meaning of addReturnIsBoolean, please refer to 
 * AbstractEventConstraint
 */
template <class PKheType, class DerivedClass, bool addReturnIsBoolean = false> class  AbstractEventAndEventGroupConstraint 
    :   virtual public AbstractEventConstraint<PKheType, DerivedClass, addReturnIsBoolean>,
        virtual public AbstractEventGroupConstraint<PKheType, DerivedClass, addReturnIsBoolean>
{

public:
   virtual ~AbstractEventAndEventGroupConstraint(){}
    
    std::vector<Event> getAllEvents() const{
        auto direct = this->getEvents();
        auto groups = this->getEventGroups();
        std::set<Event> ret;
        ret.insert(direct.begin(), direct.end());
        
        for(auto &group : groups){
            auto newRes = group.getEvents();
            ret.insert(newRes.begin(), newRes.end());
        }
        
        std::vector<Event> vec;
        vec.insert(vec.end(), ret.begin(), ret.end());
        
        return std::move(vec);
    }
    
protected:
    AbstractEventAndEventGroupConstraint(){}

};

}
#endif	/* ABSTRACTEVENTANDEVENTGROUPCONSTRAINT_H */

