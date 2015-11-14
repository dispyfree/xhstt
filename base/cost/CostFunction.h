/* 
 * File:   CostFunction.h
 * 
 *
 */

#ifndef COSTFUNCTION_H
#define	COSTFUNCTION_H

#include "global.h"
#include "Constraint.h"

#include <map>

namespace khe{
    

class CostFunction {
public:
    using KheType = KHE_COST_FUNCTION;
    
    CostFunction(){}
    CostFunction(const CostFunction& orig);
    CostFunction(KheType func);
    virtual ~CostFunction();
    
    static CostFunction getLinearFunction(){
        return CostFunction(KHE_LINEAR_COST_FUNCTION);
    }
    
    static CostFunction getStepFunction(){
        return CostFunction(KHE_STEP_COST_FUNCTION);
    }
    
    static CostFunction getQuadraticFunction(){
        return CostFunction(KHE_QUADRATIC_COST_FUNCTION);
    }
    
    operator KheType() const{
        return func;
    }
    
    
protected:
    KheType func;

};

}

#endif	/* COSTFUNCTION_H */

