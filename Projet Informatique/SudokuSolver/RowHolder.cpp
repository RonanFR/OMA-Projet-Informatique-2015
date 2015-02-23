#include "RowHolder.h"

RowHolder::RowHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & RowHolder::G() const
{
	return cell1;
}

Cell & RowHolder::C() const
{
	return cell2;
}

Cell & RowHolder::D() const
{
	return cell3;
}