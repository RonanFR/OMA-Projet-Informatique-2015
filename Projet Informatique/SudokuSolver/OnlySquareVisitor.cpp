#include "OnlySquareVisitor.h"


OnlySquareVisitor::OnlySquareVisitor()
{
}

OnlySquareVisitor::~OnlySquareVisitor()
{
}

bool OnlySquareVisitor::Visit(Grid & ioGrid) const
{
	int i;
	bool gridModified = false;
	set <int> emptyCellsIndices;
	set <unsigned char> flags;
	ValueEliminator valueEliminator1;
	for (i = 1; i<=9; i++)
	{
		// Visit all columns
		emptyCellsIndices = ioGrid.getColumn(i).getEmptyCellsIndices();
		if (emptyCellsIndices.size() == 2)
		{
			flags = ioGrid.getColumn(i).flagValues(valueEliminator1);
			
			if (ioGrid.getRow(*emptyCellsIndices.begin()).isValuePresent(*flags.begin()) || ioGrid.getRow(*(++emptyCellsIndices.begin())).isValuePresent(*(++flags.begin()))
				|| ioGrid.getRegion(*emptyCellsIndices.begin(), i).isValuePresent(*flags.begin()) || ioGrid.getRegion(*(++emptyCellsIndices.begin()), i).isValuePresent(*(++flags.begin())))
			{
				ioGrid.getColumn(i).get(*emptyCellsIndices.begin()) = *(++flags.begin());
				ioGrid.getColumn(i).get(*(++emptyCellsIndices.begin())) = *flags.begin();
				gridModified = true;
			}
			else if (ioGrid.getRow(*emptyCellsIndices.begin()).isValuePresent(*(++flags.begin())) || ioGrid.getRow(*(++emptyCellsIndices.begin())).isValuePresent(*flags.begin())
				|| ioGrid.getRegion(*emptyCellsIndices.begin(), i).isValuePresent(*(++flags.begin())) || ioGrid.getRegion(*(++emptyCellsIndices.begin()), i).isValuePresent(*flags.begin()))
			{
				ioGrid.getColumn(i).get(*emptyCellsIndices.begin()) = *flags.begin();
				ioGrid.getColumn(i).get(*(++emptyCellsIndices.begin())) = *(++flags.begin());
				gridModified = true;
			}
		}

		// Visit all rows
		emptyCellsIndices = ioGrid.getRow(i).getEmptyCellsIndices();
		if (emptyCellsIndices.size() == 2)
		{
			flags = ioGrid.getRow(i).flagValues(valueEliminator1);

			if (ioGrid.getColumn(*emptyCellsIndices.begin()).isValuePresent(*flags.begin()) || 
				ioGrid.getColumn(*(++emptyCellsIndices.begin())).isValuePresent(*(++flags.begin())) || 
				ioGrid.getRegion(i,*emptyCellsIndices.begin()).isValuePresent(*flags.begin()) ||
				ioGrid.getRegion(i,*(++emptyCellsIndices.begin())).isValuePresent(*(++flags.begin())))
			{
				ioGrid.getRow(i).get(*emptyCellsIndices.begin()) = *(++flags.begin());
				ioGrid.getRow(i).get(*(++emptyCellsIndices.begin())) = *flags.begin();
				gridModified = true;
			}
			else if (ioGrid.getColumn(*emptyCellsIndices.begin()).isValuePresent(*(++flags.begin())) ||
				ioGrid.getColumn(*(++emptyCellsIndices.begin())).isValuePresent(*flags.begin()) ||
				ioGrid.getRegion(i,*emptyCellsIndices.begin()).isValuePresent(*(++flags.begin())) ||
				ioGrid.getRegion(i,*(++emptyCellsIndices.begin())).isValuePresent(*flags.begin()))
			{
				ioGrid.getRow(i).get(*emptyCellsIndices.begin()) = *flags.begin();
				ioGrid.getRow(i).get(*(++emptyCellsIndices.begin())) = *(++flags.begin());
				gridModified = true;
			}
		}
	}

	return gridModified;
}
