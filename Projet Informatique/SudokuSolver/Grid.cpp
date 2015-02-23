# include"Grid.h"
# include <stdexcept>
# include<iostream>
# include <math.h>
# include "GridSolver.h"
# include "OnlySquareVisitor.h"


Grid::Grid(Region NO, Region N, Region NE, Region O, Region C, 
	Region E, Region SO, Region S, Region SE)
	:N(N), NO(NO), NE(NE), S(S), E(E), O(O), C(C), SO(SO), SE(SE),
	row1(this->getNO().TopRow(), this->getN().TopRow(), this->getNE().TopRow()),
	row2(this->getNO().MiddleRow(), this->getN().MiddleRow(), this->getNE().MiddleRow()),
	row3(this->getNO().BottomRow(), this->getN().BottomRow(), this->getNE().BottomRow()),
	row4(this->getO().TopRow(), this->getC().TopRow(), this->getE().TopRow()),
	row5(this->getO().MiddleRow(), this->getC().MiddleRow(), this->getE().MiddleRow()),
	row6(this->getO().BottomRow(), this->getC().BottomRow(), this->getE().BottomRow()),
	row7(this->getSO().TopRow(), this->getS().TopRow(), this->getSE().TopRow()),
	row8(this->getSO().MiddleRow(), this->getS().MiddleRow(), this->getSE().MiddleRow()),
	row9(this->getSO().BottomRow(), this->getS().BottomRow(), this->getSE().BottomRow()),
	column1(this->getNO().LeftColumn(), this->getO().LeftColumn(), this->getSO().LeftColumn()),
	column2(this->getNO().MiddleColumn(), this->getO().MiddleColumn(), this->getSO().MiddleColumn()),
	column3(this->getNO().RightColumn(), this->getO().RightColumn(), this->getSO().RightColumn()),
	column4(this->getN().LeftColumn(), this->getC().LeftColumn(), this->getS().LeftColumn()),
	column5(this->getN().MiddleColumn(), this->getC().MiddleColumn(), this->getS().MiddleColumn()),
	column6(this->getN().RightColumn(), this->getC().RightColumn(), this->getS().RightColumn()),
	column7(this->getNE().LeftColumn(), this->getE().LeftColumn(), this->getSE().LeftColumn()),
	column8(this->getNE().MiddleColumn(), this->getE().MiddleColumn(), this->getSE().MiddleColumn()),
	column9(this->getNE().RightColumn(), this->getE().RightColumn(), this->getSE().RightColumn())

{
}

bool Grid::isFull()
{
	return this->getN().isFull() && this->getS().isFull() && this->getE().isFull() && this->getO().isFull()
		&& this->getNO().isFull() && this->getNE().isFull() && this->getSO().isFull() && this->getSE().isFull() && this->getC().isFull();
}

RegionHolder  Grid::getN()
{
	
	return RegionHolder(N);
}

RegionHolder  Grid::getS() 
{
	
	return RegionHolder(S);
}

RegionHolder  Grid::getE() 
{
	
	return RegionHolder(E);
}

RegionHolder  Grid::getO() 
{
	
	return RegionHolder(O);
}

RegionHolder  Grid::getC() 
{
	
	
	return RegionHolder(C);
}

RegionHolder  Grid::getNE()
{
	
	return RegionHolder(NE);
}

RegionHolder  Grid::getNO()
{
	
	return RegionHolder(NO);
}

RegionHolder  Grid::getSE() 
{
	
	return RegionHolder(SE);
}

RegionHolder  Grid::getSO() 
{
	
	return RegionHolder(SO);
}

Column Grid::getColumn(const int j) const
{
	switch (j)
	{
	case 1:{
		return column1;
	}
	case 2:{
		return column2;
	}
	case 3:{
		return column3;
	}
	case 4:{
		return column4;
	}
	case 5:{
		return column5;
	}
	case 6:{
		return column6;
	}
	case 7:{
		return column7;
	}
	case 8:{
		return column8;
	}
	case 9:{
		return column9;
	}
	}
}

Row Grid::getRow(int i) const
{
	switch (i)
	{
	case 1:{
		return row1;
	}
	case 2:{
		return row2;
	}
	case 3:{
		return row3;
	}
	case 4:{
		return row4;
	}
	case 5:{
		return row5;
	}
	case 6:{
		return row6;
	}
	case 7:{
		return row7;
	}
	case 8:{
		return row8;
	}
	case 9:{
		return row9;
	}
	}
}

RegionHolder  Grid::getRegion(const int i, const int j)
{
	switch ((int)ceil((double)i / 3.0) + (int)ceil((double)j / 3.0) * 3)
	{
	case 4:
	{
		return this->getNO();
	}
	case 5:
	{
		return this->getO();
	}
	case 6:
	{
		return this->getSO();
	}
	case 7:
	{
		return this->getN();
	}
	case 8:
	{
		return this->getC();
	}
	case 9:
	{
		return this->getS();
	}
	case 10:
	{
		return this->getNE();
	}
	case 11:
	{
		return this->getE();
	}
	case 12:
	{
		return this->getSE();
	}
	}
}

bool Grid::isConsistent() const
{
	return row1.isConsistent() && row2.isConsistent() && row3.isConsistent() && row4.isConsistent() && row5.isConsistent()
		&& row6.isConsistent() && row7.isConsistent() && row8.isConsistent() && row9.isConsistent()
		&& column1.isConsistent() && column2.isConsistent() && column3.isConsistent() && column4.isConsistent() && column5.isConsistent() 
		&& column6.isConsistent() && column7.isConsistent() && column8.isConsistent() && column9.isConsistent()
		&& N.isConsistent() && NE.isConsistent() && NO.isConsistent() && O.isConsistent() && E.isConsistent()
		&& C.isConsistent() && SO.isConsistent() && SE.isConsistent() && S.isConsistent();
}

void Grid::Solve()
{
	/** This function solves any solvable Sodoku grid using Gridsolver and the backtracking method.
	* If the Sodoku grid is not solvable this function throws a logic error exception.
	*/
	GridSolver gridsolver;
	gridsolver.solve(*this);

	if (this->isFull() && this->isConsistent())
	{
		return;
	}
	else if (!this->isConsistent())
	{
		throw logic_error("Grid not consistent");
	}
	else
	{
		OnlySquareVisitor onlySquareVisitor;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if ((this->getRow(i)).get(j).isEmpty()) // Test all cells that are empty with all possible values
				{
					set<unsigned char> possibleValues = onlySquareVisitor.findPossibleValues(*this, i, j); // find possible assumptions
					set<unsigned char>::iterator it = possibleValues.begin();
					while (it != possibleValues.end()) // test all possible assumptions
					{
						try
						{
							Grid copyGrid = Grid(this->NO, this->N, this->NE, this->O, this->C,
								this->E, this->SO, this->S, this->SE);
							copyGrid.getRow(i).get(j) = *it; // make an assumption
							copyGrid.Solve();
							*this = copyGrid;
							return;
						}
						catch (logic_error & le) // if the assumption led to some error, we need to look for other assumptions
						{
						}
						it++;
					}
					throw logic_error("Grid not consistent"); // if all values tested failed, throw an exception
				}
			}
		}
	}
}



Grid & Grid::operator = (Grid const & iogrid)
{
	C = iogrid.C;
	O = iogrid.O;
	E = iogrid.E;
	N = iogrid.N;
	NO = iogrid.NO;
	NE = iogrid.NE;
	S = iogrid.S;
	SO = iogrid.SO;
	SE = iogrid.SE;

	row1 = iogrid.row1;
	row2 = iogrid.row2;
	row3 = iogrid.row3;
	row4 = iogrid.row4;
	row4 = iogrid.row5;
	row4 = iogrid.row6;
	row4 = iogrid.row7;
	row4 = iogrid.row8;
	row4 = iogrid.row9;

	column1 = iogrid.column1;
	column2 = iogrid.column2;
	column3 = iogrid.column3;
	column4 = iogrid.column4;
	column5 = iogrid.column5;
	column6 = iogrid.column6;
	column7 = iogrid.column7;
	column8 = iogrid.column8;
	column9 = iogrid.column9;

	return *this;
}

void Grid::dispGrid()
{
	/** This function displays an easy-to-read Sodoku grid.
	*/
	cout << "  -----------------------" << endl;

	// 1st row
	cout << " | " << NO.getNO() << " " << NO.getN() << " " << NO.getNE() << " | ";
	cout << N.getNO() << " " << N.getN() << " " << N.getNE() << " | ";
	cout << NE.getNO() << " " << NE.getN() << " " << NE.getNE() << " | " << endl;

	// 2nd row
	cout << " | " << NO.getO() << " " << NO.getC() << " " << NO.getE() << " | ";
	cout << N.getO() << " " << N.getC() << " " << N.getE() << " | ";
	cout << NE.getO() << " " << NE.getC() << " " << NE.getE() << " | " << endl;

	// 3rd row
	cout << " | " << NO.getSO() << " " << NO.getS() << " " << NO.getSE() << " | ";
	cout << N.getSO() << " " << N.getS() << " " << N.getSE() << " | ";
	cout << NE.getSO() << " " << NE.getS() << " " << NE.getSE() << " | " << endl;
	cout << "  -----------------------" << endl;

	// 4th row
	cout << " | " << O.getNO() << " " << O.getN() << " " << O.getNE() << " | ";
	cout << C.getNO() << " " << C.getN() << " " << C.getNE() << " | ";
	cout << E.getNO() << " " << E.getN() << " " << E.getNE() << " | " << endl;

	// 5th row
	cout << " | " << O.getO() << " " << O.getC() << " " << O.getE() << " | ";
	cout << C.getO() << " " << C.getC() << " " << C.getE() << " | ";
	cout << E.getO() << " " << E.getC() << " " << E.getE() << " | " << endl;

	// 6th row
	cout << " | " << O.getSO() << " " << O.getS() << " " << O.getSE() << " | ";
	cout << C.getSO() << " " << C.getS() << " " << C.getSE() << " | ";
	cout << E.getSO() << " " << E.getS() << " " << E.getSE() << " | " << endl;
	cout << "  -----------------------" << endl;

	// 7th row
	cout << " | " << SO.getNO() << " " << SO.getN() << " " << SO.getNE() << " | ";
	cout << S.getNO() << " " << S.getN() << " " << S.getNE() << " | ";
	cout << SE.getNO() << " " << SE.getN() << " " << SE.getNE() << " | " << endl;

	// 8th row
	cout << " | " << SO.getO() << " " << SO.getC() << " " << SO.getE() << " | ";
	cout << S.getO() << " " << S.getC() << " " << S.getE() << " | ";
	cout << SE.getO() << " " << SE.getC() << " " << SE.getE() << " | " << endl;

	// 9th row
	cout << " | " << SO.getSO() << " " << SO.getS() << " " << SO.getSE() << " | ";
	cout << S.getSO() << " " << S.getS() << " " << S.getSE() << " | ";
	cout << SE.getSO() << " " << SE.getS() << " " << SE.getSE() << " | " << endl;
	cout << "  -----------------------" << endl;
	
}