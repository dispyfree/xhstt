/* 
 * File:   InstanceMetaData.cpp
 * 
 */

#include "InstanceMetaData.h"
using namespace khe;

InstanceMetaData::InstanceMetaData(const std::string &name, const std::string &contributor, 
        const std::string &date, const std::string &country, const std::string &desc,
        const std::string &remarks){
    meta = KheInstanceMetaDataMake(Util::sTc(name), Util::sTc(contributor), 
            Util::sTc(date), Util::sTc(country), Util::sTc(desc), Util::sTc(remarks));
}

InstanceMetaData::InstanceMetaData(KHE_INSTANCE_METADATA meta){
    this->meta = meta;
}
InstanceMetaData::InstanceMetaData(const InstanceMetaData& orig) {
    meta = orig.meta;
}

InstanceMetaData::~InstanceMetaData() {
}

std::string InstanceMetaData::getName() const{
    return std::string(KheInstanceMetaDataName(meta));
}

std::string InstanceMetaData::getContributor() const{
    return std::string(KheInstanceMetaDataContributor(meta));
}

std::string InstanceMetaData::getDate() const{
    return std::string(KheInstanceMetaDataDate(meta));
}

std::string InstanceMetaData::getCountry() const{
    return std::string(KheInstanceMetaDataCountry(meta));
}

std::string InstanceMetaData::getDesc() const{
    return std::string(KheInstanceMetaDataDescription(meta));
}

std::string InstanceMetaData::getRemarks() const{
    return std::string(KheInstanceMetaDataRemarks(meta));
}

