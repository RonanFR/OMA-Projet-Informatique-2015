#include "Region.h"
# include <stdexcept>
#include<iostream>

Region::Region(){

}

Region::Region(string chaine)
{
	if (chaine.size() != 9)
	{
		throw length_error("Une region doit contenir exactement 9 celules");
	}
	else
	{

		NO = Cell(chaine[0]);
		N = Cell(chaine[1]);
		NE = Cell(chaine[2]);
		O = Cell(chaine[3]);
		C = Cell(chaine[4]);
		E = Cell(chaine[5]);
		SO = Cell(chaine[6]);
		S = Cell(chaine[7]);
		SE = Cell(chaine[8]);

	}
}

bool Region::isFull()
{
	return !(NO.isEmpty() || N.isEmpty() || NE.isEmpty() ||
		O.isEmpty() || C.isEmpty() || E.isEmpty() ||
		SO.isEmpty() || S.isEmpty() || SE.isEmpty());
}

Cell & Region::getN()
{
	return N;
}

Cell & Region::getS()
{
	return S;
}

Cell & Region::getE()
{
	return E;
}

Cell & Region::getO()
{
	return O;
}

Cell & Region::getC()
{
	return C;
}

Cell & Region::getNE()
{
	return NE;
}

Cell & Region::getNO()
{
	return NO;
}

Cell & Region::getSE()
{
	return SE;
}

Cell & Region::getSO()
{
	return SO;
}