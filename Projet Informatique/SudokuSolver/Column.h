#pragma once
# include "NineHolder.h"
# include "ColumnHolder.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API Column :public NineHolder
{
public:
	Column(ColumnHolder columnHolder1, ColumnHolder columnHolder2, ColumnHolder columnHolder3);
	~Column();
};

