/* 
 * File:   SolutionGroupMetaData.h
 * 
 */

#ifndef SOLUTIONGROUPMETADATA_H
#define	SOLUTIONGROUPMETADATA_H

#include "global.h"

namespace khe{
    
    class Archive;
    class SolutionGroupMetaData;
    
class SolutionGroupMetaData {
    using KheType = KHE_SOLN_GROUP_METADATA;
public:
    SolutionGroupMetaData(const std::string &contrib, const std::string &date, const std::string &desc,
            const std::string &pub, const std::string &remarks);
    SolutionGroupMetaData(KheType raw) : meta(raw){Util::rnn(raw);};
    virtual ~SolutionGroupMetaData(){}
    
    std::string getContributor() const;
    std::string getDate() const;
    std::string getDescription() const;
    std::string getPublication() const;
    std::string getRemarks() const;

    operator KheType() const{
        return meta;
    }
    
protected:
    KheType meta;
    
    std::string contrib;
    std::string date;
    std::string desc;
    std::string pub;
    std::string remarks;

};

}

#endif	/* SOLUTIONGROUPMETADATA_H */

