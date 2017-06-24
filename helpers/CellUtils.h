#include<iostream>
#include "MyStrings.h"

#ifndef CELL_UTILS
#define CELL_UTILS

enum CellType { Integer, Double, String, Formula };

CellType determineType(const char* cellContent);
int readInt(char* str, int* len = NULL);
double readDouble(char* str, int* len = NULL);

#endif
