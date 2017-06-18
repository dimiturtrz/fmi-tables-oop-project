#include "Row.h"

Row::Row() {}
Row::Row(char* rowStr) {
	char* reader = rowStr;
	char buffer[1024];
	int offset = 0;
	while(readCellStr(reader, buffer, &offset)) {
		reader += offset;
		//cells.add(buffer);
	}
}

void Row::writeToStream(std::fstream& stream) {
	/*
	for(int i=0; i< cells.getSize(); ++i) {
		cells[i].writeToStream(stream);
	}
	*/
}
void Row::print() {
	/*
	for(int i=0; i< cells.getSize(); ++i) {
		cells[i].print();
	}
	std::cout<< std::endl;
	*/
}
void Row::setCell(int col, const char* newContent) {
	/*
		cells[col] = Cell(newContent);
	*/
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
