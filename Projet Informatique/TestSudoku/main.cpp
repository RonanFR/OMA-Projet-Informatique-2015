# include "Cell.h"
# include "Grid.h"
# include <iostream>
# include <stdexcept>
# include "OnlyOneChoiceInRowVisitor.h"
# include "OnlyOneChoiceInColumnVisitor.h"
# include "OnlyOneChoiceInRegionVisitor.h"

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

	Region region1("482------");
	Region region2("-56-9----");
	Region region3("793------");
	Region region4("1489-3275");
	Region region5("-8--6--2-");
	Region region6("---------");
	Region region7("------78-");
	Region region8("-4--7-231");
	Region region9("------456");
	
	list<Region> regions;
	regions.push_back(region1);
	regions.push_back(region2);
	regions.push_back(region3);
	regions.push_back(region4);
	regions.push_back(region5);
	regions.push_back(region6);
	regions.push_back(region7);
	regions.push_back(region8);
	regions.push_back(region9);

	Grid grid1(regions);
	grid1.dispGrid();

	OnlyOneChoiceInRowVisitor visitor1;
	visitor1.Visit(grid1);

	cout << endl << endl;
	grid1.dispGrid();

	OnlyOneChoiceInColumnVisitor visitor2;
	visitor2.Visit(grid1);
	
	cout << endl << endl;
	grid1.dispGrid();

	OnlyOneChoiceInRegionVisitor visitor3;
	visitor3.Visit(grid1);

	cout << endl << endl;
	grid1.dispGrid();

	getchar();
	return 0;
}