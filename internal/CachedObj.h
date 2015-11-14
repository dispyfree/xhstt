/* 
 * File:   CachedObj.h
 * 
 *
 * Created on May 28, 2015, 4:46 PM
 */

#ifndef CACHEDOBJ_H
#define	CACHEDOBJ_H

#include <string>

#include "Ident.h"
#include "KheObjInfo.h"

namespace khe{

template <class T> class CachedObj{
public:
    CachedObj() : _isCached(false){};
    CachedObj(const CachedObj& orig) : _isCached(false){};
    virtual ~CachedObj(){}

    unsigned int getNumId(const std::string &id) const{
        if(useBackPointerForNumIds)
            return bPGetNumId();
        else{
            if(!_isCached)
                generateCachedId(id);

            return cachedId;
        }
    }
    
    
    /**
     * @see getNumId
     */
    unsigned int bPGetNumId() const{
        T *obj = const_cast<T*>(dynamic_cast<const T*>(this));
        
        KheObjInfo *info = (KheObjInfo*) obj->getBack();
        initializeIfNull(obj);
        
        return info->id;
    }
    
    unsigned int bPSetNumId(unsigned int newId) const{
        T *obj = const_cast<T*>(dynamic_cast<const T*>(this));
        KheObjInfo *info = (KheObjInfo*) obj->getBack();
        initializeIfNull(obj);
        
        info->id = newId;
        
        return newId;
    }
    
    /**
     * Use only if you know what you do
     * Note; this function does not ensure that newId equals the old id
     * if you use back pointers. This can fail in two situations:
     * 
     * - you use back pointers and Ident simultaneously. This implementation
     *   does carefully avoid that, just as you ought to.
     * - KHE reports another NumId than Ident created. Than either you messed
     *   with the ObjInfo above or KHE did. 
     */
    unsigned int setNumId(unsigned int newId) const{
        if(useBackPointerForNumIds)
            return bPSetNumId(newId);
        else{
            cachedId = newId;
            _isCached = true;

            Ident<T>::setKey(getId(), newId);
        }
    }

    virtual std::string getObjType() const = 0;
    virtual std::string getId() const = 0;
    
protected:
    mutable bool _isCached;
    mutable unsigned int cachedId;
    
    unsigned int generateCachedId(const std::string &id) const{
        cachedId = Ident<T>::getKey(id);
        _isCached = true;
        
        return cachedId;
    }
    
    /**
     * Note: you must manually deallocate the memory
     * otherwise, this _does_ leak memory. 
     * However, it is by default just one int per object. 
     */
    void initializeIfNull(T *obj) const{
        if(obj->getBack() == NULL){
            generateCachedId(obj->getId());
            //todo: deallocate memory
            KheObjInfo *info = new KheObjInfo();
            info->id = cachedId;
            obj->setBack(static_cast<void*>(info));
        }
    }
};

}

#endif	/* CACHEDOBJ_H */

