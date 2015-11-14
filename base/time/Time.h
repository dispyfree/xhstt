/* 
 * File:   Time.h
 * 
 */

#ifndef TIME_H
#define	TIME_H

#include "global.h"
#include "PossibleDummy.h"
#include "ObjectCreation.h"

#include <string>
#include <utility>

namespace khe{

    class Instance;
    class TimeGroup;
class Time : public PossibleDummy{
public:
    using KheType = KHE_TIME;
    
    Time(Instance inst, std::string id, std::string name, bool breakAfter);
    Time(KheType t);
    
    friend class ModelInitalizer;
    
    std::string getObjType() const {return "Time"; }
    
    /**
     * Miscellaneous and ubiquitous methods
     */
    void setBack(void *back);
    void *getBack() const {
         return KheTimeBack(t);
    }
    
    std::string getId() const;
    std::string getName() const;
    
    bool breakAfter() const;
    int index() const;
    bool hasNeighbour(int delta) const;
    Time getNeighbour(int delta) const;
    
    bool le(int delta1, Time t2, int delta2) const;
    bool lt(int delta1, Time t2, int delta2) const;
    bool gt(int delta1, Time t2, int delta2) const;
    bool ge(int delta1, Time t2, int delta2) const;
    bool eq(int delta1, Time t2, int delta2) const;
    bool ne(int delta1, Time t2, int delta2) const;
    
    int intervalsOverlap(int durn1, Time t2, int durn2) const;
    
    /**
     * Will return (NULL, 0) if KheTimeIntervalsOverlapInterval returns false
     * @param durn1
     * @param t2
     * @param durn2
     * @return 
     */
    std::pair<Time, int> getIntervalsOverlap(int durn1, Time t2, int durn2) const;
    
    TimeGroup getSintletonTimeGroup() const;
    
    static Time getDummy();
    
    bool operator==(const Time &t2) const;
    bool operator!=(const Time &t2) const;
    bool operator<(const Time &t2) const;
    
    operator int() const;
    operator std::string() const;
    operator KheType() const;
    
    //Used to instantiate dummies
    explicit Time(): PossibleDummy(true), t(NULL) {};
    
    static void setDummyId(int id);
    
protected:
    KheType t;
    
    static int dummyId;

};

}

#endif	/* TIME_H */

