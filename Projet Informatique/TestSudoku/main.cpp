# include "Cell.h"
# include "Grid.h"
# include <iostream>
# include <stdexcept>
# include "OnlyOneChoiceInRowVisitor.h"
# include "OnlyOneChoiceInColumnVisitor.h"
# include "OnlyOneChoiceInRegionVisitor.h"
# include "OnlySquareVisitor.h"
# include "TwoOutOfThreeRowVisitor.h"
# include "TwoOutOfThreeColumnVisitor.h"
# include "GridSolver.h"
# include <ctime>

using namespace std;


int main(){

	/*-------------------------------------------
	 * Test Cell class
	 *------------------------------------------- */
	/*try{
		Cell cell1(10);
	}
	catch (invalid_argument& ia)
	{
		cerr << ia.what() << endl;
	}*/

	/*-------------------------------------------
	 * Test Region class
	 *-------------------------------------------*/
	/*list<Region> regions1;
	try {
		Region region1("482-9--85-6");
	}
	catch (length_error & il)
	{
		cerr << il.what() << endl;
	}*/


	/*-------------------------------------------
	* Test Only Square Visitor
	*-------------------------------------------*/
	/*cout << "Test Only Square Visitor" << endl << endl;

	Region NO("2619-87--");
	Region N("495176832");
	Region NE("873-45--6");
	Region O("12638-4--");
	Region C("987654321");
	Region E("--4-27689");
	Region SO("5--69-873");
	Region S("763518249");
	Region SE("--87-2561");

	Grid grid1(NO,N,NE,O,C,E,SO,S,SE);
	OnlySquareVisitor visitor;
	
	cout << "Original Sudoku" << endl;
	grid1.dispGrid();
	cout << endl << endl;
	
	cout << "First Visit" << endl;
	visitor.Visit(grid1);
	grid1.dispGrid();
	cout << endl << endl;
	
	cout << "Second Visit" << endl;
	visitor.Visit(grid1);
	grid1.dispGrid();
	cout << endl << endl;*/

	
	/*-------------------------------------------
	* Test Two out of Three Visitor
	*-------------------------------------------*/
	/*cout << "Test Two out of Three Visitor" << endl << endl;

	Region NO("--9634125");
	Region N("51----639");
	Region NE("-6259-7-4");
	Region O("---------");
	Region C("--7---32-");
	Region E("---------");
	Region SO("---------");
	Region S("173------");
	Region SE("---------");

	Grid grid2(NO, N, NE, O, C, E, SO, S, SE);

	TwoOutOfThreeColumnVisitor visitor;

	cout << "Original Sudoku" << endl;
	grid2.dispGrid();
	cout << endl << endl;

	cout << "First Visit" << endl;
	visitor.Visit(grid2);
	grid2.dispGrid();
	cout << endl << endl;*/
	
	/*-------------------------------------------
	* Test GridSolver (Sudoku force 4)
	*-------------------------------------------*/
	/* cout << "Test GridSolver" << endl << endl;
	
	Region NO("-----6--9");
	Region N("--23----1");
	Region NE("6-3--1-52");
	Region O("782----5-");
	Region C("---------");
	Region E("-9----726");
	Region SO("24-8--6-5");
	Region S("1----48--");
	Region SE("8--5-----");

	Grid grid2(NO, N, NE, O, C, E, SO, S, SE);
	GridSolver gridSolver;

	cout << "Original Sudoku" << endl;
	grid2.dispGrid();
	cout << endl << endl;

	cout << "Solved Grid" << endl;
	gridSolver.solve(grid2);
	grid2.dispGrid();
	cout << endl << endl;*/
	
	/*-------------------------------------------
	* Test backtracking
	*-------------------------------------------*/
	cout << "Test backtracking" << endl << endl;

	// First grid : grid given in the PDF
	// Remark : this grid has no valid solution
	/*Region NO("-54--16--");
	Region N("-7--9-5--");
	Region NE("---3--2--");
	Region O("---------");
	Region C("36---84--");
	Region E("1-46---3-");
	Region SO("-8--36--5");
	Region S("9-----2--");
	Region SE("--6--14--");*/

	// Second grid : other diabolic grid found on the web
	Region NO("--1--95-7");
	Region N("-7--6---2");
	Region NE("-86---4--");
	Region O("6--8---9-");
	Region C("--1---8--");
	Region E("-9---3--2");
	Region SO("--6---34-");
	Region S("2---1--5-");
	Region SE("8-59--2--");

	// Third grid : "difficult" grid (long run time) found in the article :
	// "Limiting Backtracking in Fast Sudoku Solvers", Ileana - Diana V.D.Nicolae, Anca - Iuliana P.M.Nicolae
	/*Region NO("--------2");
	Region N("------3--");
	Region NE("-12--34--");
	Region O("--1-6----");
	Region C("8---7---9");
	Region E("--58-----");
	Region SO("--89--47-");
	Region S("5---4---6");
	Region SE("---5-----");*/

	Grid grid3(NO, N, NE, O, C, E, SO, S, SE);
	GridSolver gridSolver;

	cout << "Original Sudoku" << endl;
	grid3.dispGrid();
	cout << endl << endl;

	cout << "Solved Grid" << endl;
	
	double tic = clock();

	try
	{
		grid3.Solve();
		grid3.dispGrid();
	}
	catch (logic_error & le)
	{
		cout << le.what() << endl;
	}
	
	double toc = clock();
	cout << endl << endl;
	cout << "Runtime :" << (toc - tic)/CLOCKS_PER_SEC << endl;
	
	getchar();
	return 0;
}