# pragma once
# include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define SUDOKUSOLVER_API __declspec(dllexport)
#else
#define SUDOKUSOLVER_API __declspec(dllimport)
#endif

class SUDOKUSOLVER_API TwoOutOfThreeRowVisitor: public IVisitor
{
public:
	TwoOutOfThreeRowVisitor();
	~TwoOutOfThreeRowVisitor();
	bool Visit(Grid & iogrid) const;
private:
	bool VisitOneOutOfThree(Grid & iogrid, unsigned char value, int nThreeColumns) const;
	bool VisitTwoOutOfThree(Grid & iogrid, unsigned char value, int nThreeRows) const;
};

