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
	bool isValuePresent(const unsigned char ivalue) const;
	Cell & get(int i) const;
	set < int > getEmptyCellsIndices() const;
	set <unsigned char>  flagValues(ValueEliminator valueEliminator) const;
	int getNbEmptyCells() const;
	bool isConsistent() const;
protected:
	TripleHolder tripleHolder1;
	TripleHolder tripleHolder2;
	TripleHolder tripleHolder3;
};

