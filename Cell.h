#include "MyStrings.h"

#ifndef CELL
#define CELL

class Cell {	
protected:
	char* cellString;

public:
	Cell(const char* initialCellString);
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);

	virtual Cell* clone() = 0;/* {
		return new Cell(*this);
	}*/

	virtual void setContent(const char* newContent) = 0;

	virtual ~Cell() {
		delete cellString;
	}

	virtual void writeToStream(std::fstream& stream) = 0;
	virtual void print() = 0;

};

#endif
