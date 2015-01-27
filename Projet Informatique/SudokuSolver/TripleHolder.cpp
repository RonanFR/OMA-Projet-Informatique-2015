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