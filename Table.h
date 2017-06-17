#include<fstream>
#include "Vector.h"

#ifndef TABLE
#define TABLE

class Table {
private:
	//Vector<Row> rows;

public:
	Table();
	Table(const Table& other);
	Table& operator=(const Table& other);

	bool populateFromStream(std::fstream& stream);
	void writeToStream(std::fstream& stream);

	void print();
	void edit(int row, int col, const char* newContent);

	~Table();
};

#endif
