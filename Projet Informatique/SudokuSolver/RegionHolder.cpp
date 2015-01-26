#include "RegionHolder.h"


RegionHolder::RegionHolder(Region & region)
	:N(region.getN()), S(region.getS()), E(region.getE()), O(region.getO()), NE(region.getNE()), NO(region.getNO()), SE(region.getSE()), SO(region.getSO()), C(region.getC())
{

}


Cell & RegionHolder::getN()
{
	return N;
}

Cell & RegionHolder::getS()
{
	return S;
}

Cell & RegionHolder::getE()
{
	return E;
}

Cell & RegionHolder::getO()
{
	return O;
}

Cell & RegionHolder::getC()
{
	return C;
}

Cell & RegionHolder::getNE()
{
	return NE;
}

Cell & RegionHolder::getNO()
{
	return NO;
}

Cell & RegionHolder::getSE()
{
	return SE;
}

Cell & RegionHolder::getSO()
{
	return SO;
}


RowHolder RegionHolder::TopRow()
{
	RowHolder toprow(this->getNO(), this->getN(), this->getNE());

	return toprow;
}

RowHolder RegionHolder::MiddleRow()
{
	RowHolder middlerow(this->getO(), this->getC(), this->getE());

	return middlerow;
}

RowHolder RegionHolder::BottomRow()
{
	RowHolder bottomrow(this->getSO(), this->getS(), this->getSE());

	return bottomrow;
}

ColumnHolder RegionHolder::LeftColumn()
{
	ColumnHolder leftcolumn(this->getNO(), this->getC(), this->getSO());
	
	return leftcolumn;

}

ColumnHolder RegionHolder::RightColumn()
{
	ColumnHolder rightcolumn(this->getNE(), this->getE(), this->getSE());

	return rightcolumn;

}

ColumnHolder RegionHolder::MiddleColumn()
{
	ColumnHolder rightcolumn(this->getN(), this->getC(), this->getS());

	return rightcolumn;

}
