/* 
 * File:   StatsManager.cpp
 * Author: felsamps
 * 
 * Created on March 1, 2012, 11:03 AM
 */


#include <list>
#include <iosfwd>

#include "StatsManager.h"
#include "TLibCommon/FileWriter.h"



std::vector<Int> StatsManager::choices64;
std::vector<Int> StatsManager::choices32;
std::vector<Int> StatsManager::choices16;
std::vector<Int> StatsManager::choices8;
TComMv StatsManager::mv_NxN[4];
UInt StatsManager::currIdx, StatsManager::currCUSize;
Bool StatsManager::A, StatsManager::B, StatsManager::C, StatsManager::D;
Bool StatsManager::a, StatsManager::b, StatsManager::c, StatsManager::d;
PartSize StatsManager::currPartSize;
Pel* StatsManager::currCU;
UInt StatsManager::cuStride;

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

void StatsManager::addPuChoice() {
	
	if(currCUSize == 64) choices64[(int)currPartSize] += 1;
	else if(currCUSize == 32) choices32[currPartSize] += 1;
	else if(currCUSize == 16) choices16[currPartSize] += 1;
	else if(currCUSize == 8) choices8[currPartSize] += 1;
}

std::string StatsManager::reportPUChoices() {
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

void StatsManager::mergeMVs() {
	A = (mv_NxN[0] == mv_NxN[1]) ? true : false;
	B = (mv_NxN[0] == mv_NxN[2]) ? true : false;
	C = (mv_NxN[1] == mv_NxN[3]) ? true : false;
	D = (mv_NxN[2] == mv_NxN[3]) ? true : false;
}

std::string StatsManager::reportFastDecisionParams() {
	std::string partitions[] = {"2Nx2N","2NxN","Nx2N","NxN","2NxnU","2NxnD","nLx2N","nRx2N","","","","","","","","NONE"};
	std::string returnable;
	char temp[10];

	mergeMVs();

	sprintf(temp,"%d %s ", currCUSize, partitions[currPartSize].c_str());
	returnable.append(temp);

	returnable += (A) ? "1" : "0";
	returnable += (B) ? "1" : "0";
	returnable += (C) ? "1" : "0";
	returnable += (D) ? "1" : "0";

	returnable += "\n";

	return returnable;
}

std::string StatsManager::currCUToString() {
	Pel* org = currCU;
	std::string returnable;
	char temp[10];
	
	for (int y = 0; y < currCUSize; y++) {
		returnable.clear();
		for (int x = 0; x < currCUSize; x++) {
			sprintf(temp, "%d", org[x]);
			returnable.append(temp);
			returnable += " ";
		}
		org += cuStride;
		returnable += "\n";
		fprintf(FileWriter::getFile(PU_DECISION_PARAMS_FILE),"%s", returnable.c_str());
	}

	
	return returnable;

}

void StatsManager::setMv(TComMv mv) {
	mv_NxN[currIdx].setHor(mv.getHor());
	mv_NxN[currIdx].setVer(mv.getVer());
}
TComMv StatsManager::getMv() {
	return mv_NxN[currIdx];
}

void StatsManager::setCurrIdx(UInt idx) {
	currIdx = idx;
}
UInt StatsManager::getCurrIdx() {
	return currIdx;
}

void StatsManager::setCurrCUSize(UInt size) {
	currCUSize = size;
}

UInt StatsManager::getCurrCUSize() {
	return currCUSize;
}

void StatsManager::setCurrPartSize(PartSize part) {
	currPartSize = part;
}

PartSize StatsManager::getCurrPartSize() {
	return currPartSize;
}

void StatsManager::setCurrCU(Pel* cu) {
	currCU = cu;
}

Pel* StatsManager::getCurrCU() {
	return currCU;
}
void StatsManager::setCuStride(UInt cu) {
	cuStride = cu;
}
UInt StatsManager::getCuStride() {
	return cuStride;
}