#pragma once
#include "Cell.h"
#include "ValueEliminator.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API TripleHolder
{
public:
	TripleHolder(Cell & cell1, Cell & cell2, Cell & cell3);
	Cell & getCell1()const;
	Cell & getCell2()const;
	Cell & getCell3()const;

	int getNbEmptyCells();
	Cell & getEmptyCell();
	int getSumCells();

	set <unsigned char> flagValues(ValueEliminator ValueEliminator);
	bool isValuePresent(const unsigned char ivalue);

protected:
	Cell & cell1 ;
	Cell & cell2 ;
	Cell & cell3 ;

	int nbEmptyCells;
	Cell & emptyCell;
	int sumCells;

};
