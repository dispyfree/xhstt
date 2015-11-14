/* 
 * File:   OrderEventsConstraint.h
 * 
 */

#ifndef ORDEREVENTSCONSTRAINT_H
#define	ORDEREVENTSCONSTRAINT_H

#include "Constraint.h"

#include <tuple>

namespace khe{
    
    class Instance;
    class CostFunction;
    class Event;
    
class OrderEventsConstraint : public Constraint{
public:
    using KheType           = KHE_ORDER_EVENTS_CONSTRAINT;
    const static Tag tag    = OrderEvents;
    
    OrderEventsConstraint(Instance &inst, const std::string &id, const std::string &name,
            bool required, int weight, const CostFunction &cf);
    OrderEventsConstraint(KheType raw) : Constraint(raw), constr(raw){Util::rnn(raw);}
    virtual ~OrderEventsConstraint(){}
    
    int getEventPairCount() const;
    /**
     * structure: firstEvent, secondEvent, minSeparation, maxSeparation
     */
    std::vector<std::tuple<Event, Event, int, int>> getEventPairs() const;
    void addPair(const Event &first, const Event &second, int minSep, int maxSep);
    Event getFirstEvent(int i) const;
    Event getSecondEvent(int i) const;
    int getMinSeparation(int i) const;
    int getMaxSeparation(int i) const;

    operator KheType() const{
        return constr;
    }
    
    bool operator< (const OrderEventsConstraint &c2) const{
        return getId() < c2.getId();
    }
    
protected:
    KheType constr;

};

}

#endif	/* ORDEREVENTSCONSTRAINT_H */

