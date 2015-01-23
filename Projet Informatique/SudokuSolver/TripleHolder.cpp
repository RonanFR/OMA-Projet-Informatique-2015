#include "TripleHolder.h"

TripleHoder::TripleHoder(Cell & cell1, Cell & cell2, Cell & cell3)
	:cell1(cell1), cell2(cell2), cell3(cell3)
{

}

Cell & TripleHoder::getCell1()
{
	return cell1;
}

Cell & TripleHoder::getCell2()
{
	return cell2;
}

Cell & TripleHoder::getCell3()
{
	return cell3;
}