#pragma once
# include "NineHolder.h"
# include "RowHolder.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API Row :public NineHolder
{
public:
	Row(RowHolder rowHolder1, RowHolder rowHolder2, RowHolder rowHolder3);
	~Row();
};

