# include "Region.h"
# include <stdexcept>
# include <iostream>

using namespace std;

Region::Region()
{
}

Region::Region(string chaine){
	if (chaine.size() != 9)
	{
		throw length_error("Une region contient exactement 9 cellules");
	}
	else
	{
		int i = 0;
		NO = Cell(chaine[i]);
		N = Cell(chaine[++i]);
		NE = Cell(chaine[++i]);
		O = Cell(chaine[++i]);
		C = Cell(chaine[++i]);
		E = Cell(chaine[++i]);
		SO = Cell(chaine[++i]);
		S = Cell(chaine[++i]);
		SE = Cell(chaine[++i]);
	}
}

bool Region::isFull()
{
	return !(NO.isEmpty() || N.isEmpty() || NE.isEmpty() || O.isEmpty()
		|| C.isEmpty() || E.isEmpty() || SO.isEmpty() || SO.isEmpty()
		|| SE.isEmpty());
}

