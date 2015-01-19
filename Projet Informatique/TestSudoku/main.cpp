# include "Cell.h"
#include<iostream>
# include <stdexcept>


using namespace std;


int main(){

	
	try{
		Cell cell1(10);
	}
	catch (invalid_argument& ia)
	{
		cerr << ia.what() << endl;
	}



	getchar();
	return 0;
}