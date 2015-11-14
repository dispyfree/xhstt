/* 
 * File:   Meet.h
 * 
 */

#ifndef MEET_H
#define	MEET_H

#include "global.h"
#include <cstdio>

namespace khe{
    class Solution;
    class Event;
    class Task;
    class Time;
    class EventResource;
    class Resource;
    
class Meet {
    using KheType = KHE_MEET;
public:
    Meet(Solution &sol, int duration, Event &evt);
    Meet(Solution &sol, int duration);
    Meet(KHE_MEET pmeet) : meet(pmeet){Util::rnn(this->meet);}
    virtual ~Meet(){}
    
    void setBack(void *back);
    void *getBack() const {
         return KheMeetBack(meet);
    }

    Solution getSolution() const;
    int getSolutionIndex() const;
    int getDuration() const;
    
    /**
     * Splits this meet into two meetings meet1 and meet2 such that
     * meet1.duration = duration and meet2.duration = meet - meet2.duration
     * Please note: If the split was successful, THIS OBJECT ITSELF IS NOT
     * DEFINED ANYMORE. THEREFORE, ANY OPERATIONS AFTERWARDS WILL YIELD 
     * UNDEFINED BEHAVIOR. 
     *  
     * @param duration
     * @param recursive whether to also split attached meets
     */
    std::pair<Meet, Meet> split(int duration, bool recursive);
    
    bool hasAssignedEvent() const;
    Event getEvent() const;
    
    bool hasPreassignedTime() const;
    Time getPreassignedtime() const;
    Time getAssignedTime() const;
    bool moveTime(const Time &time);
    bool assignTime(const Time &time);
    bool unaAssignTime();
    
    std::vector<Task> getTasks() const;
    Task getTask(const std::string &role) const;
    Task findTask(const EventResource &er) const;
    
    bool preassignsResource(const Resource &r) const;
    bool assignsResource(const Resource &r) const;
    
    bool assignCheck(const Meet &target, int offset) const;
    bool assign(const Meet &target, int offset);
    bool unassignCheck() const;
    bool unassign();
    bool hasAssignment() const;
    Meet getAssignment() const;
    int getOffset() const;
    
    bool isCyclic() const;

    void remove();
    
    void debug( int verbosity, int indent, FILE *fp) const;

    operator KheType() const{
        return meet;
    }
    
protected:
    KheType meet;

};

}
#endif	/* MEET_H */

