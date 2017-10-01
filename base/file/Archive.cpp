/* 
 * File:   Archive.cpp
 * 
 */

#include <string>

#include "Archive.h"
#include "ArchiveMetaData.h"
#include "RequestedObjectNotFound.h"
#include "Instance.h"
#include "SolutionGroup.h"
#include "ObjectCreation.h"

#include <stdio.h>
#include <stdexcept>

using namespace khe;

Archive::Archive(const std::string &path){
    FILE *fp;
    fp = fopen(path.c_str(), "r");
    if(!fp)
        throw std::runtime_error("Unable to open archive file");
    
    KML_ERROR ke;
    /**
     * Feel free to change the code in order to exploit additional information
     * from KML_ERROR
     */
    if(!KheArchiveRead(fp, &archive, &ke, false, false, NULL, NULL, NULL)){
        std::string err(KmlErrorString(ke));
        throw ObjectCreation(std::string("Unable to read archive file due to KHE internal error : ")
                + err);
    }
    
    fclose(fp);
}

Archive::Archive(std::ifstream &is){
    //extract length and read string
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);
    
    char *buffer = new char [length];
    is.read (buffer,length);
    
    if(!is)
        throw std::runtime_error("Unable to read archive file, invalid stream");
    is.close();
    
    KML_ERROR ke;
    /**
     * Feel free to change the code in order to exploit additional information
     * from KML_ERROR
     */
    if(!KheArchiveReadFromString(buffer, &archive,
            &ke, false, false))
        throw ObjectCreation("Unable to read archive file due to KHE internal error");

    delete[] buffer;
}

Archive::Archive(const std::string &id, ArchiveMetaData data) {
    archive = KheArchiveMake(Util::sTc(id.c_str()), data);
}

Archive::Archive(const Archive& orig) {
    archive = orig.archive;
}

Archive::Archive(KHE_ARCHIVE arc){
    Util::rnn(arc);
    archive = arc;
}

std::string Archive::getId() const{
    return KheArchiveId(archive);
}

ArchiveMetaData Archive::getMeta() const{
    return ArchiveMetaData(KheArchiveMetaData(archive));
}
    
void Archive::setBack(void *back){
    KheArchiveSetBack(archive, back);
}

bool Archive::add(const Instance &inst){
    return KheArchiveAddInstance(archive, inst);
}

void Archive::remove(const Instance &inst){
    KheArchiveDeleteInstance(archive, inst);
}

Instance Archive::getInstance(const std::string &id) const{
    KHE_INSTANCE inst;
    if(!KheArchiveRetrieveInstance(archive, Util::sTc(id), &inst))
        throw RequestedObjectNotFound("Instance not found");
    
    return inst;
}

IR<Instance> Archive::getInstances() const{
    return createIter<Instance>(*this);
}

SolutionGroup Archive::getSolutionGroup(const std::string &id) const{
     KHE_SOLN_GROUP grp;
    if(!KheArchiveRetrieveSolnGroup(archive, Util::sTc(id), &grp))
        throw RequestedObjectNotFound("SolutionGroup not found");
    
    return grp;
}

IR<SolutionGroup> Archive::getSolutionGroups() const{
    return createIter<SolutionGroup>(*this);
}

void Archive::write(bool with_reports, FILE *fp) const{
    KheArchiveWrite(archive, with_reports, fp);
}

void Archive::write(const SolutionGroup &grp, bool with_reports, FILE *fp) const{
    KheArchiveWriteSolnGroup(archive, grp, with_reports, fp);
}
