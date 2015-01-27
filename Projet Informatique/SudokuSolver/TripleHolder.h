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
	Cell & getCell1()const ;
	Cell & getCell2()const;
	Cell & getCell3()const;

protected:
	Cell & cell1 ;
	Cell & cell2 ;
	Cell & cell3 ;

};
