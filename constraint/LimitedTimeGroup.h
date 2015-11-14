/* 
 * File:   LimitedTimeGroup.h
 * 
 */

#ifndef LIMITEDTIMEGROUP_H
#define	LIMITEDTIMEGROUP_H

#include "global.h"

namespace khe{
    
    class TimeGroup;
class LimitedTimeGroup {
public:
    using KheType = KHE_LIMITED_TIME_GROUP;
    
    LimitedTimeGroup(TimeGroup, int min, int max);
    LimitedTimeGroup(KheType raw): ltg(raw) {Util::rnn(raw);}
    virtual ~LimitedTimeGroup(){}
    
    int getMinimum() const;
    int getMaximum() const;
    TimeGroup getTimeGroup() const;
   
    operator KheType() const{
        return ltg;
    }
    
    
protected:
    KheType ltg;

};

}

#endif	/* LIMITEDTIMEGROUP_H */

