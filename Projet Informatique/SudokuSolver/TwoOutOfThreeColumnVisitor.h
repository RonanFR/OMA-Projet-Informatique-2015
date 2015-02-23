# pragma once
# include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API TwoOutOfThreeColumnVisitor: public IVisitor
{
public:
	TwoOutOfThreeColumnVisitor();
	~TwoOutOfThreeColumnVisitor();
	bool Visit(Grid & iogrid) const;
private:
	bool VisitOneOutOfThree(Grid & iogrid, unsigned char value, int nThreeColumns) const;
	bool VisitTwoOutOfThree(Grid & iogrid, unsigned char value, int nThreeColumns) const;
};

