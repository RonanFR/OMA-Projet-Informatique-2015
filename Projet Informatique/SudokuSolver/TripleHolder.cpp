# include "TripleHolder.h"

TripleHolder::TripleHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:cell1(cell1), cell2(cell2), cell3(cell3)
{
}

Cell & TripleHolder::getCell1()
{
	return cell1;
}

Cell & TripleHolder::getCell2()
{
	return cell2;
}

Cell & TripleHolder::getCell3()
{
	return cell3;
}