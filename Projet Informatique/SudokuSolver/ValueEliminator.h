#pragma once
#include"NoAvailableValueException.h"
#include <set>


using namespace std;
#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API ValueEliminator
{
public:
	ValueEliminator();
	~ValueEliminator();
	void flag(unsigned char iValue);
	int availableValues();
	set<unsigned char> availableValue();
private:
	bool tabEliminator[9];

};

