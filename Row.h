#include<iostream>
#include<fstream>

#include "Cell.h"
#include "helpers/MyStrings.h"
#include "helpers/Vector.h"
#include "TableProtocol.h"

#ifndef ROW
#define ROW

class Row {
	Vector<Cell*> cells;
	const TableProtocol* delegate;

public:
	Row();
	Row(char* rowStr, const TableProtocol* delegate);
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
