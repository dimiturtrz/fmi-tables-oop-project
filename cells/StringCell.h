#include "../Cell.h"

#ifndef STRING_CELL
#define STRING_CELL

class StringCell: public Cell {
public:
	StringCell(const char* initialCellString);

	virtual Cell* clone();

	virtual void writeToStream(std::fstream& stream);
	virtual void print();
};

#endif
