/* 
 * File:   StatsManager.cpp
 * Author: felsamps
 * 
 * Created on March 1, 2012, 11:03 AM
 */


#include <list>

#include "StatsManager.h"


std::vector<Int> StatsManager::choices64;
std::vector<Int> StatsManager::choices32;
std::vector<Int> StatsManager::choices16;
std::vector<Int> StatsManager::choices8;

StatsManager::StatsManager() {
}

void StatsManager::init() {
	
	for (int i = 0; i <= 15; i++) {
		choices64.push_back(0);
		choices32.push_back(0);
		choices16.push_back(0);
		choices8.push_back(0);
	}

}

void StatsManager::addPuChoice(Int size, PartSize part) {
	
	if(size == 64) choices64[(int)part] += 1;
	else if(size == 32) choices32[part] += 1;
	else if(size == 16) choices16[part] += 1;
	else if(size == 8) choices8[part] += 1;
}

std::string StatsManager::report() {
	std::string returnable, size64("64;"), size32("32;"), size16("16;"), size8("8;");
	returnable = "CUSize;2Nx2N;2NxN;Nx2N;NxN;2NxnU;2NxnD;nLx2N;nRx2N;\n";

	for (int i = 0; i < 8; i++) {
		char temp[10];
		sprintf(temp,"%d;",choices64[i]);
		size64.append(temp);
		sprintf(temp,"%d;",choices32[i]);
		size32.append(temp);
		sprintf(temp,"%d;",choices16[i]);
		size16.append(temp);
		sprintf(temp,"%d;",choices8[i]);
		size8.append(temp);
	}
	returnable += size64 + "\n";
	returnable += size32 + "\n";
	returnable += size16 + "\n";
	returnable += size8 + "\n";

	return returnable;
}