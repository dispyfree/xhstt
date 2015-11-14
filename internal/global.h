/* 
 * File:   global.h
 * 
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

extern "C"{
    #include "khe.h"
}


#include <boost/range/iterator_range_core.hpp>
#include "KheObjIter.h"


/**
 * see global.cpp for definition
 * Set this to "false" if you want to construct solutions; for reading purposes,
 * allowing caching speeds up things very much.
 */
extern bool allowCaching;

extern const bool useBackPointerForNumIds;

#include "Util.h"
#include "ObjNotFound.h"
#include "Ident.h"

#include <string>
#include <vector>


#endif	/* GLOBAL_H */

