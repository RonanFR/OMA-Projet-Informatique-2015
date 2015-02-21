# include "GridSolver.h"
# include "OnlyOneChoiceInColumnVisitor.h"
# include "OnlyOneChoiceInRegionVisitor.h"
# include "OnlyOneChoiceInRowVisitor.h"
# include "OnlySquareVisitor.h"
# include "TwoOutOfThreeColumnVisitor.h"
# include "TwoOutOfThreeRowVisitor.h"


GridSolver::GridSolver()
{
}


GridSolver::~GridSolver()
{
}

bool GridSolver::solveOnlyOneChoice(Grid & iogrid) const
{
	bool hasGridChanged = true;
	bool isGridModified = false;
	bool bool1;
	bool bool2;
	bool bool3;
	OnlyOneChoiceInColumnVisitor onlyOneChoiceInColumnVisitor;
	OnlyOneChoiceInRegionVisitor onlyOneChoiceInRegionVisitor;
	OnlyOneChoiceInRowVisitor onlyOneChoiceInRowVisitor;

	while (hasGridChanged && !iogrid.isFull() && iogrid.isConsistent())
	{
		bool1 = onlyOneChoiceInColumnVisitor.Visit(iogrid);
		if (iogrid.isFull() || !iogrid.isConsistent())
		{
			break;
		}
		bool2 = onlyOneChoiceInRegionVisitor.Visit(iogrid);
		if (iogrid.isFull() || !iogrid.isConsistent())
		{
			break;
		}
		bool3 = onlyOneChoiceInRowVisitor.Visit(iogrid);
		hasGridChanged = bool1 || bool2 || bool3;
		if (hasGridChanged)
		{
			isGridModified = true;
		}
	}
	return isGridModified;
}

bool GridSolver::solveOnlySquare(Grid & iogrid) const
{
	bool hasGridChanged = true;
	bool isGridModified = false;
	OnlySquareVisitor onlySquareVisitor;

	while (hasGridChanged && !iogrid.isFull() && iogrid.isConsistent())
	{
		hasGridChanged = onlySquareVisitor.Visit(iogrid);
		if (hasGridChanged)
		{
			isGridModified = true;
		}
	}
	return isGridModified;
}

bool GridSolver::solveTwoOutOfThree(Grid & iogrid) const
{
	bool hasGridChanged = true;
	bool isGridModified = false;
	bool bool1;
	bool bool2;
	TwoOutOfThreeColumnVisitor twoOutOfThreeColumnVisitor;
	TwoOutOfThreeRowVisitor twoOutOfThreeRowVisitor;

	while (hasGridChanged && !iogrid.isFull() && iogrid.isConsistent())
	{
		bool1 = twoOutOfThreeColumnVisitor.Visit(iogrid);
		if (iogrid.isFull() || !iogrid.isConsistent())
		{
			break;
		}
		bool2 = twoOutOfThreeRowVisitor.Visit(iogrid);
		hasGridChanged = bool1 || bool2 ;
		if (hasGridChanged)
		{
			isGridModified = true;
		}
	}
	return isGridModified;
}

void GridSolver::solve(Grid & iogrid) const
{
	bool hasGridChanged = true;
	bool bool1;
	bool bool2;
	bool bool3;
	while (hasGridChanged && !iogrid.isFull() && iogrid.isConsistent())
	{
		bool1 = solveOnlyOneChoice(iogrid);
		if (iogrid.isFull() || !iogrid.isConsistent())
		{
			break;
		}
		bool2 = solveOnlySquare(iogrid);
		if (iogrid.isFull() || !iogrid.isConsistent())
		{
			break;
		}
		bool3 = solveTwoOutOfThree(iogrid);
		hasGridChanged = bool1 || bool2 || bool3;
	}
}

