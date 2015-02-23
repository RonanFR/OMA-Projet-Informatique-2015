#include "ColumnHolder.h"

ColumnHolder::ColumnHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & ColumnHolder::T() const
{
	return cell1;
}

Cell & ColumnHolder::C() const
{
	return cell2;
}

Cell & ColumnHolder::B() const
{
	return cell3;
}