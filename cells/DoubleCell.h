#include "../Cell.h"

#ifndef DOUBLE_CELL
#define DOUBLE_CELL

class DoubleCell: public Cell {
private:
	double doubleVal;
public:
	DoubleCell(const char* initialCellString);

	virtual Cell* clone();
	virtual double evaluate() const;
};

#endif
