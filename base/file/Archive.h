/* 
 * File:   Archive.h
 *
 * This class represents one archive, that is, a collection of instances plus a collection
 * of solution groups.
 */

#ifndef ARCHIVE_H
#define	ARCHIVE_H

extern "C"{
    #include "khe.h"
}

#include "ArchiveMetaData.h"
#include "Instance.h"
#include <fstream>

namespace khe{
    
    class SolutionGroup;
    
class Archive {
public:
    using KheType = KHE_ARCHIVE;
    
    Archive(std::ifstream &in);
    Archive(const std::string &path);
    Archive(const std::string &id, ArchiveMetaData data);
    Archive(const Archive& orig);
    Archive(KHE_ARCHIVE arc);
    
    std::string getId() const;
    ArchiveMetaData getMeta() const;
    
    bool add(const Instance &inst);
    void remove(const Instance &inst);
    
    void write(bool with_reports, FILE *fp) const;
    void write(const SolutionGroup &grp, bool with_reports, FILE *fp) const;
    
    Instance getInstance(const std::string &id) const;
    IR<Instance> getInstances() const;
    SolutionGroup getSolutionGroup(const std::string &id) const;
    IR<SolutionGroup> getSolutionGroups() const;
    
    
    void setBack(void *back);
    void *getBack() const {
         return KheArchiveBack(archive);
    }
     
    operator KheType() const{
        return archive;
    }
    
protected:
    KheType archive;

};

}

#endif	/* ARCHIVE_H */

