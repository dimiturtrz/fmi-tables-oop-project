#include<iostream>
#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* initialCellString): Cell(initialCellString) {
	char* reader = cellString;
	for(; *reader != ' '; ++reader);
	*reader = '\0';
	// interpret double
}

Cell* DoubleCell::clone() {
	return new DoubleCell(*this);
}

void DoubleCell::writeToStream(std::fstream& stream) {
	//stream<< cellString;
}

void DoubleCell::print() {
	std::cout<< cellString;
}
