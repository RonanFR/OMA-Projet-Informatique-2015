#include "RegionHolder.h"


RegionHolder::RegionHolder(Region &  region)
	:N(region.getN()), S(region.getS()), E(region.getE()), 
	O(region.getO()), NE(region.getNE()), NO(region.getNO()), 
	SE(region.getSE()), SO(region.getSO()), C(region.getC())
{

}


Cell & RegionHolder::getN()const
{
	return N;
}

Cell & RegionHolder::getS()const
{
	return S;
}

Cell & RegionHolder::getE()const
{
	return E;
}

Cell & RegionHolder::getO()const
{
	return O;
}

Cell & RegionHolder::getC()const
{
	return C;
}

Cell & RegionHolder::getNE()const
{
	return NE;
}

Cell & RegionHolder::getNO()const
{
	return NO;
}

Cell & RegionHolder::getSE()const
{
	return SE;
}

Cell & RegionHolder::getSO()const
{
	return SO;
}


RowHolder RegionHolder::TopRow() const
{
	RowHolder toprow(this->getNO(), this->getN(), this->getNE());

	return toprow;
}

RowHolder RegionHolder::MiddleRow()const
{
	RowHolder middlerow(this->getO(), this->getC(), this->getE());

	return middlerow;
}

RowHolder RegionHolder::BottomRow()const
{
	RowHolder bottomrow(this->getSO(), this->getS(), this->getSE());

	return bottomrow;
}

ColumnHolder RegionHolder::LeftColumn()const
{
	ColumnHolder leftcolumn(this->getNO(), this->getO(), this->getSO());
	
	return leftcolumn;

}

ColumnHolder RegionHolder::RightColumn()const
{
	ColumnHolder rightcolumn(this->getNE(), this->getE(), this->getSE());

	return rightcolumn;

}

ColumnHolder RegionHolder::MiddleColumn()const
{
	ColumnHolder rightcolumn(this->getN(), this->getC(), this->getS());

	return rightcolumn;

}

set <unsigned char>  RegionHolder::flagValues(ValueEliminator valueEliminator)
{
	valueEliminator.flag(this->getNO());
	valueEliminator.flag(this->getN());
	valueEliminator.flag(this->getNE());

	valueEliminator.flag(this->getE());
	valueEliminator.flag(this->getC());
	valueEliminator.flag(this->getO());
	
	valueEliminator.flag(this->getSO());
	valueEliminator.flag(this->getS());
	valueEliminator.flag(this->getSE());

	if (valueEliminator.availableValues() == 0)
	{
		set<unsigned char> emptySet;
		return  emptySet;
	}
	else
	{
		return valueEliminator.availableValue();
	}
}

bool RegionHolder::isValuePresent(const unsigned char ivalue)
{
	ValueEliminator valueEliminator1;
	set <unsigned char> flagValues = this->flagValues(valueEliminator1);
	return flagValues.find(ivalue) == flagValues.end();
}

bool RegionHolder::isFull() const
{
	return !this->getN().isEmpty() && !this->getS().isEmpty() && !this->getE().isEmpty() && !this->getO().isEmpty()
		&& !this->getNO().isEmpty() && !this->getNE().isEmpty() && !this->getSO().isEmpty() && !this->getSE().isEmpty() && !this->getC().isEmpty();
}