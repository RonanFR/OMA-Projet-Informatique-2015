# include "Cell.h"
# include "Grid.h"
# include <iostream>
# include <stdexcept>
# include "OnlyOneChoiceInRowVisitor.h"
# include "OnlyOneChoiceInColumnVisitor.h"
# include "OnlyOneChoiceInRegionVisitor.h"
# include "OnlySquareVisitor.h"

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

	// Test Only Square Visitor
	cout << "Test Only Square Visitor" << endl << endl;

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
	cout << endl << endl;

	getchar();
	return 0;
}