#include "NoAvailableValueException.h"


NoAvailableValueException::NoAvailableValueException(char* ErrorMsg)
	:ErrorMsg(ErrorMsg)
{
}


NoAvailableValueException::~NoAvailableValueException()
{
}



const char* NoAvailableValueException:: what() const throw()
	{
		return ErrorMsg;
	}
