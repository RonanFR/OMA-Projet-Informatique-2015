# include "Grid.h"
# include <iostream>

Grid::Grid(list<Region> regions){
	if (regions.size() != 9)
	{
		throw length_error("Une grille contient exactement 9 regions");
	}
	else
	{
		list<Region>::iterator it = regions.begin();
		NO = Region(*it);
		N = Region(*++it);
		NE = Region(*++it);
		O = Region(*++it);
		C = Region(*++it);
		E = Region(*++it);
		SO = Region(*++it);
		S = Region(*++it);
		SE = Region(*++it);
	}
}

bool Grid::isFull()
{
	return NO.isFull() && N.isFull() && NE.isFull() && O.isFull()
		&& C.isFull() && E.isFull() && SO.isFull() && SO.isFull()
		&& SE.isFull();
}