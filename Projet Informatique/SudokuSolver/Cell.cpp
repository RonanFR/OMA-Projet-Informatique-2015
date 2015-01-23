# include "Cell.h"
# include <stdexcept>

using namespace std;

Cell::Cell()
{
}

Cell::Cell(unsigned char input)
	: value(input)
{
	if ((input > '9' || input< '1') && (input != '-'))
	{
		throw invalid_argument("la cellule doit contenir un chiffre entre 1 et 9");
	}
}

bool Cell::isEmpty()
{
	if (value == '-')
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

Cell & Cell ::operator=(unsigned char iValue)
{
	value = iValue;
	return *this;
}

Cell::operator unsigned char()const
{
	return value;
}

bool Cell::operator ==(unsigned char iValue) const
{
	return value == iValue;

}