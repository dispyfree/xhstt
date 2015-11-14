/* 
 * File:   Dummy.h
 *
 */

#ifndef POSSIBLEDUMMY_H
#define	POSSIBLEDUMMY_H

#include <string>

namespace khe{
    
class PossibleDummy {
public:
    PossibleDummy(bool isDummy = false) : _isDummy(isDummy){};
    
    bool isDummy() const{
        return _isDummy;
    }

protected:
    bool _isDummy;

};

}

#endif	/* POSSIBLEDUMMY_H */

