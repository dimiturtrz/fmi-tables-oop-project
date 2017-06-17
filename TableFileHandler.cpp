#include <iostream>
#include <fstream>

#include "MyStrings.h"
#include "BaseFileHandler.h"
#include "TableFileHandler.h"

//input stuff
bool TableFileHandler::interpretInput(const char* command, const char* arguments) {
	if(strcmp(command, "print") == 0) {
		print();
	} else if(strcmp(command, "edit") == 0) {
		edit(arguments);
	} else {
		return BaseFileHandler::interpretInput(command, arguments);
	}
	return true;
}

//file stuff
bool TableFileHandler::open(const char* path) {
	if(!BaseFileHandler::open(path)) {
		return false;
	}

	return populateTable();
}

void TableFileHandler::save() {
	writeTableToStream(file);
}

bool TableFileHandler::saveas(const char* path) {
	std::fstream newFile;
	newFile.open(path, std::ios::out | std::ios::trunc);
	if(newFile.fail()) {
		std::cout<< "opening file failed"<< std::endl;
		newFile.clear();
		return false;
	}
	writeTableToStream(newFile);
	newFile.close();
	return false;
}

void TableFileHandler::print() {
	table.print();
}

void TableFileHandler::edit(const char* arguments) {
	int row = 0, col = 0;
	int endOne = 0, endTwo = 0;
	if(!readInt(arguments, ' ', row, &endOne) || !readInt(arguments + endOne, ' ', col, &endTwo)) {
		std::cout<< "wrong input form (it is not that complicated)"<< std::endl;
	}
	for(; arguments[endTwo] == ' '; ++endTwo);
	const char* newContent = arguments + endTwo;
	table.edit(row, col, newContent);
}

//other stuff
bool TableFileHandler::populateTable() {
	return table.populateFromStream(file);
}

void TableFileHandler::writeTableToStream(std::fstream& stream) {
	table.writeToStream(stream);
}

