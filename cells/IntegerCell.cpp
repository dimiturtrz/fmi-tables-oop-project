#include<iostream>
#include "IntegerCell.h"

IntegerCell::IntegerCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' ' && cellString[i] != '\0'; ++i);
	cellString[i] = '\0';

	bool sign = cellString[0] != '-';
	int number = 0;
	i = (cellString[0] == '-' || cellString[0] == '+') ? 1 : 0;
	for(; cellString[i] != '\0'; i++) {
		number *= 10;
		number += cellString[i] - '0';
	}

	intVal = sign ? number : -number;
}

Cell* IntegerCell::clone() {
	return new IntegerCell(*this);
}
