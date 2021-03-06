# pragma once
# include "Cell.h"
# include <string>

using namespace std;

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif

class SUDOKUSOLVER_API  Region
{
public:
	Region();
	Region(string chaine);
	bool isFull() const;
	bool isConsistent() const;
	int getNbEmptyCells() const;
	Region & operator =(Region const & region);
	Cell & getN() ;
	Cell & getS() ;
	Cell & getE() ;
	Cell & getO() ;
	Cell & getNO() ;
	Cell & getNE() ;
	Cell & getSO() ;
	Cell & getSE() ;
	Cell & getC() ;

private:
	Cell N;
	Cell S;
	Cell E;
	Cell O;
	Cell NE;
	Cell SE;
	Cell NO;
	Cell SO;
	Cell C;
};