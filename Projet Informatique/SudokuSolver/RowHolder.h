#pragma once
#include "TripleHolder.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API RowHolder:public TripleHolder
{
public:
	RowHolder(Cell & cell1, Cell & cell2, Cell & cell3);
	Cell & G() const;
	Cell & C() const;
	Cell & D() const;
};