#include<iostream>
#include<fstream>

#include "Cell.h"
#include "MyStrings.h"
#include "Vector.h"

#ifndef ROW
#define ROW

class Row {
	Vector<Cell*> cells;

public:
	Row();
	Row(char* rowStr);
	Row(const Row& other);
	Row& operator=(const Row& other);
	~Row();

	void writeToStream(std::fstream& stream);
	void print();
	void setCell(int col, const char* newContent);

private:
	bool readCellStr(const char* start, char* buffer, int* length = NULL);
};

#endif
