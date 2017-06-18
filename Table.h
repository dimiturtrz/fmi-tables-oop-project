#include<fstream>
#include "helpers/Vector.h"
#include "Row.h"

#ifndef TABLE
#define TABLE

class Table {
private:
	Vector<Row> rows;

public:
	bool populateFromStream(std::fstream& stream);
	void writeToStream(std::fstream& stream);

	void print();
	void edit(int row, int col, const char* newContent);
};

#endif
