/* 
 * File:   Cost.h
 * 
 */

#ifndef COST_H
#define	COST_H

#include "global.h"

namespace khe{ 
    
class Cost {
public:
    Cost();
    Cost(const Cost& orig);
    Cost(KHE_COST cost);
    
    operator KHE_COST() const{
        return cost;
    }
    
    
protected:
    KHE_COST cost;

};

}

#endif	/* COST_H */

