#include "OnlyOneChoiceInRowVisitor.h"
# include "LastCellFinder.h"

OnlyOneChoiceInRowVisitor::OnlyOneChoiceInRowVisitor()
{
}


OnlyOneChoiceInRowVisitor::~OnlyOneChoiceInRowVisitor()
{
}

bool OnlyOneChoiceInRowVisitor::Visit(Grid & iogrid) const
{
	LastCellFinder lastCellFinder1(iogrid.getNO().TopRow(), iogrid.getN().TopRow(), iogrid.getNE().TopRow());
	LastCellFinder lastCellFinder2(iogrid.getNO().MiddleRow(), iogrid.getN().MiddleRow(), iogrid.getNE().MiddleRow());
	LastCellFinder lastCellFinder3(iogrid.getNO().BottomRow(), iogrid.getN().BottomRow(), iogrid.getNE().BottomRow());
	LastCellFinder lastCellFinder4(iogrid.getO().TopRow(), iogrid.getC().TopRow(), iogrid.getE().TopRow());
	LastCellFinder lastCellFinder5(iogrid.getO().MiddleRow(), iogrid.getC().MiddleRow(), iogrid.getE().MiddleRow());
	LastCellFinder lastCellFinder6(iogrid.getO().BottomRow(), iogrid.getC().BottomRow(), iogrid.getE().BottomRow());
	LastCellFinder lastCellFinder7(iogrid.getSO().TopRow(), iogrid.getS().TopRow(), iogrid.getSE().TopRow());
	LastCellFinder lastCellFinder8(iogrid.getSO().MiddleRow(), iogrid.getS().MiddleRow(), iogrid.getSE().MiddleRow());
	LastCellFinder lastCellFinder9(iogrid.getSO().BottomRow(), iogrid.getS().BottomRow(), iogrid.getSE().BottomRow());

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