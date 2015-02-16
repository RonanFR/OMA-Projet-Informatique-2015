# pragma once
# include "Grid.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

class SUDOKUSOLVER_API GridSolver
{
public:
	GridSolver();
	~GridSolver();

	bool solveOnlyOneChoice(Grid & iogrid) const;
	bool solveOnlySquare(Grid & iogrid) const;
	bool solveTwoOutOfThree(Grid & iogrid) const;
	void solve(Grid & iogrid) const;
};

