#include <iostream>
#include <fstream>

#include "Table.h"

// --------------------- BIG FOUR -------------------------
Table::Table()/*: rows(NULL)*/ {}

Table::Table(const Table& other) {
	/*rowsCount = other.rowsCount;
	delete [] rows;
	rows = new Row[rowsCount];
	for(int i = 0; i<rowsCount; i++) {
		rows[i] = other.rows[i];
	}*/
}

Table& Table::operator=(const Table& other) {
	if(this != &other) {
		/*rowsCount = other.rowsCount;
		delete [] rows;
		rows = new Row[rowsCount];
		for(int i = 0; i<rowsCount; i++) {
			rows[i] = other.rows[i];
		}*/
	}

	return *this;
}

Table::~Table() {
	//delete [] rows;
}

// ------------------- FILE METHODS -----------------------

bool Table::populateFromStream(std::fstream& stream) {
	char buffer[1024];
	while(stream.getline(buffer, 1024)) {
		
	}
}

void Table::writeToStream(std::fstream& stream) {
	/*for(int i = 0; i < rowsCount; i++) {
		rows[i].writeToStream(stream);
	} */
}

// ------------------- INTERFACE METHODS ------------------
void Table::print() {
	//writeToStream(std::cout);
}
void Table::edit(int row, int col, char* newContent) {
	//rows[row].setCell(col, newContent);
}

