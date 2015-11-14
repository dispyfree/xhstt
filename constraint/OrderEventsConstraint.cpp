/* 
 * File:   OrderEventsConstraint.cpp
 * 
 */

#include "OrderEventsConstraint.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "CostFunction.h"
#include "Event.h"
#include "Util.h"

using namespace khe;
using oec = OrderEventsConstraint;

oec::OrderEventsConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf){
    if(!KheOrderEventsConstraintMake(inst, Util::sTc(id), Util::sTc(name), required,
            weight, cf, &constr))
        throw ObjectCreation("Unable to create OrderEventsConstraint");
    
}
    
int oec::getEventPairCount() const{
    return KheOrderEventsConstraintEventPairCount(constr);
}

Event oec::getFirstEvent(int i) const{
    return KheOrderEventsConstraintFirstEvent(constr, i);
}

Event oec::getSecondEvent(int i) const{
    KheOrderEventsConstraintSecondEvent(constr, i);
}

int oec::getMinSeparation(int i) const{
    return KheOrderEventsConstraintMinSeparation(constr, i);
}

int oec::getMaxSeparation(int i) const{
    KheOrderEventsConstraintMaxSeparation(constr, i);
}

std::vector<std::tuple<Event, Event, int, int>> oec::getEventPairs() const{
    std::vector<std::tuple<Event, Event, int, int>> res;
    
    for(int i = 0; i != getEventPairCount(); i++){
        auto e1 = getFirstEvent(i);
        auto e2 = getSecondEvent(i);
        
        auto min = getMinSeparation(i);
        auto max = getMaxSeparation(i);
        
        res.push_back(std::make_tuple(e1, e2, min, max));
    }
    
    return res;
}

void OrderEventsConstraint::addPair(const Event &first, const Event &second, int minSep, int maxSep){
    KheOrderEventsConstraintAddEventPair(constr, first, second, minSep, maxSep);
}
