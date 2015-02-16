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

using namespace std;


int main(){

	//// Test 1
	//try{
	//	Cell cell1(9);
	//}
	//catch (invalid_argument& ia)
	//{
	//	cerr << ia.what() << endl;
	//}

	//// Test 2
	//list<Region> regions1;
	//Region region1("482-9--85-");

	//for (int i = 1; i < 10; i++)
	//{
	//	regions1.push_back(region1);

	//}

	//// Test 3
	/*try {
		Grid Grid(regions1);
	}
	catch (length_error & il)
	{
		cerr << il.what() << endl;
	}*/


	//// Test Only Square Visitor
	//cout << "Test Only Square Visitor" << endl << endl;

	//Region NO("2619-87--");
	//Region N("495176832");
	//Region NE("873-45--6");
	//Region O("12638-4--");
	//Region C("987654321");
	//Region E("--4-27689");
	//Region SO("5--69-873");
	//Region S("763518249");
	//Region SE("--87-2561");

	//Grid grid1(NO,N,NE,O,C,E,SO,S,SE);
	//OnlySquareVisitor visitor;
	//
	//cout << "Original Sudoku" << endl;
	//grid1.dispGrid();
	//cout << endl << endl;
	//
	//cout << "First Visit" << endl;
	//visitor.Visit(grid1);
	//grid1.dispGrid();
	//cout << endl << endl;
	//
	//cout << "Second Visit" << endl;
	//visitor.Visit(grid1);
	//grid1.dispGrid();
	//cout << endl << endl;

	//// Test Two out of Three Visitor
	//Region NO("--9634125");
	//Region N("51----6-9");
	//Region NE("-6259-7-4");
	//Region O("---------");
	//Region C("--7---32-");
	//Region E("---------");
	//Region SO("---------");
	//Region S("173------");
	//Region SE("---------");

	//Grid grid2(NO, N, NE, O, C, E, SO, S, SE);

	//TwoOutOfThreeColumnVisitor visitor;

	//cout << "Original Sudoku" << endl;
	//grid2.dispGrid();
	//cout << endl << endl;

	//cout << "First Visit" << endl;
	//visitor.Visit(grid2);
	//grid2.dispGrid();
	//cout << endl << endl;

	// Test Solver
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
	cout << endl << endl;
	
	getchar();
	return 0;
}