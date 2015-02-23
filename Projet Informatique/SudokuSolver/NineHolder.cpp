#include "NineHolder.h"


NineHolder::NineHolder(TripleHolder tripleHolder1, TripleHolder tripleHolder2, TripleHolder tripleHolder3)
	: tripleHolder1(tripleHolder1), tripleHolder2(tripleHolder2), tripleHolder3(tripleHolder3)
{
}


NineHolder::~NineHolder()
{
}

bool NineHolder::isValuePresent(const unsigned char ivalue) const
{
	return tripleHolder1.isValuePresent(ivalue) || tripleHolder2.isValuePresent(ivalue) || tripleHolder3.isValuePresent(ivalue);
}

Cell & NineHolder::get(int i) const
{
	switch (i)
	{
	case 1:
		return tripleHolder1.getCell1();
	case 2:
		return tripleHolder1.getCell2();
	case 3:
		return tripleHolder1.getCell3();
	case 4:
		return tripleHolder2.getCell1();
	case 5:
		return tripleHolder2.getCell2();
	case 6:
		return tripleHolder2.getCell3();
	case 7:
		return tripleHolder3.getCell1();
	case 8:
		return tripleHolder3.getCell2();
	case 9:
		return tripleHolder3.getCell3();
	}
}

set < int > NineHolder::getEmptyCellsIndices() const
{
	set < int > emptyCellsIndices;
	for (int i = 1; i <= 9; i++)
	{
		if (this->get(i).isEmpty())
		{
			emptyCellsIndices.insert(i);
		}
	}
	return emptyCellsIndices;
}

set <unsigned char>  NineHolder::flagValues(ValueEliminator valueEliminator) const
{
	for (int i = 1; i <= 9; i++)
	{
		valueEliminator.flag(this->get(i));
	}
	if (valueEliminator.availableValues()==0)
	{
		set<unsigned char> emptySet;
		return  emptySet;
	}
	else
	{
		return valueEliminator.availableValue();
	}
}

int  NineHolder::getNbEmptyCells() const 
{
	return tripleHolder1.getNbEmptyCells() + tripleHolder2.getNbEmptyCells() + tripleHolder3.getNbEmptyCells();
}

bool  NineHolder::isConsistent() const
{
	ValueEliminator valueEliminator;
	for (int i = 1; i <= 9; i++)
	{
		valueEliminator.flag(this->get(i));
	}
	if (valueEliminator.availableValues() != this->getNbEmptyCells())
	{
		return false;
	}
	return true;
}

