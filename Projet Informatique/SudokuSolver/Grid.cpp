#include"Grid.h"
#include <stdexcept>
#include<iostream>



Grid::Grid(list<Region> regions)

{
	if (regions.size() != 9)
	{
		throw length_error("Une grile doit contenir exactement 9 regions");
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