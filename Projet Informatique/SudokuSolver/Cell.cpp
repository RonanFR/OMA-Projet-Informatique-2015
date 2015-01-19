# include "Cell.h"
# include <stdexcept>

using namespace std;

Cell::Cell()
{
}

Cell::Cell(unsigned int input)
	: value(input)
{
	if (input > 9)
	{
		throw invalid_argument("Chiffre de la cellule superieur a 10");
	}
}

