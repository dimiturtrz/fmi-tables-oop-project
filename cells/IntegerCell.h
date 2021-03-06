#include "../Cell.h"

#ifndef INTEGER_CELL
#define INTEGER_CELL

class IntegerCell: public Cell {
private:
	int intVal;
public:
	IntegerCell(const char* initialCellString);

	virtual Cell* clone();
	virtual double evaluate() const;
};

#endif
