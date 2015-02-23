# pragma once
# include "Grid.h"

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

/** This class aims at providing methods for solving simple Sudoku grids (of force 4 maximum).
* The methods used are : OnlyOneChoice, OnlySquare and TwoOutOfThree. The idea is to apply all
* these methods recursively until no changes occur in the grid or the grid is not consistent.
*/

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

