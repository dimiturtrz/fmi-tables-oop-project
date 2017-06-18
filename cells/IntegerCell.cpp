#include<iostream>
#include "IntegerCell.h"

IntegerCell::IntegerCell(const char* initialCellString): Cell(initialCellString) {
	char* reader = cellString;
	for(; *reader != ' '; ++reader);
	*reader = '\0';
	// interpret int
}

Cell* IntegerCell::clone() {
	return new IntegerCell(*this);
}

void IntegerCell::writeToStream(std::fstream& stream) {
	//stream<< cellString;
}

void IntegerCell::print() {
	std::cout<< cellString;
}
