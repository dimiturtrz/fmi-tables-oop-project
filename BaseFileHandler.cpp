#include <iostream>
#include <fstream>

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
	exit();
}

// console interpretation part
bool BaseFileHandler::interpretInput(const char* input) {
	
}

void BaseFileHandler::startGettingInput() {
	char* buffer[512];
	while(true) {
		std::getline(std::cin, buffer);
		interpretInput(buffer);
	}
}

// just-in-case destructor
BaseFileHandler::~BaseFileHandler() {
	close();
}

