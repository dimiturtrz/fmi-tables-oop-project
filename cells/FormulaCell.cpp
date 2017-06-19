#include<iostream>
#include "FormulaCell.h"

FormulaCell::FormulaCell(const char* initialCellString): Cell(initialCellString) {
	// interpret formula
}

Cell* FormulaCell::clone() {
	return new FormulaCell(*this);
}
