// Symboles exportes/importes

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API Cell{
public:
	Cell();
	Cell(unsigned int value);
private:
	unsigned int value; // 0 si la cellule est vide, chiffre entre 1 et 9 si la cellule est valuee
};

