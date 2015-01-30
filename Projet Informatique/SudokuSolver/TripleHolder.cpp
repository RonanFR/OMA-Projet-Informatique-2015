# include "TripleHolder.h"

TripleHolder::TripleHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:cell1(cell1), cell2(cell2), cell3(cell3), 
	emptyCell((cell1.isEmpty()) ? cell1 : ((cell2.isEmpty())?cell2:cell3))
{
	sumCells = (char)cell1 * (int)!(cell1.isEmpty()) + (char)cell2* (int)!(cell2.isEmpty()) + (char)cell3 * (int)!(cell3.isEmpty());
	nbEmptyCells = (int)cell1.isEmpty() + (int)cell2.isEmpty() + (int)cell3.isEmpty();
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

int TripleHolder::getNbEmptyCells()
{
	return nbEmptyCells;
}

Cell & TripleHolder::getEmptyCell()
{
	return emptyCell;
}

int TripleHolder::getSumCells()
{
	return sumCells;
}