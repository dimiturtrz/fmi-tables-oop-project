#include<iostream>
#include<fstream>
#include "CellProtocol.h"
#include "TableProtocol.h"
#include "helpers/MyStrings.h"

#ifndef CELL
#define CELL

class Cell: public CellProtocol {	
protected:
	char* cellString;

public:
	Cell(const char* initialCellString);
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);
	virtual ~Cell();

	virtual Cell* clone() = 0;
	virtual double evaluate() const = 0;

	virtual void writeToStream(std::fstream& stream) const;
	virtual void print(int width) const;

	virtual int getStringLength() const;
};

#endif
