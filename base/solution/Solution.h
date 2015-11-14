/* 
 * File:   Solution.h
 * 
 */

#ifndef SOLUTION_H
#define	SOLUTION_H

#include "global.h"
#include "SolutionGroup.h"
#include "Meet.h"
#include "Task.h"
#include "Event.h"

namespace khe{

    class Instance;
    
class Solution {
    using KheType = KHE_SOLN;
public:
    Solution(Instance inst);
    Solution(KheType sol): sol(sol){Util::rnn(sol);}
    virtual ~Solution(){}
    
    void setBack(void *back);
    void *getBack() const {
         return KheSolnBack(sol);
    }
    
    Instance getInstance() const;
    Solution clone() const;
    
    void remove(){ KheSolnDelete(sol);}
    
    int getCost() const;
    int getHardCost() const;
    int getSoftCost() const;
    
    std::vector<SolutionGroup> getSolutionGroups() const;
    
    Meet createMeet(int duration, const Event &evt);
    std::vector<Meet> getMeets() const;
    std::vector<Meet> getMeets(const Event &evt) const;
    std::vector<Meet> getCycleMeets() const;
    void remove(const Meet &meet);
    
    
    std::vector<Task> getTasks() const;
    std::vector<Task> getTasks(const EventResource &er) const;
    
    void setDescription(const std::string &desc);
    std::string getDescription() const;
    
    void setRunningTime(float time);
    float getRunningTime() const;
    
    float getSoftTimeLimit() const;
    void setSoftTimeLimit(float limit);
    bool reachedSoftTimeLimit() const;
    
    void complete();
    /**
     * Use these functions to obtain the "real" cost
     * (cost may also be induced by preassigned resources or times;
     * however, they are not considered when bearing the "preassigned" state)
     */
    void assignPreassignedTimes();
    void assignPreassignedResources();
    void assignPreassignedResources(const ResourceType &rt);
    int getDiversifier() const;
    void setDiversifier(int div);
    int chooseDiversifier(int c);
    
    float getElapsedTime() const;
    
    /**
     * prints information about the current solution onto file fp with the given verbosity and indent,
     * as described for debug functions in general in Section 1.3. Verbosity 1 prints just the instance
     * name and current cost, verbosity 2 adds a breakdown of the current cost by constraint type (only
     * constraint types with non-zero cost are printed), verbosity 3 adds debug prints of the solution’s
     * defects (Section 6.2), and verbosity 4 prints further details
     */
    void debug(int verbosity, int indent, FILE *fp) const;
    
    operator KheType() const{
        return sol;
    }
    

protected:
    KheType sol;

};

}

#endif	/* SOLUTION_H */

