/* 
 * File:   InstanceMetaData.h
 * 
 */

#ifndef INSTANCEMETADATA_H
#define	INSTANCEMETADATA_H

#include "global.h"

#define UNSPEC "unspecified"

namespace khe{
    
class InstanceMetaData{
    friend class Instance;
    
public:
    InstanceMetaData(KHE_INSTANCE_METADATA meta);
    InstanceMetaData(const std::string &name = UNSPEC, const std::string &contributor = UNSPEC, 
        const std::string &date = UNSPEC, const std::string &country = UNSPEC, const std::string &desc = UNSPEC,
        const std::string &remarks = UNSPEC);
    
    InstanceMetaData(const InstanceMetaData& orig);
    virtual ~InstanceMetaData();
    
    std::string getName() const;
    std::string getContributor() const;
    std::string getDate() const;
    std::string getCountry() const;
    std::string getDesc() const;
    std::string getRemarks() const;
    
    operator KHE_INSTANCE_METADATA() const{
        return meta;
    }
    
    
protected:
    KHE_INSTANCE_METADATA meta;
    

};
}

#endif	/* INSTANCEMETADATA_H */

