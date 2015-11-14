/* 
 * File:   LimitedTimeGroup.cpp
 * 
 */

#include "LimitedTimeGroup.h"
#include "TimeGroup.h"
#include "LimitedTimeGroup.h"
using namespace khe;

using ltg = LimitedTimeGroup;

ltg::LimitedTimeGroup(TimeGroup tg, int min, int max){
    ltg = KheLimitedTimeGroupMake(tg, min, max);
}

int ltg::getMinimum() const{
    return KheLimitedTimeGroupMinimum(ltg);
}

int ltg::getMaximum() const{
    return KheLimitedTimeGroupMaximum(ltg);
}

TimeGroup ltg::getTimeGroup() const{
    return KheLimitedTimeGroupTimeGroup(ltg);
}