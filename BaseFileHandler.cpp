#include <iostream>
#include <fstream>

#include "BaseFileHandler.h"

void BaseFileHandler::close() {
	file.close();
}

void BaseFileHandler::startGettingInput() {}

BaseFileHandler::~BaseFileHandler() {
	close();
}

