#include<iostream>

#ifndef MY_STRINGS
#define MY_STRINGS 

//standart
int strlen(const char* str);
void strcpy(const char* destination, char* source);
int strcmp(const char* str1, const char* str2);

bool isDigit(char ch);
// TODO fix
int readInt(const char* strIterator, char endSym, int& intHolder, int* lengthRead = NULL);

#endif
