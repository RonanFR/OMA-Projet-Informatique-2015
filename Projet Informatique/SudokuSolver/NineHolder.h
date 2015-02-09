#pragma once
# include "TripleHolder.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API NineHolder
{
public:
	NineHolder(TripleHolder tripleHolder1, TripleHolder tripleHolder2, TripleHolder tripleHolder3);
	~NineHolder();
	bool isValuePresent(const unsigned char ivalue);
	Cell & get(int i);
	set < int > getEmptyCellsIndices();
	set <unsigned char>  flagValues(ValueEliminator valueEliminator);
protected:
	TripleHolder tripleHolder1;
	TripleHolder tripleHolder2;
	TripleHolder tripleHolder3;
};

