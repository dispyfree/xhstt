/* 
 * File:   SolutionGroupMetaData.cpp
 * 
 */

#include "SolutionGroupMetaData.h"
#include <time.h>
#include <sys/time.h>

using namespace khe;
using sgmd = SolutionGroupMetaData;

sgmd::SolutionGroupMetaData(const std::string &contrib, const std::string &pdate, const std::string &desc,
            const std::string &pub, const std::string &remarks):
    contrib(contrib), date(pdate), desc(desc), pub(pub), remarks(remarks){
  
    meta = KheSolnGroupMetaDataMake(Util::sTc(this->contrib), 
            Util::sTc(date), Util::sTc(desc),
            Util::sTc(pub), Util::sTc(remarks));
}

    
std::string sgmd::getContributor() const{
    return KheSolnGroupMetaDataContributor(meta);
}

std::string sgmd::getDate() const{
    return KheSolnGroupMetaDataDate(meta);
}

std::string sgmd::getDescription() const{
    return KheSolnGroupMetaDataDescription(meta);
}

std::string sgmd::getPublication() const{
    return KheSolnGroupMetaDataPublication(meta);
}

std::string sgmd::getRemarks() const{
    return KheSolnGroupMetaDataRemarks(meta);
}

