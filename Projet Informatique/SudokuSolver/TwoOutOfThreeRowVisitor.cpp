#include "TwoOutOfThreeRowVisitor.h"


TwoOutOfThreeRowVisitor::TwoOutOfThreeRowVisitor()
{
}


TwoOutOfThreeRowVisitor::~TwoOutOfThreeRowVisitor()
{
}

bool TwoOutOfThreeRowVisitor::Visit(Grid & iogrid) const
{
	bool isGridModified = false;
	int nThreeRows;
	int nRow;
	int nRow1;
	int nRow2;
	int nRegion;
	int nCol;
	int nPossibleCells;
	int nbRegionsInWhichPresent;

	for (unsigned char value = '1'; value <= '9'; value++) // For all possible values
	{
		for (nThreeRows = 0; nThreeRows < 3; nThreeRows++)
		{
			nbRegionsInWhichPresent = (int)iogrid.getRegion(3 * nThreeRows+1,1).isValuePresent(value)
				+ (int)iogrid.getRegion(3 * nThreeRows + 1, 4).isValuePresent(value)
				+ (int)iogrid.getRegion(3 * nThreeRows + 1, 7).isValuePresent(value);
			if (nbRegionsInWhichPresent == 1)
			{
				nRow1 = 1;
				while (nRow1 < 3 && iogrid.getRow(nRow1 + 3 * nThreeRows).isValuePresent(value))
				{
					nRow1++;
				}
				nRow2 = nRow1+1;
				while (nRow2 < 3 && iogrid.getRow(nRow2 + 3 * nThreeRows).isValuePresent(value))
				{
					nRow2++;
				}
				for (nRegion = 0; nRegion < 3; nRegion++)
				{
					if (!iogrid.getRegion(1 + 3 * nThreeRows, 3 * nRegion + 1).isValuePresent(value))
					{
						nCol = 1;

						int j = 1;
						nPossibleCells = 0;

						while (j <= 3 && nPossibleCells < 2)
						{
							if (iogrid.getRow(nRow1 + 3 * nThreeRows).get(3 * nRegion + j).isEmpty() && !iogrid.getColumn(3 * nRegion + j).isValuePresent(value))
							{
								nCol = j;
								nPossibleCells++;
								nRow = nRow1;
							}
							j++;

						}
						j = 1;
						while (j <= 3 && nPossibleCells < 2)
						{
							if (iogrid.getRow(nRow2 + 3 * nThreeRows).get(3 * nRegion + j).isEmpty() && !iogrid.getColumn(3 * nRegion + j).isValuePresent(value))
							{
								nCol = j;
								nPossibleCells++;
								nRow = nRow2;
							}
							j++;

						}
						if (nPossibleCells == 1)
						{
							iogrid.getRow(nRow + 3 * nThreeRows).get(3 * nRegion + nCol) = value;
							isGridModified = true;
						}
					}

				}
			}
			else if (nbRegionsInWhichPresent == 2)
			{
				nRow = 1;
				while (nRow < 3 && iogrid.getRow(3 * nThreeRows + nRow).isValuePresent(value))
				{
					nRow++;
				}

				nRegion = 0;
				while (nRegion < 2 && iogrid.getRegion(3 * nThreeRows + nRow, 3 * nRegion + 1).isValuePresent(value))
				{
					nRegion++;
				}

				int j = 1;
				nCol = 1;
				nPossibleCells = 0;
				while (j <= 3 && nPossibleCells < 2)
				{
					if (iogrid.getRow(3 * nThreeRows + nRow).get(3 * nRegion + j).isEmpty()
						&& !iogrid.getColumn(3 * nRegion + j).isValuePresent(value))
					{
						nCol = j;
						nPossibleCells++;
					}
					j++;
				}

				if (nPossibleCells == 1)
				{
					iogrid.getRow(3 * nThreeRows + nRow).get(3 * nRegion + nCol) = value;
					isGridModified = true;
				}
			}
		}
	}

	
	return isGridModified;
}