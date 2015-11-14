/* 
 * File:   SolutionGroup.h
 * 
 */

#ifndef SOLUTIONGROUP_H
#define	SOLUTIONGROUP_H

#include "global.h"

#include "SolutionGroupMetaData.h"

namespace khe{
    
    class Archive;
    class Solution;
    
class SolutionGroup {
public:
    using KheType = KHE_SOLN_GROUP;
    
    SolutionGroup(Archive &arch, const std::string &id, 
            SolutionGroupMetaData meta);
    SolutionGroup(KheType raw) : grp(raw){Util::rnn(raw);}
    virtual ~SolutionGroup(){}
    
    void setBack(void *back);
    void *getBack() const {
         return KheSolnGroupBack(grp);
    }
    
    Archive getArchive() const;
    std::string getId() const;
    SolutionGroupMetaData getMeta() const;
    
    void add(const Solution &sol);
    void remove(const Solution &sol);
    std::vector<Solution> getSolutions() const;

    operator KheType() const{
        return grp;
    }
    
     bool operator==(const SolutionGroup &solg2) const{
        return getId() == solg2.getId();
    }
    
protected:
    KheType grp;

};

}

#endif	/* SOLUTIONGROUP_H */

