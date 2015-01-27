#pragma once
#include "TripleHolder.h"
#include<list>
#include<memory>

using namespace std;

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API LastCellFinder
{
public:
	LastCellFinder(TripleHolder triple1, TripleHolder triple2, TripleHolder triple3);
	
	bool fill() ;
	
	list<unique_ptr<Cell>> Getlist();

private:
	TripleHolder triple1;
	TripleHolder triple2;
	TripleHolder triple3;
};