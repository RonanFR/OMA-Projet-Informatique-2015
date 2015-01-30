#pragma once
# include "Grid.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif


class SUDOKUSOLVER_API IVisitor
{
public:
	IVisitor();
	~IVisitor();
	virtual bool Visit(Grid & ioGrid) const = 0 ;
};

