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

RegionHolder & Grid::getN()
{
	RegionHolder & rh_N = RegionHolder(N);
	return rh_N;
}

RegionHolder & Grid::getS()
{
	RegionHolder & rh_S = RegionHolder(S);
	return rh_S;
}

RegionHolder & Grid::getE()
{
	RegionHolder & rh_E = RegionHolder(E);
	return rh_E;
}

RegionHolder & Grid::getO()
{
	RegionHolder & rh_O = RegionHolder(O);
	return rh_O;
}

RegionHolder & Grid::getC()
{
	RegionHolder & rh_C = RegionHolder(C);
	return rh_C;
}

RegionHolder & Grid::getNE()
{
	RegionHolder & rh_NE = RegionHolder(NE);
	return rh_NE;
}

RegionHolder & Grid::getNO()
{
	RegionHolder & rh_NO = RegionHolder(NO);
	return rh_NO;
}

RegionHolder & Grid::getSE()
{
	RegionHolder & rh_SE = RegionHolder(SE);
	return rh_SE;
}

RegionHolder & Grid::getSO()
{
	RegionHolder & rh_SO = RegionHolder(SO);
	return rh_SO;
}