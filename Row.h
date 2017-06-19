#include<iostream>
#include<fstream>

#include "Cell.h"
#include "helpers/MyStrings.h"
#include "helpers/Vector.h"

#ifndef ROW
#define ROW

class Table;

class Row {
	Vector<Cell*> cells;
	const Table* delegate;

public:
	Row();
	Row(char* rowStr, const Table* delegate);
	Row(const Row& other);
	Row& operator=(const Row& other);
	~Row();

	void writeToStream(std::fstream& stream) const;
	void print() const;
	void setCell(int col, const char* newContent);
	Cell* getCell(int col) const;

private:
	bool readCellStr(const char* start, char* buffer, int* length = NULL) const;
	Cell* makeCell(const char* cellContent) const;
};

#endif
