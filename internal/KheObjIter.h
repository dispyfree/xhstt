/* 
 * File:   KheObjIter.h
 * 
 * special class to model the specific requirements of iterators for KHE
 * in particular, the object storage is hidden by its C counterpart, the exposed
 * access functions resemble a random access list. 
 */

#ifndef KHEOBJITER_H
#define	KHEOBJITER_H

//Boost shall not interfere with C++11 placeholders
#define BOOST_BIND_NO_PLACEHOLDERS

#include <boost/iterator/iterator_facade.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <stdexcept>
#include <functional>

#include "IterAccessMapping.h"

using namespace std::placeholders;

namespace khe{


template <class KheObj> class KheObjIter:
    public boost::iterator_facade<
        KheObjIter<KheObj>
      , typename KheObj::KheType
      , boost::random_access_traversal_tag,
        KheObj>
{
    
public:
    
    template <class PO> using TCount =  int (*)(typename PO::KheType);
    typedef int (* TWrappedCountFunc)();
    
    template <class PO> using TAccessFunc = 
        typename KheObj::KheType (*)(typename PO::KheType, int index);
    
    template <class ParentObj> 
        KheObjIter( const ParentObj &obj, 
                    TCount<ParentObj> count,
                    TAccessFunc<ParentObj> acc) 
        : currentId(0), countF(0), accF(0){
        countF      = std::bind(count, obj);
        accF        = std::bind(acc, obj, std::placeholders::_1);
        totalCount  = countF();
    }
            
    KheObjIter getEnd() const{
        KheObjIter ret(*this);
        ret.currentId = totalCount;
        return ret;
    }
            
private:
    friend class boost::iterator_core_access;
    
    int currentId;
    int totalCount;
    
    std::function<int()> countF;
    std::function<typename KheObj::KheType (int index)> accF;
    
    //Implementation of core functions
    void increment() { currentId++; }
    void decrement() { currentId--;}

    /**
     * Hint: don't compare pointers on different objects ;-)
     */
    bool equal(KheObjIter const& other) const
    {
        return  currentId == other.currentId;
    }
    
    void advance(int n){
        currentId += n;
        if(currentId >= totalCount || currentId < 0)
            throw std::runtime_error("Out of bounds");
    }
    
    int distance_to(const KheObjIter &i) const{
        return i.currentId - this->currentId;
    }

    KheObj dereference() const { 
        return std::move(accF(currentId)); 
    }

    
};


template <class KheObj> using IR = 
boost::iterator_range<KheObjIter<KheObj>>;

template <class ChildObj, class ParentObj> 
  IR<ChildObj> createIter(const ParentObj &obj){
    auto iter = KheObjIter<ChildObj>(obj, 
            IAM<ParentObj, ChildObj>::countFunc, 
            IAM<ParentObj, ChildObj>::accessFunc);
    return IR<ChildObj>(iter, iter.getEnd());
} 

}

#endif	/* KHEOBJITER_H */

