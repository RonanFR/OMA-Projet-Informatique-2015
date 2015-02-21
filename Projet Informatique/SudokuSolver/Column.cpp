#include "Column.h"


Column::Column(ColumnHolder columnHolder1, ColumnHolder columnHolder2, ColumnHolder columnHolder3)
	: NineHolder(columnHolder1, columnHolder2, columnHolder3)
{
}


Column::~Column()
{
}

Column & Column::operator =(Column const & Column)
{
	tripleHolder1 = Column.tripleHolder1;
	tripleHolder2 = Column.tripleHolder2;
	tripleHolder3 = Column.tripleHolder3;

	return *this;
}