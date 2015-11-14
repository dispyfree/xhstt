/* 
 * File:   Time.cpp
 * 
 */

#include "Time.h"
#include "TimeGroup.h"
#include "ObjectCreation.h"
#include "Instance.h"
#include "Ident.h"
#include <string>
#include <map>
using namespace khe;

int Time::dummyId = -1;

Time::Time(Instance inst, std::string id, std::string name, bool breakAfter){
    if(!KheTimeMake(inst, Util::sTc(id), Util::sTc(name), breakAfter, &t))
        throw ObjectCreation("Unable to create Time");
}

Time::Time(KHE_TIME t){
    Util::rnn(t);
    this->t = t;
}


void Time::setBack(void *back){
    KheTimeSetBack(t, back);
}

std::string Time::getId() const{
    if(isDummy())
        return "TimeDummy";
    return std::string(KheTimeId(t));
}

std::string Time::getName() const{
    return std::string(KheTimeName(t));
}
    
bool Time::breakAfter() const{
    return KheTimeBreakAfter(t);
}

int Time::index() const{
    if(isDummy())
        return dummyId;
    return KheTimeIndex(t);
}

bool Time::hasNeighbour(int delta) const{
    return KheTimeHasNeighbour(t, delta);
}

Time Time::getNeighbour(int delta) const{
    return KheTimeNeighbour(t, delta);
}

    
bool Time::le(int delta1, Time t2, int delta2) const{
    return KheTimeLE(t, delta1, t2, delta2);
}

bool Time::lt(int delta1, Time t2, int delta2) const{
    return KheTimeLT(t, delta1, t2, delta2);
}

bool Time::gt(int delta1, Time t2, int delta2) const{
    return KheTimeGT(t, delta1, t2, delta2);
}

bool Time::ge(int delta1, Time t2, int delta2) const{
    return KheTimeGE(t, delta1, t2, delta2);
}

bool Time::eq(int delta1, Time t2, int delta2) const{
    return KheTimeEQ(t, delta1, t2, delta2);
}

bool Time::ne(int delta1, Time t2, int delta2) const{
    return KheTimeNE(t, delta1, t2, delta2);
}

    
int Time::intervalsOverlap(int durn1, Time t2, int durn2) const{
    return KheTimeIntervalsOverlap(t, durn1, t2, durn2);
}

std::pair<Time, int> Time::getIntervalsOverlap(int durn1, Time t2, int durn2) const{
    KHE_TIME t_tmp;
    int res;
    
    if(!KheTimeIntervalsOverlapInterval(t, durn1, t2, durn2, &t_tmp, &res))
        //will throw exception
        return std::make_pair(Time(NULL), 0);
    return std::make_pair(t_tmp, res);
}
    
TimeGroup Time::getSintletonTimeGroup() const{
    return KheTimeSingletonTimeGroup(t);
}

bool Time::operator==(const Time &t2) const{
        return index() == t2.index();
}

bool Time::operator!=(const Time &t2) const{
    return index() != t2.index();
}

bool Time::operator<(const Time &t2) const{
    return index() < t2.index();
}

Time::operator int() const{
    return index();
}

Time::operator std::string() const{
    return getId();          
}

Time::operator KHE_TIME() const{
    if(isDummy())
        throw ObjectCreation("Tried to convert dummy obj to KHE");
    return t;
}

void Time::setDummyId(int id){
    dummyId = id;
}

Time Time::getDummy(){
        return Time();
}



