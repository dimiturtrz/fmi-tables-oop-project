#include "Row.h"
#include "TableProtocol.h"
#include "helpers/MyStrings.h"
#include "helpers/CellUtils.h"
#include "cells/IntegerCell.h"
#include "cells/DoubleCell.h"
#include "cells/StringCell.h"
#include "cells/FormulaCell.h"

// ------------------- BIG FOUR ---------------------
Row::Row(): delegate(NULL) {}

Row::Row(char* rowStr, TableProtocol* delegate): delegate(delegate) {
	char* reader = rowStr;
	char buffer[1024];
	int offset = 0;
	while(readCellStr(reader, buffer, &offset)) {
		reader += offset;
		Cell* newCell = makeCell(buffer);
		cells.add(newCell);
	}
}

Row::Row(const Row& other): delegate(other.delegate) {
	cells = other.cells;
	for(int i=0; i<cells.getSize(); i++) {
		cells[i] = cells[i]->clone();
	}
}

Row& Row::operator=(const Row& other) {
	if(this != &other) {
		delegate = other.delegate;
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

void Row::writeToStream(std::fstream& stream) const {
	for(int i=0; i< cells.getSize(); ++i) {
		if(i != 0) {
			stream<< ", "; 		
		}
		cells[i]->writeToStream(stream);
	}
	stream<< std::endl;
}
void Row::print() const {
	for(int i=0; i< cells.getSize(); ++i) {
		if(i != 0) {
			std::cout<< "|"; 		
		}
		cells[i]->print(delegate->getColumnWidth(i));
	}
	std::cout<< std::endl;
}
void Row::setCell(int col, const char* newContent) {
	cells[col] = makeCell(newContent);
}

int Row::getTotalCells() const {
	return cells.getSize();
}

//----------------------- ROW STRING METHODS -------------------
bool Row::readCellStr(const char* start, char* buffer, int* len) const {
	if(*start == '\0'){
		return false;
	}
	int i = 0;
	for(; start[i] != ',' && start[i] != '\0'; ++i) {
		buffer[i] = start[i];
	}
	buffer[i] = '\0';
	*len = start[i] == ',' ? i + 1 : i;
	return true;
}

Cell* Row::getCell(int col) const {
	return cells[col];
}

Cell* Row::makeCell(const char* cellContent) const {
	const char* reader = cellContent;
	for(; *reader == ' '; ++reader);

	switch(determineType(reader)) {
		case Integer:
			return new IntegerCell(reader);
		case Double:
			return new DoubleCell(reader);
		case String:
			return new StringCell(reader);
		case Formula:
			return new FormulaCell(reader, delegate);
	}
}
