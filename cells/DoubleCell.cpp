#include<iostream>
#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' '; ++i);
	cellString[i] = '\0';
	// interpret double
}

Cell* DoubleCell::clone() {
	return new DoubleCell(*this);
}
