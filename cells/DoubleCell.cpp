#include<iostream>
#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* initialCellString): Cell(initialCellString) {
	int i = 0;
	for(; cellString[i] != ' ' && cellString[i] != '\0'; ++i);
	cellString[i] = '\0';

	bool sign = cellString[0] != '-';
	double number = 0;
	int exp = 1;
	bool afterDecimalPoint = false;
	i = (cellString[0] == '-' || cellString[0] == '+') ? 1 : 0;
	for(; cellString[i] != '\0'; i++) {
		if(cellString[i] == '.') {
			afterDecimalPoint = true;		
		} else {
			number *= 10;
			number += cellString[i] - '0';
			if(afterDecimalPoint) {
				exp *= 10;
			}
		}	
	}

	doubleVal = sign ? number/exp : -(number/exp);
}

Cell* DoubleCell::clone() {
	return new DoubleCell(*this);
}

double DoubleCell::evaluate() const {
	return doubleVal;
}
