#pragma once
#include"Region.h"
#include "RowHolder.h"
#include "ColumnHolder.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API RegionHolder
{
public:
	RegionHolder(Region & region);

	Cell & getN();
	Cell & getS();
	Cell & getE();
	Cell & getO();
	Cell & getNO();
	Cell & getNE();
	Cell & getSO();
	Cell & getSE();
	Cell & getC();

	RowHolder TopRow();
	RowHolder MiddleRow();
	RowHolder BottomRow();

	ColumnHolder LeftColumn();
	ColumnHolder MiddleColumn();
	ColumnHolder RightColumn();

	

private:
	Cell & N;
	Cell & S;
	Cell & E;
	Cell & O;
	Cell & NE;
	Cell & SE;
	Cell & NO;
	Cell & SO;
	Cell & C;


};