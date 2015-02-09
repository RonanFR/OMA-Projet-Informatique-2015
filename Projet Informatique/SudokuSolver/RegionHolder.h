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
	RegionHolder(Region  & region);

	Cell & getN() const ;
	Cell & getS() const;
	Cell & getE()const;
	Cell & getO()const;
	Cell & getNO()const;
	Cell & getNE()const;
	Cell & getSO()const;
	Cell & getSE()const;
	Cell & getC()const;

	RowHolder TopRow()const;
	RowHolder MiddleRow()const;
	RowHolder BottomRow()const;

	ColumnHolder LeftColumn()const;
	ColumnHolder MiddleColumn()const;
	ColumnHolder RightColumn()const;

	set <unsigned char> flagValues(ValueEliminator ValueEliminator);
	bool isValuePresent(const unsigned char ivalue);
	

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