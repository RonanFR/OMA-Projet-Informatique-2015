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

	lastCellFinder1.fill();
	lastCellFinder2.fill();
	lastCellFinder3.fill();
	lastCellFinder4.fill();
	lastCellFinder5.fill();
	lastCellFinder6.fill();
	lastCellFinder7.fill();
	lastCellFinder8.fill();
	lastCellFinder9.fill();

}