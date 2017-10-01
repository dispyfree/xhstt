/* 
 * File:   TimeGroup.h
 * 
 */

#ifndef TIMEGROUP_H
#define	TIMEGROUP_H

#include <vector>
#include "Time.h"
#include "CachedObj.h"
#include "khe.h"

namespace khe{

    class Instance;
    class TimeGroup;
    class TimeGroupKind;
    
class TimeGroup : CachedObj<TimeGroup>{
public:
    
    using KheType = KHE_TIME_GROUP;
    
    enum Kind{
        Ordinary    = KHE_TIME_GROUP_KIND_ORDINARY,
        Weekly      = KHE_TIME_GROUP_KIND_WEEK,
        Daily       = KHE_TIME_GROUP_KIND_DAY,
        //commented out in KHE, author did not give reasoning
        /*Predefined  = KHE_TIME_GROUP_KIND_PREDEFINED*/
    };


    TimeGroup(Instance &inst, Kind kind, const std::string &id, const std::string &name);
    TimeGroup(KheType);
    
    std::string getObjType() const;
    
    
    /**
     * Miscellaneous and ubiquitous methods
     */
    void debug(int verbosity, int indent, std::string file);
    void setBack(void *back);
    void *getBack() const {
         return KheTimeGroupBack(grp);
    }
    
    
    Instance getInstance() const;
    TimeGroup::Kind getKind() const;
    virtual std::string getId() const;
    std::string getName() const;
    
    
    /**
     * time related functionality
     */
    void add(Time &t);
    void sub(Time &t);
    //Note that union is a protected keyword in C++
    void doUnion(TimeGroup &tg2);
    void intersect(TimeGroup &tg2);
    void difference(TimeGroup &tg2);
    
    IR<Time> getTimes() const;
    
    bool contains(const Time &t);
    bool equals(const TimeGroup &tg2);
    bool isSubsetOf(const TimeGroup &tg2);
    bool isDisjoint(const TimeGroup &tg2);
    bool isCompact();
    bool overlaps(const Time &t, int duration);
    TimeGroup neighbour(int delta);
    
    bool operator==(const TimeGroup &tg2) const;
    bool operator <(const TimeGroup &tg2) const;
    
    operator int() const;
    operator KheType() const;
    
protected:
    KheType grp;
    

};
}

#endif	/* TIMEGROUP_H */


