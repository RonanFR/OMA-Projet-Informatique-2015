#include "LastCellFinder.h"


LastCellFinder::LastCellFinder(TripleHolder triple1, TripleHolder triple2, TripleHolder triple3)
	
{
	triples.push_back(triple1);
	triples.push_back(triple2);
	triples.push_back(triple3);

};



bool LastCellFinder::fill()
{
	
	list<TripleHolder>::iterator it = triples.begin();
	list<TripleHolder>::iterator ie;
	int nbEmptyCells = 0;
	int sumCells = 0;
	

	while (it != triples.end())
	{
		nbEmptyCells += (*it).getNbEmptyCells();
		if (nbEmptyCells > 1)
		{
			return false ;
		}
		
		if ((*it).getNbEmptyCells()==1)
		{
			ie = it;
			
		}
		sumCells += (*it).getSumCells();
		it++;

	}

	if (nbEmptyCells == 1)
	{
		((*ie).getEmptyCell()) = (char)(477 - sumCells );
		
	}
	if (nbEmptyCells == 0)
	{
		return false;
	}
	return true;
	

}
