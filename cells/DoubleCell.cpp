#include<iostream>
#include "DoubleCell.h"
#include "../helpers/CellUtils.h"

DoubleCell::DoubleCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' ' && cellString[i] != '\0'; ++i);
	cellString[i] = '\0';
	doubleVal = readDouble(cellString);
}

Cell* DoubleCell::clone() {
	return new DoubleCell(*this);
}

double DoubleCell::evaluate() const {
	return doubleVal;
}
