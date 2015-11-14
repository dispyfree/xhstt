/* 
 * File:   ObjectCreation.h
 * 
 */

#ifndef OBJECTCREATION_H
#define	OBJECTCREATION_H
#include <stdexcept>

namespace khe{

class ObjectCreation : public std::runtime_error{
public:
    ObjectCreation(const std::string &msg): std::runtime_error(msg){}
    ObjectCreation(const ObjectCreation& orig);
};

};


#endif	/* OBJECTCREATION_H */

