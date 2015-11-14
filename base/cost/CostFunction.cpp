/* 
 * File:   CostFunction.cpp
 * 
 */

#include "CostFunction.h"
#include <stdexcept>
using namespace khe;



CostFunction::CostFunction(const CostFunction& orig) {
    func = orig.func;
}

CostFunction::CostFunction(KHE_COST_FUNCTION func){
    this->func = func;
}

CostFunction::~CostFunction() {
}


