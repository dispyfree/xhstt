/* 
 * File:   ObjNotFound.h
 * 
 */

#ifndef OBJNOTFOUND_H
#define	OBJNOTFOUND_H

#include <stdexcept>

namespace khe{

class ObjNotFound : public std::runtime_error{
public:
    ObjNotFound(const std::string &msg): std::runtime_error(msg){}
};

};

#endif	/* OBJNOTFOUND_H */

