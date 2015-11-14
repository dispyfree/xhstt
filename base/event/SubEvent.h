/* 
 * File:   SubEvent.h
 * 
 * 
 * This class represents a SubEvent for the MIP model (or any other solver), NOT a SubEvent
 * for the XHSTT format. 
 * It does have a duration and links to an original Event. 
 * For the MIP solver, all SubEvents for a given Event are automatically generated. 
 */

#ifndef SUBEVENT_H
#define	SUBEVENT_H

#include "global.h"
#include "Event.h"

using namespace khe;


class SubEvent {
    using KheType = KHE_EVENT;
public:
    SubEvent(const Event &evt, int duration) : duration(duration), event(evt) {ownId = idCount++;}
    virtual ~SubEvent(){}
    
    
    /**
     * Creates the complete set of all SubEvents for the given event.
     * "complete" has the meaning in the header of this file
     * @param evt
     * @return 
     */
    static std::vector<SubEvent> splitEvent(const Event &evt, int maxSELength);
    
    int getDuration() const;
    Event getEvent() const;
    int getNumId() const;
    
    operator int() const;
    
    static void resetCounter();
    
protected:
    int duration;
    Event event;
    
    /**
     * we need to distinguish subevents even if they have the same duration!
     */
    static int idCount;
    int ownId;

};

#endif	/* SUBEVENT_H */

