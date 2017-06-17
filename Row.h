#include<iostream>
#include<fstream>

#ifndef ROW
#define ROW

class Row {
	//Vector<Cell> cells;

public:
	Row();
	Row(char* rowStr);

	void writeToStream(std::fstream& stream);
	void print();
	void setCell(int col, const char* newContent);
};

#endif
