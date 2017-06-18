#include "../Cell.h"

#ifndef DOUBLE_CELL
#define DOUBLE_CELL

class DoubleCell: public Cell {
private:
	double doubleVal;
public:
	DoubleCell(const char* initialCellString);

	virtual Cell* clone();

	virtual void writeToStream(std::fstream& stream);
	virtual void print();
};

#endif
