#include "RowHolder.h"

RowHolder::RowHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & RowHolder :: G()
{
	return this->getCell1();
}

Cell & RowHolder::C()
{
	return this->getCell2();
}

Cell & RowHolder::D()
{
	return this->getCell3();
}