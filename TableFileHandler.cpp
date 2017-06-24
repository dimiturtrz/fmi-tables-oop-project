#include <iostream>
#include <fstream>

#include "helpers/MyStrings.h"
#include "BaseFileHandler.h"
#include "TableFileHandler.h"

// ----------------------- INPUT --------------------------
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

// ------------------- BASIC FILE METHODS ---------------------
bool TableFileHandler::open(const char* path) {
	if(!BaseFileHandler::open(path)) {
		return false;
	}
	
	return populateTable();
}

bool TableFileHandler::save() {
	file.close();
	if(!saveas(currFilePath)) {
		return false;
	}
	return open(currFilePath);
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
	std::cout<< "table successfully(maybe) saved to "<< path<< std::endl;
	return true;
}

void TableFileHandler::close() {
	BaseFileHandler::close();
	table.reset();
}

// --------------------- OUTPUT FILE METHODS ------------------

void TableFileHandler::print() {
	table.print();
}

void TableFileHandler::edit(const char* arguments) {
	int row = 0, col = 0;
	int endOne = 0, endTwo = 0;
	if(!readGenericInt(arguments, ' ', row, &endOne) || !readGenericInt(arguments + endOne, ' ', col, &endTwo) && row >= 0 && col >= 0) {
		std::cout<< "wrong input form (it is not that complicated)"<< std::endl;
	}
	for(; arguments[endOne + endTwo] == ' '; ++endTwo);
	const char* newContent = arguments + endOne + endTwo;
	table.edit(row - 1, col - 1, newContent);
	std::cout<< "the edit function reached it's end without any runtime errors"<< std::endl;
}

// -------------------- TABLE HANDLER METHODS ----------------
bool TableFileHandler::populateTable() {
	return table.populateFromStream(file);
}

void TableFileHandler::writeTableToStream(std::fstream& stream) {
	table.writeToStream(stream);
}

