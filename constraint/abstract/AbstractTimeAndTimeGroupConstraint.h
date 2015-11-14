/* 
 * File:   AbstractTimeAndTimeGroupConstraint.h
 * 
 */

#ifndef ABSTRACTTIMEANDTIMEGROUPCONSTRAINT_H
#define	ABSTRACTTIMEANDTIMEGROUPCONSTRAINT_H

#include "AbstractTimeConstraint.h"
#include "AbstractTimeGroupConstraint.h"

#include <set>
namespace khe{
    
    
template <class PKheType, class DerivedClass> class  AbstractTimeAndTimeGroupConstraint 
    :   virtual public AbstractTimeConstraint<PKheType, DerivedClass>,
        virtual public AbstractTimeGroupConstraint<PKheType, DerivedClass>
{

public:
    virtual ~AbstractTimeAndTimeGroupConstraint(){}
    
     std::vector<Time> getAllTimes() const{
         if(allowCaching){
             if(cachedT.empty())
                cachedT = getAllTimesUncached();
             return cachedT;
         }
         return std::move(getAllTimesUncached());
    }
    
protected:
    
    mutable std::vector<Time> cachedT;
    
    std::vector<Time> getAllTimesUncached() const{
       auto direct = this->getTimes();
        auto groups = this->getTimeGroups();
        std::set<Time> ret;
        ret.insert(direct.begin(), direct.end());
        
        for(auto &group : groups){
            auto newRes = group.getTimes();
            ret.insert(newRes.begin(), newRes.end());
        }
        
        std::vector<Time> vec;
        vec.insert(vec.end(), ret.begin(), ret.end());
        
        return std::move(vec); 
    }
    
    AbstractTimeAndTimeGroupConstraint(){}

};

}
#endif	/* ABSTRACTTIMEANDTIMEGROUPCONSTRAINT_H */

