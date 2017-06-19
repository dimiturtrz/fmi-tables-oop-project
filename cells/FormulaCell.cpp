#include<iostream>
#include "FormulaCell.h"

FormulaCell::FormulaCell(const char* initialCellString): Cell(initialCellString) {
	char* reader = cellString;
	for(; *reader != ' '; ++reader);
	*reader = '\0';
	// interpret int
}

Cell* FormulaCell::clone() {
	return new FormulaCell(*this);
}
