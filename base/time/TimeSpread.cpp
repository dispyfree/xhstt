/* 
 * File:   TimeSpread.cpp
 * 
 */

#include "TimeSpread.h"
#include "Instance.h"
#include "LimitedTimeGroup.h"

using namespace khe;

TimeSpread::TimeSpread(Instance inst){
    spread = KheTimeSpreadMake(inst);
}


void TimeSpread::add(const LimitedTimeGroup &ltg){
    KheTimeSpreadAddLimitedTimeGroup(spread, ltg);
}

std::vector<LimitedTimeGroup> TimeSpread::getLimitedTimeGroups() const{
    return Util::toArray<LimitedTimeGroup>(&KheTimeSpreadLimitedTimeGroup,
            spread, KheTimeSpreadLimitedTimeGroupCount(spread));
}


