/* 
 * File:   EventGroupKind.h
 * 
 */

#ifndef EVENTGROUPKIND_H
#define	EVENTGROUPKIND_H

#include "global.h"

namespace khe{
    
class EventGroupKind {
public:
    using KheType = KHE_EVENT_GROUP_KIND;
    EventGroupKind();
    EventGroupKind(KheType kind);
    virtual ~EventGroupKind();
    
    static EventGroupKind getOrdinary(){
        return EventGroupKind(KHE_EVENT_GROUP_KIND_ORDINARY);
    }
    
    static EventGroupKind getCourse(){
        return EventGroupKind(KHE_EVENT_GROUP_KIND_COURSE);
    }
    
    operator KheType() const{
        return kind;
    }
    
    bool operator==(const EventGroupKind &egk2) const{
        return kind == egk2.kind;
    }
    
    bool operator<(const EventGroupKind &egk2) const{
        return kind < egk2.kind;
    }
    
protected:
    KheType kind;

};

}

#endif	/* EVENTGROUPKIND_H */

