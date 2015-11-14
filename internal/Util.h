/* 
 * File:   Util.h
 * 
 */

#ifndef UTIL_H
#define	UTIL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "ObjNotFound.h"
#include "ObjectCreation.h"

namespace khe{
    
 class Util{
 public:
     static char* cc(const std::string &str){
         return const_cast<char*>(str.c_str());
     }
     
     /**
      * Calls the given function with indices from {0, ..., n-1} 
      * and collects the returned values in a vector which is the result
      * R => return class, tmp => tmp result of the KHE callback
      * struc => type the callback expects
      * @param the iterator function (i.e. KheInstanceTimeGroup)
      * @param n the delimiter
      * @return 
      */
     template <class R, class tmp,  class struc> static std::vector<R> toArray(
        tmp (*func)(struc, int), struc obj, int n){
         std::vector<R> vec;
         
         for(int i = 0; i != n; i++){
             tmp ret = (*func)(obj, i) ;
              if(ret == NULL)
                  throw ObjNotFound(std::string("ran into nullptr"));
             R tmp = static_cast<R>(ret);
             vec.push_back(tmp);
         }
         
         return std::move(vec);
     }
     
     /**
      * Specialization allowing for another class parameter parameter to be passed
      * necessary for the implementation of: 
      * 
      * KheAvoidSplitAssignmentsConstraintEventResource (here struc2 = int)
      * KHE_MEET KheEventMeet(KHE_SOLN soln, KHE_EVENT e, int i);
      */
     
     template <class R, class tmp,  class struc, class struc2> static std::vector<R> toArray2(
        tmp (*func)(struc, struc2, int), struc obj, struc2 obj2, int n){
         std::vector<R> vec;
         
         for(int i = 0; i != n; i++){
             tmp ret = (*func)(obj, obj2, i) ;
             if(ret == NULL)
                  throw ObjNotFound(std::string("ran into nullptr"));
             
             vec.push_back(R(ret));
         }
         
         return std::move(vec);
     }
     
     
     /**
      * Retrieves an object given by the ID
      * @param obj  the parent object, i.e. an instance
      * @param func the KHE function retrieving the underlying structures
      * @param id   the unique identifier
      * @return returns the OOP style object or throws an exception if the id is invalid
      */
     template <class R, class Tmp, class T, class ID> static R retrieve(T obj, 
        bool (*func)(T, ID id, Tmp*), ID id){
         Tmp tmpObj;
         bool success = (*func)(obj, id, &tmpObj);
         
         if(!success)
             throw ObjNotFound(std::string("unable to retrieve object"));
         
         return R(tmpObj);
     }
     
     /**
      * Specialization allowing strings
      */
     template <class R, class Tmp, class T> static R retrieve(T obj, 
        bool (*func)(T, char *id, Tmp*), const std::string &id){
         return retrieve<R, Tmp, T>(obj, func, sTc(id));
     }
     
     /**
      * StringToChar converts a c++ style string to a C style char
      * or returns NULL if the string is empty
      * this is useful if you do not want to specify a string for i.e.
      * KHE[...]Make(... , char *id)
      * An empty string will still be a string, while NULL is the proper way to 
      * denote that you do not wish to set the id.
      * 
      * The vector is needed to store strings as they may be deallocated later on
      * before KHE gets to write out to a file 
      * @param str
      * @return 
      */
     static std::list<std::string> strs;
     static char *sTc(const std::string &str);
     
     /**
      * rnn = requireNotNull
      * will throw exception if given poitner is null reference
      * 
      * This can be used to ensure that KHE objects are not instantiated on null
      * pointers (after the constructor finished, it is assumed that a valid 
      * object is referenced. However, KHE functions exhibit undefined behavior
      * for null functions.)
      */
     template <class T> static void rnn(T* ptr){
         if(ptr == NULL || ptr == 0)
             throw ObjectCreation("Cannot instantiate KHE instance on null pointer");
         
     }
 };  
};


#endif	/* UTIL_H */

