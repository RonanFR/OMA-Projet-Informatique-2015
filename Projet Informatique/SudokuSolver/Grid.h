# pragma once
# include "RegionHolder.h"
# include "Column.h"
# include "Row.h"
# include <list>

using namespace std;

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

class IVisitor;
class SUDOKUSOLVER_API Grid
{
public:
	Grid(Region NO, Region N, Region NE, Region O, Region C,
		Region E, Region SO, Region S, Region SE);
	void Accept(IVisitor & visitor);
	void dispGrid();
	void Solve();

	RegionHolder getN() ;
	RegionHolder getS() ;
	RegionHolder getE() ;
	RegionHolder getO() ;
	RegionHolder getNE() ;
	RegionHolder getNO() ;
	RegionHolder getSE() ;
	RegionHolder getSO() ;
	RegionHolder getC() ;

	Column getColumn(const int j) const;
	Row getRow(const int i) const;
	RegionHolder getRegion(const int i, const int j);
	bool isFull();
	bool isConsistent() const;
	Grid & operator =(Grid const & iogrid);

private:
	Region N;
	Region S;
	Region E;
	Region O;
	Region NE;
	Region SE;
	Region NO;
	Region SO;
	Region C;

	Row row1;
	Row row2;
	Row row3;
	Row row4;
	Row row5;
	Row row6;
	Row row7;
	Row row8;
	Row row9;

	Column column1;
	Column column2;
	Column column3;
	Column column4;
	Column column5;
	Column column6;
	Column column7;
	Column column8;
	Column column9;

};