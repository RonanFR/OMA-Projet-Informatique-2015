#include "Row.h"


Row::Row(RowHolder rowHolder1, RowHolder rowHolder2, RowHolder rowHolder3)
	:NineHolder(rowHolder1, rowHolder2, rowHolder3)
{
}


Row::~Row()
{
}

Row & Row::operator =(Row const & row)
{
	tripleHolder1 = row.tripleHolder1;
	tripleHolder2 = row.tripleHolder2;
	tripleHolder3 = row.tripleHolder3;

	return *this;
}
