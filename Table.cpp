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

	setColumnWidths();
}

void Table::writeToStream(std::fstream& stream) const {
	for(int i = 0; i < rows.getSize(); i++) {
		rows[i].writeToStream(stream);
	}
}

// ----------------- INTERFACE METHODS -------------------
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

CellProtocol* Table::getCell(int row, int col) const {
	return rows[row].getCell(col);
}

int Table::getColumnWidth(int column) const {
	return columnWidths[column];
}

// ------------------ PRIVATE METHODS ----------------------

void Table::setColumnWidths() {
	int maxRowLen = 0;

	for(int i = 0; i < rows.getSize(); i++) {
		int rowCells = rows[i].getTotalCells();
		if(maxRowLen < rowCells) {
			maxRowLen = rowCells;
		}
	}

	columnWidths = Vector<int>(maxRowLen);

	for(int i = 0; i < maxRowLen; i++) {
		columnWidths.add(0);
	}

	for(int i = 0; i < rows.getSize(); i++) {
		for(int j = 0; j < rows[i].getTotalCells(); j++) {
			int cellStrLen = getCell(i, j)->getStringLength();
			if(columnWidths[j] < cellStrLen) {
				columnWidths[j] = cellStrLen;
			}
		}
	}
}

