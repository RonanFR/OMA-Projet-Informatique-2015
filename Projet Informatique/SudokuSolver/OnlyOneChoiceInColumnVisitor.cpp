#include "OnlyOneChoiceInColumnVisitor.h"


OnlyOneChoiceInColumnVisitor::OnlyOneChoiceInColumnVisitor()
{
}


OnlyOneChoiceInColumnVisitor::~OnlyOneChoiceInColumnVisitor()
{
}

bool OnlyOneChoiceInColumnVisitor::Visit(Grid & ioGrid)const
{
	LastCellFinder lastCellFinder1(ioGrid.getNO().LeftColumn(), ioGrid.getO().LeftColumn(), ioGrid.getSO().LeftColumn());
	LastCellFinder lastCellFinder2(ioGrid.getNO().MiddleColumn(), ioGrid.getO().MiddleColumn(), ioGrid.getSO().MiddleColumn());
	LastCellFinder lastCellFinder3(ioGrid.getNO().RightColumn(), ioGrid.getO().RightColumn(), ioGrid.getSO().RightColumn());

	LastCellFinder lastCellFinder4(ioGrid.getN().LeftColumn(), ioGrid.getC().LeftColumn(), ioGrid.getS().LeftColumn());
	LastCellFinder lastCellFinder5(ioGrid.getN().MiddleColumn(), ioGrid.getC().MiddleColumn(), ioGrid.getS().MiddleColumn());
	LastCellFinder lastCellFinder6(ioGrid.getN().RightColumn(), ioGrid.getC().RightColumn(), ioGrid.getS().RightColumn());


	LastCellFinder lastCellFinder7(ioGrid.getNE().LeftColumn(), ioGrid.getE().LeftColumn(), ioGrid.getSE().LeftColumn());
	LastCellFinder lastCellFinder8(ioGrid.getNE().MiddleColumn(), ioGrid.getE().MiddleColumn(), ioGrid.getSE().MiddleColumn());
	LastCellFinder lastCellFinder9(ioGrid.getNE().RightColumn(), ioGrid.getE().RightColumn(), ioGrid.getSE().RightColumn());

	bool bool1 = lastCellFinder1.fill();
	bool bool2 = lastCellFinder2.fill();
	bool bool3 = lastCellFinder3.fill();
	bool bool4 = lastCellFinder4.fill();
	bool bool5 = lastCellFinder5.fill();
	bool bool6 = lastCellFinder6.fill();
	bool bool7 = lastCellFinder7.fill();
	bool bool8 = lastCellFinder8.fill();
	bool bool9 = lastCellFinder9.fill();

	return bool1 || bool2 || bool3 || bool4 || bool5 || bool6 || bool7 || bool8 || bool9;
}