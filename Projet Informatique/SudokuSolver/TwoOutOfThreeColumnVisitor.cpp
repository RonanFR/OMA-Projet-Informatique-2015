#include "TwoOutOfThreeColumnVisitor.h"

TwoOutOfThreeColumnVisitor::TwoOutOfThreeColumnVisitor()
{
}


TwoOutOfThreeColumnVisitor::~TwoOutOfThreeColumnVisitor()
{
}

bool TwoOutOfThreeColumnVisitor::Visit(Grid & iogrid) const
{
	/** This function uses blocks of three aligned regions (in column) to fill some empty cells. 
	* For each value between 1 and 9, two cases are considered here : the value is present only
	* once in the three regions or the value is present twice.
	*/
	bool isGridModified = false;
	int nThreeColumns;
	int nbRegionsInWhichPresent;

	for (unsigned char value = '1'; value <= '9'; value++) // For all possible values
	{
		for (nThreeColumns = 0; nThreeColumns < 3; nThreeColumns++)
		{
			nbRegionsInWhichPresent = (int)iogrid.getRegion(1,3 * nThreeColumns + 1).isValuePresent(value)
				+ (int)iogrid.getRegion(4,3 * nThreeColumns + 1).isValuePresent(value)
				+ (int)iogrid.getRegion(7,3 * nThreeColumns + 1).isValuePresent(value);
			
			if (nbRegionsInWhichPresent == 1)
			{
				isGridModified = this->VisitOneOutOfThree(iogrid, value, nThreeColumns);
			}
			else if (nbRegionsInWhichPresent == 2)
			{
				isGridModified = this->VisitTwoOutOfThree(iogrid, value, nThreeColumns);
			}
		}
	}
	return isGridModified;
}

bool TwoOutOfThreeColumnVisitor::VisitOneOutOfThree(Grid & iogrid, unsigned char value, int nThreeColumns) const
{
	bool isGridModified = false;
	int nRow;
	int nRegion;
	int nCol;
	int nCol1 = 1;
	int nCol2;
	int nPossibleCells;
	
	while (nCol1 < 3 && iogrid.getColumn(nCol1 + 3 * nThreeColumns).isValuePresent(value))
	{
		nCol1++;

	}
	nCol2 = nCol1 + 1;
	while (nCol2 < 3 && iogrid.getColumn(nCol2 + 3 * nThreeColumns).isValuePresent(value))
	{
		nCol2++;

	}
	for (nRegion = 0; nRegion < 3; nRegion++)
	{
		if (!iogrid.getRegion(3 * nRegion + 1, 1 + 3 * nThreeColumns).isValuePresent(value))
		{
			nRow = 1;
			nCol = 1;

			int j = 1;
			nPossibleCells = 0;

			while (j <= 3 && nPossibleCells < 2)
			{
				if (iogrid.getColumn(nCol1 + 3 * nThreeColumns).get(3 * nRegion + j).isEmpty() && !iogrid.getRow(3 * nRegion + j).isValuePresent(value))
				{
					nRow = j;
					nPossibleCells++;
					nCol = nCol1;
				}
				j++;

			}
			j = 1;
			while (j <= 3 && nPossibleCells < 2)
			{
				if (iogrid.getColumn(nCol2 + 3 * nThreeColumns).get(3 * nRegion + j).isEmpty() && !iogrid.getRow(3 * nRegion + j).isValuePresent(value))
				{
					nRow = j;
					nPossibleCells++;
					nCol = nCol2;
				}
				j++;

			}
			if (nPossibleCells == 1)
			{
				iogrid.getColumn(nCol + 3 * nThreeColumns).get(3 * nRegion + nRow) = value;
				isGridModified = true;
			}
		}

	}

	return isGridModified;
}

bool TwoOutOfThreeColumnVisitor::VisitTwoOutOfThree(Grid & iogrid, unsigned char value, int nThreeColumns) const
{
	bool isGridModified = false;
	int nRow;
	int nRegion;
	int nCol = 1;
	int nPossibleCells;

	while (nCol < 3 && iogrid.getColumn(3 * nThreeColumns + nCol).isValuePresent(value))
	{
		nCol++;
	}

	nRegion = 0;
	while (nRegion < 2 && iogrid.getRegion(3 * nRegion + 1, 3 * nThreeColumns + nCol).isValuePresent(value))
	{
		nRegion++;
	}

	int j = 1;
	nRow = 1;
	nPossibleCells = 0;
	while (j <= 3 && nPossibleCells < 2)
	{
		if (iogrid.getColumn(3 * nThreeColumns + nCol).get(3 * nRegion + j).isEmpty()
			&& !iogrid.getRow(3 * nRegion + j).isValuePresent(value))
		{
			nRow = j;
			nPossibleCells++;
		}
		j++;
	}

	if (nPossibleCells == 1)
	{
		iogrid.getColumn(3 * nThreeColumns + nCol).get(3 * nRegion + nRow) = value;
		isGridModified = true;
	}

	return isGridModified;
}