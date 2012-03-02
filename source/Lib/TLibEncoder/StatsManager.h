/* 
 * File:   StatsManager.h
 * Author: felsamps
 *
 * Created on March 1, 2012, 11:03 AM
 */

#ifndef _STATSMANAGER_H
#define	_STATSMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include "TLibCommon/TypeDef.h"

class StatsManager {
    static std::vector<Int> choices64, choices32, choices16, choices8;

public:
    StatsManager();
    static void init();
    static void addPuChoice(Int size, PartSize part);
    static std::string report();
    
};

#endif	/* _STATSMANAGER_H */

