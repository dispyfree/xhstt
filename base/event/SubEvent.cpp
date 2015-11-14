/* 
 * File:   SubEvent.cpp
 * 
 */

#include "SubEvent.h"
#include "Event.h"
#include <math.h>
#include <iostream>

/**
 * @see resetCounter
 */
int SubEvent::idCount = 0;

void SubEvent::resetCounter(){
    idCount = 0;
}

std::vector<SubEvent> SubEvent::splitEvent(const Event &evt, int maxSELength){
    std::vector<SubEvent> res;
    
    /**
     * The duration of all sub events' sum is given by:
     * sum_{i=1}^{D_l} floor( \frac{D_l}{i})
     * 
     * Therefore for D_l = 4, we have
     * 4 x 1, 2 x 2, 1 x 3 and 1 x 4      (num x duration)
     * 
     */
    int D_l = evt.getDuration();
    for(int i = 1; i <= D_l && i <= maxSELength; i++){
        int num = floor(static_cast<double>(D_l)/i);
        
        //Create num subevents of duration i
        for(int j = 1; j <= num; j++)
            res.push_back(SubEvent(evt, i));
    }
    
    return res;
}

int SubEvent::getDuration() const{
    return duration;
}

Event SubEvent::getEvent() const {
    return event;
}

int SubEvent::getNumId() const{
    return ownId;
}

SubEvent::operator int() const{
    return ownId;
}
