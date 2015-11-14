/* 
 * File:   IterAccessMapping.h
 */

#ifndef ITERACCESSMAPPING_H
#define	ITERACCESSMAPPING_H

namespace khe{   
    class Instance;
    class Time;
    class TimeGroup;
    class Archive;
    class Event;
    class EventGroup;
    class EventResource;
    class EventResourceGroup;
    class Resource;
    class ResourceGroup;
    class ResourceType;
    class SolutionGroup;
    class Constraint;
}

using namespace khe;

template <class ParentObj, class ChildObj> class IAM;

//Instance => *
template <> class IAM<Instance, Time>{ public:
    static constexpr auto accessFunc = &KheInstanceTime;
    static constexpr auto countFunc  = &KheInstanceTimeCount;
};

template <> class IAM<Instance, TimeGroup>{ public:
    static constexpr auto accessFunc = &KheInstanceTimeGroup;
    static constexpr auto countFunc  = &KheInstanceTimeGroupCount;
};

template <> class IAM<Instance, Archive>{ public:
    static constexpr auto accessFunc = &KheInstanceArchive;
    static constexpr auto countFunc  = &KheInstanceArchiveCount;
};

template <> class IAM<Instance, Event>{ public:
    static constexpr auto accessFunc = &KheInstanceEvent;
    static constexpr auto countFunc  = &KheInstanceEventCount;
};

template <> class IAM<Instance, EventGroup>{ public:
    static constexpr auto accessFunc = &KheInstanceEventGroup;
    static constexpr auto countFunc  = &KheInstanceEventGroupCount;
};

template <> class IAM<Instance, EventResource>{ public:
    static constexpr auto accessFunc = &KheInstanceEventResource;
    static constexpr auto countFunc  = &KheInstanceEventResourceCount;
};

template <> class IAM<Instance, Resource>{ public:
    static constexpr auto accessFunc = &KheInstanceResource;
    static constexpr auto countFunc  = &KheInstanceResourceCount;
};

template <> class IAM<Instance, ResourceType>{ public:
    static constexpr auto accessFunc = &KheInstanceResourceType;
    static constexpr auto countFunc  = &KheInstanceResourceTypeCount;
};

template <> class IAM<Instance, Constraint>{ public:
    static constexpr auto accessFunc = &KheInstanceConstraint;
    static constexpr auto countFunc  = &KheInstanceConstraintCount;
};




//Archive => * 
template <> class IAM<Archive, Instance>{ public:
    static constexpr auto accessFunc = &KheArchiveInstance;
    static constexpr auto countFunc  = &KheArchiveInstanceCount;
};

template <> class IAM<Archive, SolutionGroup>{ public:
    static constexpr auto accessFunc = &KheArchiveSolnGroup;
    static constexpr auto countFunc  = &KheArchiveSolnGroupCount;
};


// TimeGroup => 

template <> class IAM<TimeGroup, Time>{ public:
    static constexpr auto accessFunc = &KheTimeGroupTime;
    static constexpr auto countFunc  = &KheTimeGroupTimeCount;
};


//Resource =>
template <> class IAM<Resource, Event>{ public:
    static constexpr auto accessFunc = &KheResourceLayerEvent;
    static constexpr auto countFunc  = &KheResourceLayerEventCount;
};
template <> class IAM<Resource, EventResource>{ public:
    static constexpr auto accessFunc = &KheResourcePreassignedEventResource;
    static constexpr auto countFunc  = &KheResourcePreassignedEventResourceCount;
};

template <> class IAM<Resource, Constraint>{ public:
    static constexpr auto accessFunc = &KheResourceConstraint;
    static constexpr auto countFunc  = &KheResourceConstraintCount;
};


//ResourceType => 
template <> class IAM<ResourceType, ResourceGroup>{ public:
    static constexpr auto accessFunc = &KheResourceTypeResourceGroup;
    static constexpr auto countFunc  = &KheResourceTypeResourceGroupCount;
};

template <> class IAM<ResourceType, Resource>{ public:
    static constexpr auto accessFunc = &KheResourceTypeResource;
    static constexpr auto countFunc  = &KheResourceTypeResourceCount;
};


//Resource Group
template <> class IAM<ResourceGroup, Resource>{ public:
    static constexpr auto accessFunc = &KheResourceGroupResource;
    static constexpr auto countFunc  = &KheResourceGroupResourceCount;
};


//Event 
template <> class IAM<Event, EventResource>{ public:
    static constexpr auto accessFunc = &KheEventResource;
    static constexpr auto countFunc  = &KheEventResourceCount;
};

template <> class IAM<Event, EventResourceGroup>{ public:
    static constexpr auto accessFunc = &KheEventResourceGroup;
    static constexpr auto countFunc  = &KheEventResourceGroupCount;
};

template <> class IAM<Event, Constraint>{ public:
    static constexpr auto accessFunc = &KheEventConstraint;
    static constexpr auto countFunc  = &KheEventConstraintCount;
};

        

//EventGroup => *
template <> class IAM<EventGroup, Event>{ public:
    static constexpr auto accessFunc = &KheEventGroupEvent;
    static constexpr auto countFunc  = &KheEventGroupEventCount;
};

template <> class IAM<EventGroup, Constraint>{ public:
    static constexpr auto accessFunc = &KheEventGroupConstraint;
    static constexpr auto countFunc  = &KheEventGroupConstraintCount;
};



//EventResource => * 
template <> class IAM<EventResource, Constraint>{ public:
    static constexpr auto accessFunc = &KheEventResourceConstraint;
    static constexpr auto countFunc  = &KheEventResourceConstraintCount;
};


#endif	/* ITERACCESSMAPPING_H */

