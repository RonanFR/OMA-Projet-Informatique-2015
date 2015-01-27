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
	bool isFull();
	Cell getN() const;
	Cell getS() const;
	Cell getE()const;
	Cell getO() const;
	Cell getNO()const;
	Cell getNE()const;
	Cell getSO()const;
	Cell getSE()const;
	Cell getC() const;
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