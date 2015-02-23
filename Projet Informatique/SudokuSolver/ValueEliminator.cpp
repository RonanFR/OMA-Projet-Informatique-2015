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
	if (iValue >= '1' && iValue <= '9' && !tabEliminator[iValue - '1'])
	{
		tabEliminator[iValue - '1'] = true;
		--nbAvailableValues;
	}
}

int ValueEliminator::availableValues() const
{
	return nbAvailableValues;
}

set<unsigned char> ValueEliminator::availableValue() const
{
	set<unsigned char> setAvaibaleValues;

	if (this->availableValues() == 0)
	{
		throw NoAvailableValueException("No available value found");
	}
	else if (this->availableValues() == 1)
	{
		for (int i = 0; i < 9; i++)
		{
			if (!tabEliminator[i])
			{
				setAvaibaleValues.insert(i + '1');
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (!tabEliminator[i])
			{
				setAvaibaleValues.insert(i + '1');

			}
		}
	}
	return setAvaibaleValues;
}