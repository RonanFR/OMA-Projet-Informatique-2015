#pragma once
#include "IVisitor.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

class SUDOKUSOLVER_API OnlyOneChoiceInRowVisitor : public IVisitor
{
public:
	OnlyOneChoiceInRowVisitor();
	~OnlyOneChoiceInRowVisitor();
	bool Visit(Grid & iogrid) const;
};

