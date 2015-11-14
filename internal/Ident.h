/* 
 * File:   Ident.h
 * 
 */

#ifndef IDENT_H
#define	IDENT_H

#include "global.h"
#include <unordered_map>

namespace khe{

/**
 * Using the dummy template parameter T we simply count each object
 * type instead of all object types at once.
 * This decreases the IDs generally; as we do only compare objects of two equal
 * types, this does work (Note: all constraints are considered to be of type 
 * "Constraint" in this case)
 * 
 * Please note that as Ident is a template class, by definition of static member
 * variables there's _no_ need for definition (memory allocation) in a 
 * translation unit. For an in-depth analysis, we refer to 
 * http://stackoverflow.com/questions/1553854/template-static-variable
 */
using mapType = std::unordered_map<std::string, unsigned int>;
    
    
template <class T> class Ident {
public:
    
    
    static unsigned int getKey(const std::string &str){
        auto iter = entries.find(str);

        if(iter == entries.end()){
            unsigned int newID = counter++;
            entries.insert(std::make_pair(str, newID));
            return newID;
        }

        return iter->second;
    }
    
    static void setKey(const std::string &strId, unsigned int key){
        auto res = entries.find(strId);
        if(res != entries.end() && res->second != key)
            throw std::runtime_error("Trying to reassign another numIdKey; this may be dangerous");
        
        entries.insert(std::make_pair(strId, key));
    }
    
    static void resetCounter(){
        counter = 0;
    }
    
protected:
    static std::unordered_map<std::string, unsigned int> entries;
    static unsigned int counter;

};

template <class T> mapType Ident<T>::entries = mapType(1);
/**
 * @see resetCounter
 */
template <class T> unsigned int Ident<T>::counter = 0;

}


#endif	/* IDENT_H */

