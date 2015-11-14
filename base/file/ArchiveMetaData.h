/* 
 * File:   ArchiveMetaData.h
 * 
 */

#ifndef ARCHIVEMETADATA_H
#define	ARCHIVEMETADATA_H

extern "C" {
    #include "khe.h"
}

#include <string>

namespace khe{
    
class ArchiveMetaData {
    friend class Archive;
    
public:
    using KheType = KHE_ARCHIVE_METADATA;
    ArchiveMetaData();
    ArchiveMetaData(const std::string &name, const std::string &contributor, 
            const std::string &date, const std::string &desc, const std::string &remarks);
    ArchiveMetaData(const ArchiveMetaData& orig);
    ArchiveMetaData(KheType);
    
    std::string getName() const;
    std::string getContributor() const;
    std::string getDate() const;
    std::string getDesc() const;
    std::string getRemarks() const;
    
    
    operator KheType() const{
        return meta;
    }
protected:
    KheType meta;
    

};

}

#endif	/* ARCHIVEMETADATA_H */

