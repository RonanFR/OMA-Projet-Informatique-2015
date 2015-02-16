# include "OnlySquareVisitor.h"
# include <set>
# include <algorithm>


OnlySquareVisitor::OnlySquareVisitor()
{
}

OnlySquareVisitor::~OnlySquareVisitor()
{
}

bool OnlySquareVisitor::Visit(Grid & ioGrid) const
{
	bool gridModified = false;
	ValueEliminator valueEliminator;
	set < unsigned char > missingValues;
	set < unsigned char > missingValues2;
	set < unsigned char > possilbleValues;
	set < unsigned char > possilbleValues2;
	set < int > emptyCells;
	set<int>::iterator it;

	for (int i = 1; i <= 9; i++)
	{
		// Visit column i
		missingValues = ioGrid.getColumn(i).flagValues(valueEliminator);
		emptyCells = ioGrid.getColumn(i).getEmptyCellsIndices();
		it = emptyCells.begin();
		while (it != emptyCells.end())
		{
			// Check row
			missingValues2 = ioGrid.getRow(*it).flagValues(valueEliminator);
			set_intersection(missingValues.begin(), missingValues.end(), missingValues2.begin(),
				missingValues2.end(), inserter(possilbleValues, possilbleValues.begin()));

			// Check Region
			missingValues2 = ioGrid.getRegion(*it,i).flagValues(valueEliminator);
			set_intersection(possilbleValues.begin(), possilbleValues.end(), missingValues2.begin(),
				missingValues2.end(), inserter(possilbleValues2, possilbleValues2.begin()));

			if (possilbleValues2.size() == 1)
			{
				ioGrid.getColumn(i).get(*it) = *possilbleValues2.begin();
				gridModified = true;
			}

			// Clear sets
			possilbleValues.clear();
			possilbleValues2.clear();
			missingValues.clear();
			missingValues2.clear();

			it++; // Increment cell index
		}
		
	}


	return gridModified;
}
