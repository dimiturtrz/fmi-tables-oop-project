#include "../Cell.h"

#ifndef FORMULA_CELL
#define FORMULA_CELL

class FormulaCell: public Cell {
private:
	Cell* cells;
public:
	FormulaCell(const char* initialCellString);

	virtual Cell* clone();
};

#endif
