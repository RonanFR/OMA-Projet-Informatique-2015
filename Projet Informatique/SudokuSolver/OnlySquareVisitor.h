#pragma once
# include "IVisitor.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

class SUDOKUSOLVER_API OnlySquareVisitor : public IVisitor
{
public:
	OnlySquareVisitor();
	~OnlySquareVisitor();
	bool Visit(Grid & ioGrid) const;
	set<unsigned char> findPossibleValues(Grid & ioGrid, int i, int j) const;
};

