/*#include "LastCellFinder.h"


LastCellFinder::LastCellFinder(TripleHolder triple1, TripleHolder triple2, TripleHolder triple3)
	:triple1(triple1), triple2(triple2), triple3(triple3)
{

};

list<unique_ptr<Cell>> LastCellFinder:: Getlist()
{	
	list<unique_ptr<Cell>> liste;
	
	unique_ptr<Cell> ptr_Cell_11;
	*ptr_Cell_11 = triple1.getCell1();
	liste.push_back(ptr_Cell_11);

	unique_ptr<Cell> ptr_Cell_12;
	*ptr_Cell_12 = triple1.getCell2();
	liste.push_back(ptr_Cell_12);

	unique_ptr<Cell> ptr_Cell_13;
	*ptr_Cell_13 = triple1.getCell3();
	liste.push_back(ptr_Cell_13);

	unique_ptr<Cell> ptr_Cell_21;
	*ptr_Cell_21 = triple2.getCell1();
	liste.push_back(ptr_Cell_21);

	unique_ptr<Cell> ptr_Cell_22;
	*ptr_Cell_22 = triple2.getCell2();
	liste.push_back(ptr_Cell_22);

	unique_ptr<Cell> ptr_Cell_23;
	*ptr_Cell_23 = triple2.getCell3();
	liste.push_back(ptr_Cell_23);
	
	unique_ptr<Cell> ptr_Cell_31;
	*ptr_Cell_31 = triple3.getCell1();
	liste.push_back(ptr_Cell_31);

	unique_ptr<Cell> ptr_Cell_32;
	*ptr_Cell_32 = triple3.getCell2();
	liste.push_back(ptr_Cell_32);

	unique_ptr<Cell> ptr_Cell_33;
	*ptr_Cell_33 = triple3.getCell3();
	liste.push_back(ptr_Cell_33);

	return liste;
}

bool LastCellFinder::fill()
{
	list<unique_ptr<Cell>> liste;
	liste = Getlist();
	list<unique_ptr<Cell>>::iterator it = liste.begin();
	list<unique_ptr<Cell>>::iterator pointeur_cell_vide;
	int nombre_cell_vide = 0;
	
	while (nombre_cell_vide>1)
	{
		if ((**it).isEmpty())
		{	
			pointeur_cell_vide = it;
			++nombre_cell_vide;
		}	
		++it;
	}
	
	

	return (nombre_cell_vide == 1);

}
*/