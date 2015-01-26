#pragma once
#include "Cell.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API TripleHolder
{
public:
	TripleHolder(Cell & cell1, Cell & cell2, Cell & cell3);
	Cell & getCell1();
	Cell & getCell2();
	Cell & getCell3();

protected:
	Cell & cell1;
	Cell & cell2;
	Cell & cell3;

};