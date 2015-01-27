# include"Grid.h"
# include <stdexcept>
# include<iostream>



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

RegionHolder  Grid::getN()
{
	
	return RegionHolder(N);
}

RegionHolder  Grid::getS()
{
	
	return RegionHolder(S);
}

RegionHolder  Grid::getE()
{
	
	return RegionHolder(E);
}

RegionHolder  Grid::getO()
{
	
	return RegionHolder(O);
}

RegionHolder  Grid::getC()
{
	
	
	return RegionHolder(C);
}

RegionHolder  Grid::getNE()
{
	
	return RegionHolder(NE);
}

RegionHolder  Grid::getNO()
{
	
	return RegionHolder(NO);
}

RegionHolder  Grid::getSE() 
{
	
	return RegionHolder(SE);
}

RegionHolder  Grid::getSO()
{
	
	return RegionHolder(SO);
}