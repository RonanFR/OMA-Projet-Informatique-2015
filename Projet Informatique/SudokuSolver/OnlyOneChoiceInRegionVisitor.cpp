#include "OnlyOneChoiceInRegionVisitor.h"


OnlyOneChoiceInRegionVisitor::OnlyOneChoiceInRegionVisitor()
{
}


OnlyOneChoiceInRegionVisitor::~OnlyOneChoiceInRegionVisitor()
{
}
bool OnlyOneChoiceInRegionVisitor::Visit(Grid & iogrid) const
{
	LastCellFinder lastCellFinder1(iogrid.getNO().TopRow(), iogrid.getNO().MiddleRow(), iogrid.getNO().BottomRow());
	LastCellFinder lastCellFinder2(iogrid.getN().TopRow(), iogrid.getN().MiddleRow(), iogrid.getN().BottomRow());
	LastCellFinder lastCellFinder3(iogrid.getNE().TopRow(), iogrid.getNE().MiddleRow(), iogrid.getNE().BottomRow());

	LastCellFinder lastCellFinder4(iogrid.getO().TopRow(), iogrid.getO().MiddleRow(), iogrid.getO().BottomRow());
	LastCellFinder lastCellFinder5(iogrid.getC().TopRow(), iogrid.getC().MiddleRow(), iogrid.getC().BottomRow());
	LastCellFinder lastCellFinder6(iogrid.getE().TopRow(), iogrid.getE().MiddleRow(), iogrid.getE().BottomRow());

	LastCellFinder lastCellFinder7(iogrid.getNO().TopRow(), iogrid.getNO().MiddleRow(), iogrid.getNO().BottomRow());
	LastCellFinder lastCellFinder8(iogrid.getNO().TopRow(), iogrid.getNO().MiddleRow(), iogrid.getNO().BottomRow());
	LastCellFinder lastCellFinder9(iogrid.getNO().TopRow(), iogrid.getNO().MiddleRow(), iogrid.getNO().BottomRow());

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