# include "TripleHolder.h"

TripleHolder::TripleHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:cell1(cell1), cell2(cell2), cell3(cell3)
{
}

Cell & TripleHolder::getCell1()const
{
	return cell1;
}

Cell & TripleHolder::getCell2()const
{
	return cell2;
}

Cell & TripleHolder::getCell3()const
{
	return cell3;
}

int TripleHolder::getNbEmptyCells() const
{
	return cell1.isEmpty() + cell2.isEmpty() + cell3.isEmpty();
}

Cell & TripleHolder::getEmptyCell() const
{
	return (cell1.isEmpty()) ? cell1 : ((cell2.isEmpty()) ? cell2 : cell3);
}

int TripleHolder::getSumCells() const
{
	return (char)cell1 * (int)!(cell1.isEmpty()) + (char)cell2* (int)!(cell2.isEmpty()) + (char)cell3 * (int)!(cell3.isEmpty());
}

set <unsigned char> TripleHolder::flagValues(ValueEliminator valueEliminator) const
{
	valueEliminator.flag(this->getCell1());
	valueEliminator.flag(this->getCell2());
	valueEliminator.flag(this->getCell3());
	
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

bool TripleHolder::isValuePresent(const unsigned char ivalue) const
{
	ValueEliminator valueEliminator1;
	set <unsigned char> flagValues = this->flagValues(valueEliminator1);
	return flagValues.find(ivalue) == flagValues.end();
}

TripleHolder & TripleHolder::operator = (TripleHolder const tripleHolder)
{
	cell1 = tripleHolder.cell1;
	cell2 = tripleHolder.cell2;
	cell3 = tripleHolder.cell3;

	return *this;
}