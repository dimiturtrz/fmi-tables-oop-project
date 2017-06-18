#include "Row.h"

Row::Row() {}
Row::Row(char* rowStr) {
	char* reader = rowStr;
	char buffer[1024];
	int offset = 0;
	while(readCellStr(reader, buffer, &offset)) {
		reader += offset;
		//Cell* newCell = new Cell(buffer); // cell of type
		//cells.add(newCell);
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
	cells[col]->setContent(newContent);
}


//----------------------- ROW STRING METHODS -------------------
bool Row::readCellStr(const char* start, char* buffer, int* len) {
	int i = 0;
	for(; start[i] != ',' && start[i] != '\0'; ++i) {
		buffer[i] = start[i];
	}
	buffer[i] = '\0';
	*len = ++i;
	return start[i] != '\0';
}
