/* 
 * File:   RequestedObjectNotFound.h
 * 
 */

#ifndef REQUESTEDOBJECTNOTFOUND_H
#define	REQUESTEDOBJECTNOTFOUND_H

#include <stdexcept>
namespace khe{

class RequestedObjectNotFound : public std::runtime_error{
public:
    RequestedObjectNotFound(const std::string &msg): std::runtime_error(msg){}
};

};

#endif	/* REQUESTEDOBJECTNOTFOUND_H */

