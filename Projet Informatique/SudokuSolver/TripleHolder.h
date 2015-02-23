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

	int getNbEmptyCells() const;
	Cell & getEmptyCell() const;
	int getSumCells() const;

	set <unsigned char> flagValues(ValueEliminator ValueEliminator) const;
	bool isValuePresent(const unsigned char ivalue) const;
	TripleHolder & operator =(TripleHolder const tripleHolder);

protected:
	Cell & cell1;
	Cell & cell2;
	Cell & cell3;

};
