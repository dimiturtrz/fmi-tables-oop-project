#include "../Cell.h"

#ifndef FORMULA_CELL
#define FORMULA_CELL

class FormulaCell: public Cell {
public:
	FormulaCell(const char* initialCellString);

	virtual Cell* clone();

	virtual void writeToStream(std::fstream& stream);
	virtual void print();
};

#endif
