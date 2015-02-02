#pragma once
#include "IVisitor.h"
#include "LastCellFinder.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
#endif 

class SUDOKUSOLVER_API OnlyOneChoiceInRegionVisitor : public IVisitor
{
public:
	OnlyOneChoiceInRegionVisitor();
	~OnlyOneChoiceInRegionVisitor();
	bool Visit(Grid & iogrid) const;
};

