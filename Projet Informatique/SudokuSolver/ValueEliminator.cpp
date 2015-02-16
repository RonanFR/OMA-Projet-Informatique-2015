#include "ValueEliminator.h"


ValueEliminator::ValueEliminator()
	:nbAvailableValues(9)
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
	tabEliminator[(int)iValue - 49] = true;
}

int ValueEliminator :: availableValues()
{
	return nbAvailableValues;
}

set<unsigned char> ValueEliminator::availableValue()
{
	set<unsigned char> setAvaibaleValues;
	if (this->availableValues == 0)
	{
		throw string("NoAvailableValueException");
	}
	else if (this->availableValues == 1)
	{
		for (int i = 0; i <= 8; i++)
		{
			if (!tabEliminator[i])
			{
				setAvaibaleValues.insert((unsigned char)(i + 49));
			}
		}
		return setAvaibaleValues;
	}
	else
	{
		for (int i = 0; i <= 8; i++)
		{
			if (!tabEliminator[i])
			{
				setAvaibaleValues.insert((unsigned char)(i + 49));

			}
		}
		
		return setAvaibaleValues;

}