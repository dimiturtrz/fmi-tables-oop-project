#include<iostream>
#include<iomanip>
#include "helpers/MyStrings.h"
#include "Cell.h"

Cell::Cell(const char* initialCellString): cellString(NULL) {
	cellString = new char[strlen(initialCellString) + 1];
	strcpy(cellString, initialCellString);
}

Cell::Cell(const Cell& other): cellString(NULL) {
	cellString = new char[strlen(other.cellString) + 1];
	strcpy(cellString, other.cellString);
}

Cell& Cell::operator=(const Cell& other) {
	if(this != &other) {
		delete cellString;
		cellString = new char[strlen(other.cellString) + 1];
		strcpy(cellString, other.cellString);
	}
	return *this;
}

Cell::~Cell() {
	delete [] cellString;
}

void Cell::writeToStream(std::fstream& stream) const {
	stream<< cellString;
}

void Cell::print(int width) const {
	std::cout<< std::setw(width)<< cellString;
}

int Cell::getStringLength() const {
	return strlen(cellString);
}
