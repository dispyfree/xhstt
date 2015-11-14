/* 
 * File:   Cost.cpp
 * 
 */

#include "Cost.h"
using namespace khe;

Cost::Cost() {
}

Cost::Cost(const Cost& orig) {
    this->cost = orig.cost;
}

Cost::Cost(KHE_COST cost){
    this->cost = cost;
}


