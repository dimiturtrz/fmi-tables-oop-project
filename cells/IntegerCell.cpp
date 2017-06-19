#include<iostream>
#include "IntegerCell.h"

IntegerCell::IntegerCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' ' && cellString[i] != '\0'; ++i);
	cellString[i] = '\0';
	// interpret int
}

Cell* IntegerCell::clone() {
	return new IntegerCell(*this);
}
