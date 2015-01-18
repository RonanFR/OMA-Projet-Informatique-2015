# include "Cell.h"
# include <stdexcept>
# include <iostream>

using namespace std;

int main(){
	try {
		Cell(10);
	}
	catch (const std::invalid_argument & ia){
		cerr << "Invalid argument " << ia.what();
	}
}