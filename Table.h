#include<fstream>
#include "helpers/Vector.h"
#include "Row.h"
#include "Cell.h"

#ifndef TABLE
#define TABLE

class Table {
private:
	Vector<Row> rows;

public:
	bool populateFromStream(std::fstream& stream);
	void writeToStream(std::fstream& stream) const;
	void reset();

	void print() const;
	void edit(int row, int col, const char* newContent);
	Cell* getCell(int row, int col) const;
};

#endif
