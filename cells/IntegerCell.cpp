#include<iostream>
#include "IntegerCell.h"
#include "../helpers/CellUtils.h"

IntegerCell::IntegerCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' ' && cellString[i] != '\0'; ++i);
	cellString[i] = '\0';
	intVal = readInt(cellString);
}

Cell* IntegerCell::clone() {
	return new IntegerCell(*this);
}

double IntegerCell::evaluate() const {
	return intVal;
}
