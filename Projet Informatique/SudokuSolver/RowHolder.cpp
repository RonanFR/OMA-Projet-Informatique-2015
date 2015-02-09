#include "RowHolder.h"

RowHolder::RowHolder(Cell & cell1, Cell & cell2, Cell & cell3)
	:TripleHolder(cell1, cell2, cell3)
{

}

Cell & RowHolder :: G()
{
	return cell1;
}

Cell & RowHolder::C()
{
	return cell2;
}

Cell & RowHolder::D()
{
	return cell3;
}