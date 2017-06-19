#include<iostream>
#include "FormulaCell.h"
#include "../helpers/MyStrings.h"

FormulaCell::FormulaCell(const char* initialCellString, const Table* delegate): Cell(initialCellString), tableDelegate(delegate) {
	const char* reader = initialCellString;
	
	int end = 0;
	for(; *reader != 'R'; ++reader);
	getCell(reader, end, row1, col1);
	reader += end;
	
	for(; !isOperator(*reader); reader++);
	sign = *reader;

	for(++reader; *reader != 'R'; ++reader);
	getCell(reader, end, row2, col2);
}

Cell* FormulaCell::clone() {
	return new FormulaCell(*this);
}

double FormulaCell::evaluate() {
	double op1 = tableDelegate->getCell(row1 - 1, col1 - 1)->evaluate();
	double op2 = tableDelegate->getCell(row2 - 1, col2 - 1)->evaluate();
	switch(sign) {
		case '+':
			return op1 + op2;
			break;
		case '-':
			return op1 - op2;
			break;
		case '*':
			return op1 * op2;
			break;
		case '/':
			return op1 / op2;
	}
}

void FormulaCell::writeToStream(std::fstream& stream) {
	double op2 = tableDelegate->getCell(row2 - 1, col2 - 1)->evaluate();
	if(sign == '/' && op2 == 0) {
		stream<< "ERROR";
	} else {
		stream<< evaluate();
	}
}

void FormulaCell::print() {
	double op2 = tableDelegate->getCell(row2 - 1, col2 - 1)->evaluate();
	if(sign == '/' && op2 == 0) {
		std::cout<< "ERROR";
	} else {
		std::cout<< evaluate();
	}
}

void FormulaCell::getCell(const char* str, int& end, int& cRow, int& cCol) {
	int row = 0, col = 0;
	int i = 1;
	for(; str[i] != 'C' && str[i] != '\0'; i++) {
		row *= 10;
		row += str[i] - '0';
	}
	for(++i; isDigit(str[i]) && str[i] != '\0'; i++) {
		col *= 10;
		col += str[i] - '0';
	}
	cRow = row;
	cCol = col;
	end = i;
}
