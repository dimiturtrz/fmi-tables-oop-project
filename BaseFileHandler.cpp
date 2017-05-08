#include <iostream>
#include <fstream>

#include "MyStrings.h"
#include "BaseFileHandler.h"

// file part
void BaseFileHandler::open(const char* path) {
	file.open(path);
}
void BaseFileHandler::close() {
	file.close();
}
void BaseFileHandler::save() {
	
}
void BaseFileHandler::saveas(const char* path) {
	
}
void BaseFileHandler::exit() {
	gettingInput = false;
}

// console interpretation part
bool BaseFileHandler::interpretInput(const char* command, const char* arguments) {
	if(strcmp(command, "open") == 0) {
		open(arguments + sizeof(char));
	} else if(strcmp(command, "close") == 0) {
		close();
	} else if(strcmp(command, "exit") == 0) {
		exit();
	} else if(strcmp(command, "save") == 0) {
		save();
	} else if(strcmp(command, "saveas") == 0) {
		saveas(arguments + sizeof(char));
	}
}

void BaseFileHandler::startGettingInput() {
	gettingInput = true;
	char command[6];
	char arguments[512];
	while(gettingInput) {
		std::cin>> command;
		std::cin.getline(arguments, 511);
		interpretInput(command, arguments);
	}
}

// just-in-case destructor
BaseFileHandler::~BaseFileHandler() {
	close();
}

