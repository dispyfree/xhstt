/* 
 * File:   Task.cpp
 * 
 */

#include "Task.h"
#include "RequestedObjectNotFound.h"
#include "Solution.h"
#include "ResourceType.h"
#include "Meet.h"
#include "EventResource.h"
using namespace khe;

Task::Task(Solution &sol, ResourceType &rt, Meet &meet, EventResource &er){
    task = KheTaskMake(sol, rt, meet, er);
}

void Task::setBack(void *back){
    KheTaskSetBack(task, back);
}


bool Task::isAssignedMeet() const{
    return KheTaskMeet(task) != NULL;
}
Meet Task::getMeet() const{
    KHE_MEET meet = KheTaskMeet(task);
    
    if(meet == NULL)
        throw RequestedObjectNotFound("The task is not assigned a meet");
    return meet;
}

int Task::getMeetIndex() const{
    KHE_MEET meet = KheTaskMeet(task);
    
    if(meet == NULL)
        throw RequestedObjectNotFound("The task is not assigned a meet");
    return KheTaskMeetIndex(task);
}

int Task::getDuration() const{
    int dur = KheTaskDuration(task);
    
    if(dur == 0)
        throw RequestedObjectNotFound("The task is not assigned a meet");
    return dur;
}

float Task::getWorkload() const{
    int workload = KheTaskWorkload(task);
    
    if(workload == 0)
        throw RequestedObjectNotFound("The task is not assigned a meet");
    return workload;
}

Solution Task::getSolution() const{
    return  KheTaskSoln(task);
}

int Task::getSolutionIndex() const{
    return KheTaskSolnIndex(task);
}

ResourceType Task::getResourceType() const{
    return KheTaskResourceType(task);
}

EventResource Task::getEventResource() const{
    KHE_EVENT_RESOURCE res = KheTaskEventResource(task);
    
    if(res == NULL)
        throw RequestedObjectNotFound("The task is not assigned an event resource");
    return res;
}

bool Task::isCyclic() const{
    return KheTaskIsCycleTask(task);
}

bool Task::assignResourceCheck(const Resource &r) const{
    return KheTaskAssignResourceCheck(task, r);
}

bool Task::assignResource(const Resource &r){
    return KheTaskAssignResource(task, r);
}

bool Task::unAssignResourceCheck() const{
    return KheTaskUnAssignResourceCheck(task);
}

bool Task::unAssignResource(){
    return KheTaskUnAssignResource(task);
}


bool Task::hasAssignedResource() const{
    return KheTaskAsstResource(task) != NULL;
}

Resource Task::getAssignedResource() const{
    KHE_RESOURCE res = KheTaskAsstResource(task);
    
    if(res == NULL)
        throw RequestedObjectNotFound("The task is not assigned a resource");
    return res;
}
    
void Task::remove(){
    KheTaskDelete(task);
}



