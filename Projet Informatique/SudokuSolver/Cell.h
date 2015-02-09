# pragma once

# ifdef SUDOKUSOLVER_EXPORTS
# define SUDOKUSOLVER_API __declspec(dllexport)
# else
# define SUDOKUSOLVER_API __declspec(dllimport)
# endif


class SUDOKUSOLVER_API Cell{
public:
	Cell();
	Cell(unsigned char value);
	bool isEmpty();
	Cell & operator =(unsigned char iValue);
	operator unsigned char() const;
	bool operator ==(unsigned char iValue) const;
private:
	char value;
};
