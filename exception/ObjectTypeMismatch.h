/* 
 * File:   ObjectTypeMismatch.h
 * 
 */

#ifndef OBJECTTYPEMISMATCH_H
#define	OBJECTTYPEMISMATCH_H

#include <stdexcept>

namespace khe{
    
template <class K> class ObjectTypeMismatch : public std::runtime_error {
public:
    ObjectTypeMismatch(const std::string &msg, const K &obj): 
        std::runtime_error(msg), perpetrator(obj){}
    
    K perpetrator;

};

}
#endif	/* OBJECTTYPEMISMATCH_H */

