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

//void Grid::Accept(IVisitor & visitor)
//{
//	visitor.Visit(*this);
//}

void Grid::dispGrid()
{
	cout << "  ------------------------------------" << endl;

	// 1st row
	cout << " | " << NO.getNO() << " | " << NO.getN() << " | " << NO.getNE() << " | ";
	cout  << N.getNO() << " | " << N.getN() << " | " << N.getNE() << " | ";
	cout  << NE.getNO() << " | " << NE.getN() << " | " << NE.getNE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 2nd row
	cout << " | " << NO.getO() << " | " << NO.getC() << " | " << NO.getE() << " | ";
	cout  << N.getO() << " | " << N.getC() << " | " << N.getE() << " | ";
	cout  << NE.getO() << " | " << NE.getC() << " | " << NE.getE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 3rd row
	cout << " | " << NO.getSO() << " | " << NO.getS() << " | " << NO.getSE() << " | ";
	cout  << N.getSO() << " | " << N.getS() << " | " << N.getSE() << " | ";
	cout  << NE.getSO() << " | " << NE.getS() << " | " << NE.getSE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 4th row
	cout << " | " << O.getNO() << " | " << O.getN() << " | " << O.getNE() << " | ";
	cout  << C.getNO() << " | " << C.getN() << " | " << C.getNE() << " | ";
	cout  << E.getNO() << " | " << E.getN() << " | " << E.getNE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 5th row
	cout << " | " << O.getO() << " | " << O.getC() << " | " << O.getE() << " | ";
	cout  << C.getO() << " | " << C.getC() << " | " << C.getE() << " | ";
	cout  << E.getO() << " | " << E.getC() << " | " << E.getE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 6th row
	cout << " | " << O.getSO() << " | " << O.getS() << " | " << O.getSE() << " | ";
	cout  << C.getSO() << " | " << C.getS() << " | " << C.getSE() << " | ";
	cout  << E.getSO() << " | " << E.getS() << " | " << E.getSE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 7th row
	cout << " | " << SO.getNO() << " | " << SO.getN() << " | " << SO.getNE() << " | ";
	cout  << S.getNO() << " | " << S.getN() << " | " << S.getNE() << " | ";
	cout  << SE.getNO() << " | " << SE.getN() << " | " << SE.getNE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 8th row
	cout << " | " << SO.getO() << " | " << SO.getC() << " | " << SO.getE() << " | ";
	cout << S.getO() << " | " << S.getC() << " | " << S.getE() << " | ";
	cout  << SE.getO() << " | " << SE.getC() << " | " << SE.getE() << " | " << endl;
	cout << "  ------------------------------------" << endl;

	// 9th row
	cout << " | " << SO.getSO() << " | " << SO.getS() << " | " << SO.getSE() << " | ";
	cout << S.getSO() << " | " << S.getS() << " | " << S.getSE() << " | ";
	cout << SE.getSO() << " | " << SE.getS() << " | " << SE.getSE() << " | " << endl;
	cout << "  ------------------------------------" << endl;
	
}