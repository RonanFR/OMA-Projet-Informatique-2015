#include "ColumnHolder.h"

ColumnHolder::ColumnHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & ColumnHolder::T()
{
	return this->getCell1();
}

Cell & ColumnHolder::C()
{
	return this->getCell2();
}

Cell & ColumnHolder::B()
{
	return this->getCell3();
}