/* 
 * File:   TimeSpread.h
 * 
 */

#ifndef TIMESPREAD_H
#define	TIMESPREAD_H

#include "global.h"

namespace khe{

    class Instance;
    class LimitedTimeGroup;
    
    
class TimeSpread {
public:
    using KheType = KHE_TIME_SPREAD;
    
    TimeSpread(Instance inst);
    TimeSpread(KheType raw) : spread(raw) {Util::rnn(raw);}
    virtual ~TimeSpread(){}
    
    void add(const LimitedTimeGroup &ltg);
    std::vector<LimitedTimeGroup> getLimitedTimeGroups() const;
    
    bool isDisjoint(const TimeSpread &ts) const;
    bool coversWholeCycle(const TimeSpread &ts) const;
    
    operator KHE_TIME_SPREAD() const{
        return spread;
    }
    
protected:
    KheType spread;

};

}

#endif	/* TIMESPREAD_H */

