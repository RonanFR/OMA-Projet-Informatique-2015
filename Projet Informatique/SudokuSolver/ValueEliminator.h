#pragma once
# include <iostream>;
#include <set>


using namespace std;

class ValueEliminator
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

