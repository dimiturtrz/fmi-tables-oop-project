#include <iostream>
#include <fstream>

#include "Table.h"
#include "Row.h"

// ------------------- FILE METHODS -----------------------

bool Table::populateFromStream(std::fstream& stream) {
	char buffer[1024];
	while(stream.getline(buffer, 1024)) {
		rows.add(Row(buffer, this));
	}
}

void Table::writeToStream(std::fstream& stream) const {
	for(int i = 0; i < rows.getSize(); i++) {
		rows[i].writeToStream(stream);
	}
}

// ------------------- INTERFACE METHODS ------------------
void Table::print() const {
	for(int i = 0; i < rows.getSize(); i++) {
		rows[i].print();
	}
}
void Table::edit(int row, int col, const char* newContent) {
	rows[row].setCell(col, newContent);
}

void Table::reset() {
	rows.reset();
}

Cell* Table::getCell(int row, int col) const {
	return rows[row].getCell(col);
}

