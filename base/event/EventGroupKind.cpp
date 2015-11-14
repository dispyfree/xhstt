/* 
 * File:   EventGroupKind.cpp
 * 
 */

#include "EventGroupKind.h"
#include "Util.h"
using namespace khe;

using egk = EventGroupKind;

egk::EventGroupKind() {
}

egk::EventGroupKind(KHE_EVENT_GROUP_KIND raw){
    kind = raw;
}

egk::~EventGroupKind() {
}

