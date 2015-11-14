/* 
 * File:   SolutionGroup.cpp
 * 
 */

#include "SolutionGroup.h"
#include "Archive.h"
#include "SolutionGroupMetaData.h"
#include "ObjectCreation.h"
#include "Solution.h"

using namespace khe;

using sg = SolutionGroup;

sg::SolutionGroup(Archive &arch, const std::string &id, 
            SolutionGroupMetaData meta){
    if(!KheSolnGroupMake(arch, Util::sTc(id), meta, &grp))
        throw ObjectCreation("Unable to create SolutionGroup");
}
    
void sg::setBack(void *back){
    KheSolnGroupSetBack(grp, back);
}

Archive sg::getArchive() const{
    return KheSolnGroupArchive(grp);
}

std::string sg::getId() const{
    return KheSolnGroupId(grp);
}

SolutionGroupMetaData sg::getMeta() const{
    return KheSolnGroupMetaData(grp);
}

void sg::add(const Solution &sol){
    KheSolnGroupAddSoln(grp, sol);
}

void sg::remove(const Solution &sol){
   KheSolnGroupDeleteSoln(grp, sol); 
}

std::vector<Solution> sg::getSolutions() const{
    return Util::toArray<Solution>(&KheSolnGroupSoln, grp, KheSolnGroupSolnCount(grp));
}

