#include "Row.h"
#include "helpers/MyStrings.h"
#include "cells/IntegerCell.h"
#include "cells/DoubleCell.h"
#include "cells/StringCell.h"
#include "cells/FormulaCell.h"

// ------------------- BIG FOUR ---------------------
Row::Row() {}

Row::Row(char* rowStr) {
	char* reader = rowStr;
	char buffer[1024];
	int offset = 0;
	while(readCellStr(reader, buffer, &offset)) {
		reader += offset;
		Cell* newCell = getCell(buffer);
		cells.add(newCell);
	}
}

Row::Row(const Row& other) {
	cells = other.cells;
	for(int i=0; i<cells.getSize(); i++) {
		cells[i] = cells[i]->clone();
	}
}

Row& Row::operator=(const Row& other) {
	if(this != &other) {
		cells = other.cells;
		for(int i=0; i<cells.getSize(); i++) {
			cells[i] = cells[i]->clone();
		}
	}
	return *this;
}

Row::~Row() {
	for(int i=0; i<cells.getSize(); i++) {
		delete cells[i];
	}
}
// ------------------- FILE MEHODS ----------------

void Row::writeToStream(std::fstream& stream) {
	for(int i=0; i< cells.getSize(); ++i) {
		cells[i]->writeToStream(stream);
	}
}
void Row::print() {
	for(int i=0; i< cells.getSize(); ++i) {
		cells[i]->print();
	}
	std::cout<< std::endl;
}
void Row::setCell(int col, const char* newContent) {
	cells[col] = getCell(newContent);
}


//----------------------- ROW STRING METHODS -------------------
bool Row::readCellStr(const char* start, char* buffer, int* len) {
	int i = 0;
	for(; start[i] != ',' && start[i] != '\0'; ++i) {
		buffer[i] = start[i];
	}
	buffer[i] = '\0';
	*len = ++i;
	return *start != '\0';
}

// black magic, do not touch
Cell* Row::getCell(const char* cellContent) {
	const char* reader = cellContent;
	for(; *reader == ' '; ++reader);

	if(*reader == '\0') {
		return new StringCell("");
	}
	if(*reader == '=') {
		return new FormulaCell(reader);
	}
	
	bool isInteger = true;
	bool isDouble = true;
	int i = 0;
	for(; reader[i] != '\0' && (isDigit(reader[i]) || reader[i] == '.'); ++i) {
		if(reader[i] == '.') {
			isInteger ? isInteger = false : isDouble = false;
		}
	}

	for(; reader[i] == ' '; ++i);
	if(reader[i] == '\0') {
		if(isInteger) {
			return new IntegerCell(reader);
		} else if(isDouble) {
			return new DoubleCell(reader);
		}
	}
	
	return new StringCell(reader);
}
