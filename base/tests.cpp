#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <iostream>

#include "Archive.h"

const std::string inputFile = "data/SpainSchool.xml";



inline bool exists(const std::string& name)
{
    return (std::ifstream(name));
}



TEST(HandleInstance, InstanceFileExists){
    EXPECT_TRUE(exists(inputFile));
}

TEST(HandleInstance, CanReadInstance){
    Archive arc(inputFile);
    Instance inst = arc.getInstance("ES-SS-08");
    EXPECT_EQ(inst.getId(), "ES-SS-08");
    
    auto meta = inst.getMeta();
    EXPECT_EQ("Spanish school", meta.getName());
    EXPECT_EQ(meta.getDate(), "March 7, 2012");
    
    //Test iterator (will throw exception on failure)
    for(auto t: inst.getTimes())
        t.getId();
}

TEST(HandleInstance, CanWriteInstance){
    InstanceMetaData meta("testInst");
    Instance inst("testInstance", meta);
    
    Time time1(inst, "Time1", "Time1", false);
    Time time2(inst, "Time2", "Time2", false);
    
    ResourceType resType(inst, "resT", "restT");
    Resource t(resType, "res1", "res1");
    
    inst.end(false);
    
    Archive arc("archiveID", ArchiveMetaData());
    arc.add(inst);
    
    FILE *f = fopen("data/testWriteOut", "w");
    arc.write(false, f);
}
