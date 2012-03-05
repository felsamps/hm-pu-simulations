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
#include "TLibCommon/TComMv.h"

class StatsManager {
    //fast pu decision parameters
    static TComMv mv_NxN[4];
    static UInt currCUSize, currIdx;
    static PartSize currPartSize;
    static Bool A, B, C, D;
    static Bool a, b, c, d;
    static Pel* currCU;
    static UInt cuStride;
    
    
    //PU choices statistics
    static std::vector<Int> choices64, choices32, choices16, choices8;


public:
    StatsManager();
    static void init();
    static void addPuChoice();
    static void clearFastDecisionParams();
    static std::string reportPUChoices();
    static std::string reportFastDecisionParams();
    static std::string currCUToString();

    static void mergeMVs();

    static void setMv(TComMv mv);
    static TComMv getMv();

    static void setCurrIdx(UInt idx);
    static UInt getCurrIdx();

    static void setCurrCUSize(UInt size);
    static UInt getCurrCUSize();

    static void setCurrPartSize(PartSize part);
    static PartSize getCurrPartSize();

    static void setCurrCU(Pel* cu);
    static Pel* getCurrCU();
    
    static void setCuStride(UInt cu);
    static UInt getCuStride();
};

#endif	/* _STATSMANAGER_H */

