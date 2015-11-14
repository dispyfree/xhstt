/* 
 * File:   ArchiveMetaData.cpp
 * 
 */

#include <string>

#include "ArchiveMetaData.h"
#include "Util.h"

using namespace khe;

ArchiveMetaData::ArchiveMetaData(){
    meta = NULL;
}

ArchiveMetaData::ArchiveMetaData(const std::string &name, const std::string &contributor, 
        const std::string &date, const std::string &desc, const std::string &remarks) {
    meta = KheArchiveMetaDataMake(Util::sTc(name), 
            Util::sTc(contributor), Util::sTc(date), 
            Util::sTc(desc), Util::sTc(remarks));
}

ArchiveMetaData::ArchiveMetaData(KHE_ARCHIVE_METADATA meta){
    this->meta = meta;
}

ArchiveMetaData::ArchiveMetaData(const ArchiveMetaData& orig) {
    meta = orig.meta;
}

    
std::string ArchiveMetaData::getName() const{
    return std::string(KheArchiveMetaDataName(meta));
}

std::string ArchiveMetaData::getContributor() const{
    return std::string(KheArchiveMetaDataContributor(meta));
}

std::string ArchiveMetaData::getDate() const{
    return std::string(KheArchiveMetaDataDate(meta));
}

std::string ArchiveMetaData::getDesc() const{
    return std::string(KheArchiveMetaDataDescription(meta));
}

std::string ArchiveMetaData::getRemarks() const{
    return std::string(KheArchiveMetaDataRemarks(meta));
}
