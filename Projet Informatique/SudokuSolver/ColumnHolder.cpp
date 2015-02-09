#include "ColumnHolder.h"

ColumnHolder::ColumnHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & ColumnHolder::T()
{
	return cell1;
}

Cell & ColumnHolder::C()
{
	return cell2;
}

Cell & ColumnHolder::B()
{
	return cell3;
}