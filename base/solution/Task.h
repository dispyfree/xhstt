/* 
 * File:   Task.h
 * 
 */

#ifndef TASK_H
#define	TASK_H

#include "global.h"

namespace khe{

    class Solution;
    class Resource;
    class ResourceType;
    class Meet;
    class EventResource;
    
class Task {
    using KheType = KHE_TASK;
public:

    Task(Solution &sol, ResourceType &rt, Meet &meet, EventResource &er);
    Task(KHE_TASK task) : task(task){ Util::rnn(task); }
    virtual ~Task(){}
    
    void setBack(void *back);
    void *getBack() const {
         return KheTaskBack(task);
    }
    
    bool isAssignedMeet() const;
    Meet getMeet() const;
    int getMeetIndex() const;
    int getDuration() const; 
    float getWorkload() const;
    
    Solution getSolution() const;
    int getSolutionIndex() const;
    ResourceType getResourceType() const;
    EventResource getEventResource() const;
    
    bool isCyclic() const;
    
    bool assignResourceCheck(const Resource &r) const;
    bool assignResource(const Resource &r);
    bool unAssignResourceCheck() const;
    bool unAssignResource();
    bool hasAssignedResource() const;
    Resource getAssignedResource() const;
    
    void remove();

    operator KheType() const{
        return task;
    }
    
protected:
    KheType task;
};

}

#endif	/* TASK_H */

