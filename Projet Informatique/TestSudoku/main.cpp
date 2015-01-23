# include "Cell.h"
#include "Grid.h"
#include<iostream>
# include <stdexcept>


using namespace std;


int main(){


	/*try{
		Cell cell1(9);
		}
		catch (invalid_argument& ia)
		{
		cerr << ia.what() << endl;
		}
		*/
	list<Region> regions1;
	Region region1("482-9--85-");

	for (int i = 1; i < 10; i++)
	{
		regions1.push_back(region1);

	}
	try {
		Grid Grid(regions1);
	}
	catch (length_error & il)
	{
		cerr << il.what() << endl;
	}
	getchar();
	return 0;
}