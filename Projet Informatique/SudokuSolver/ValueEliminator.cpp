#include "ValueEliminator.h"


ValueEliminator::ValueEliminator()
	
{
	for (int i = 0; i <= 8; i++)
	{
		tabEliminator[i] = false;
	}
}


ValueEliminator::~ValueEliminator()
{
}

void ValueEliminator::flag(unsigned char iValue)
{
	if ((int)iValue >= 49 && (int)iValue <= 57)
	tabEliminator[(int)iValue - 49] = true;

}

int ValueEliminator :: availableValues()
{
	int sum=0;
	for (int i = 0; i <= 8; i++)
	{
		sum += (int)!tabEliminator[i];
	}
	return sum;
	
}

set<unsigned char> ValueEliminator::availableValue()
{
	set<unsigned char> setAvaibaleValues;

	if (this->availableValues() == 0)
	{
		throw NoAvailableValueException("No available value found");
	}

	else if (this->availableValues() == 1)
	{
		for (int i = 0; i <= 8; i++)
		{
			if (tabEliminator[i] == false)
			{
				setAvaibaleValues.insert((unsigned char)(i + 49));
				break;
			}
		}
	}
	else
	{
		
		for (int i = 0; i <= 8; i++)
		{
			if (tabEliminator[i] == false)
			{
				setAvaibaleValues.insert((unsigned char)(i + 49));

			}
		}

		
	}
	return setAvaibaleValues;
}