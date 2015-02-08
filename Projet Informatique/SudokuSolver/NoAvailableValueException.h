#pragma once

#include <exception>
using namespace std;

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API NoAvailableValueException : public exception
{
public:
	NoAvailableValueException(char * ErrorMsg);
	~NoAvailableValueException();
	virtual const char * what() const throw();
private:
	char * ErrorMsg;
};

