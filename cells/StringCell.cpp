#include<iostream>
#include "StringCell.h"

StringCell::StringCell(const char* initialCellString): Cell(initialCellString) {}

Cell* StringCell::clone() {
	return new StringCell(*this);
}
