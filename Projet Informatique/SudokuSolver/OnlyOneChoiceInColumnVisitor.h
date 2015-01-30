#pragma once
#include "Ivisitor.h"
#include "LastCellFinder.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif
class SUDOKUSOLVER_API OnlyOneChoiceInColumnVisitor : public IVisitor
{
public:

	OnlyOneChoiceInColumnVisitor();
	~OnlyOneChoiceInColumnVisitor();

	bool Visit(Grid & ioGrid)const;

};

