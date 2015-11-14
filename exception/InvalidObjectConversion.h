/* 
 * File:   InvalidObjectConversion.h
 * 
 */

#ifndef INVALIDOBJECTCONVERSION_H
#define	INVALIDOBJECTCONVERSION_H

#include <stdexcept>

namespace khe{
class InvalidObjectConversion : public std::runtime_error{
public:
    InvalidObjectConversion(const std::string &msg): std::runtime_error(msg){}
    virtual ~InvalidObjectConversion(){}
private:

};

}

#endif	/* INVALIDOBJECTCONVERSION_H */

