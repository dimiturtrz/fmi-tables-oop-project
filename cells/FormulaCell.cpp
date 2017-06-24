#include<iostream>
#include<iomanip>
#include "FormulaCell.h"
#include "../helpers/MyStrings.h"
#include "../helpers/CellUtils.h"

FormulaCell::FormulaCell(const char* initialCellString, const TableProtocol* delegate): Cell(initialCellString), tableDelegate(delegate), row1(-1), col1(-1), row2(-1), col2(-1), const1(0), const2(0) {
	const char* reader = initialCellString + 1;
	
	int end = 0;
	for(; *reader == ' '; ++reader);
	if(*reader == 'R') {
		readCell(reader, end, row1, col1);
	} else {
		const1 = readConst(reader, end);
	}
	reader += end;
	
	for(; !isOperator(*reader); reader++);
	sign = *reader;

	for(++reader; *reader == ' '; ++reader);
	if(*reader == 'R') {
		readCell(reader, end, row2, col2);
	} else {
		const2 = readConst(reader, end);
	}
}

Cell* FormulaCell::clone() {
	return new FormulaCell(*this);
}

double FormulaCell::evaluate() const {
	CellProtocol* cell1 = getCell(row1, col1);
	double op1 = (cell1 != NULL) ? cell1->evaluate() : const1;
	CellProtocol* cell2 = getCell(row2, col2);
	double op2 = (cell2 != NULL) ? cell2->evaluate() : const2;

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

void FormulaCell::writeToStream(std::fstream& stream) const {
	CellProtocol* cell2 = getCell(row2, col2);
	double op2 = (cell2 != NULL) ? cell2->evaluate() : const2;
	if(sign == '/' && op2 == 0) {
		stream<< "ERROR";
	} else {
		stream<< evaluate();
	}
}

void FormulaCell::print(int width) const {
	CellProtocol* cell2 = getCell(row2, col2);
	double op2 = (cell2 != NULL) ? cell2->evaluate() : const2;
	if(sign == '/' && op2 == 0) {
		std::cout<< "ERROR";
	} else {
		std::cout<< std::setw(width)<< evaluate();
	}
}

CellProtocol* FormulaCell::getCell(int row, int col) const {
	return (row >= 0) ? tableDelegate->getCell(row, col) : NULL;
}

void FormulaCell::readCell(const char* str, int& end, int& cRow, int& cCol) {
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
	
	cRow = row - 1;
	cCol = col - 1;
	end = i;
}

double FormulaCell::readConst(const char* reader, int& end) const {
	char buffer[1024];
	int i = 0;
	for(; reader[i] != '\0' && (i == 0 || !isOperator(reader[i])); i++) {
		buffer[i] = reader[i];
	}
	buffer[i] = '\0';
	end = i - 1;

	switch(determineType(buffer)) {
		case Integer:
			for(i = 0; buffer[i] != ' ' && buffer[i] != '\0'; ++i);
			buffer[i] = '\0';
			return readInt(buffer);
		case Double:
			for(i = 0; buffer[i] != ' ' && buffer[i] != '\0'; ++i);
			buffer[i] = '\0';
			return readDouble(buffer);
		case String:
			return 0;
		case Formula:
			return 0;
	}
}

