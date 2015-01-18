# pragma once

class Cell{
public:
	Cell();
	Cell(unsigned int value);
private:
	unsigned int value; // 0 si la cellule est vide, chiffre entre 1 et 9 si la cellule est valuee
};
