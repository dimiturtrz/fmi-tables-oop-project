#include<iostream>
#include<fstream>
#include "helpers/MyStrings.h"

#ifndef CELL
#define CELL

class Cell {	
protected:
	char* cellString;

public:
	Cell(const char* initialCellString);
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);
	virtual ~Cell();

	virtual Cell* clone() = 0;

	virtual void writeToStream(std::fstream& stream);
	virtual void print();

};

#endif
