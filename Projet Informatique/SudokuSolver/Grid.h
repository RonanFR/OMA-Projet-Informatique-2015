#pragma once
#include "Region.h"
#include <list>

using namespace std;

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API Grid
{
public:
	Grid(list<Region> regions);

private:
	Region N;
	Region S;
	Region E;
	Region O;
	Region NE;
	Region SE;
	Region NO;
	Region SO;
	Region C;


};