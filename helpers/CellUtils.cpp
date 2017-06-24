#include "CellUtils.h"

// black magic, do not touch
CellType determineType(const char* cellContent) {
	const char* reader = cellContent;
	for(; *reader == ' '; ++reader);

	if(*reader == '\0') {
		return String;
	}
	if(*reader == '=') {
		return Formula;
	}
	
	bool isInteger = true;
	bool isDouble = true;
	int i = ((reader[0] == '-' || reader[0] == '+') && reader[1] != '\0' && isDigit(reader[1])) ? 1 : 0;
	for(; reader[i] != '\0' && (isDigit(reader[i]) || reader[i] == '.'); ++i) {
		if(reader[i] == '.') {
			isInteger ? isInteger = false : isDouble = false;
		}
	}

	for(; reader[i] == ' '; ++i);
	if(reader[i] == '\0') {
		if(isInteger) {
			return Integer;
		} else if(isDouble) {
			return Double;
		}
	}
	
	return String;
}

int readInt(char* str, int* len) {
	int i = 0;
	bool sign = str[0] != '-';
	int number = 0;

	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	for(; str[i] != '\0'; i++) {
		number *= 10;
		number += str[i] - '0';
	}

	return sign ? number : -number;
}

double readDouble(char* str, int* len) {
	int i = 0;
	bool sign = str[0] != '-';
	double number = 0;
	int exp = 1;
	bool afterDecimalPoint = false;

	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	for(; str[i] != '\0'; i++) {
		if(str[i] == '.') {
			afterDecimalPoint = true;		
		} else {
			number *= 10;
			number += str[i] - '0';
			if(afterDecimalPoint) {
				exp *= 10;
			}
		}	
	}

	return sign ? number/exp : -(number/exp);
}
