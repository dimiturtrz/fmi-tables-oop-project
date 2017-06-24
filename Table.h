#include<fstream>
#include "helpers/Vector.h"
#include "Row.h"
#include "CellProtocol.h"
#include "TableProtocol.h"

#ifndef TABLE
#define TABLE

class Table: public TableProtocol {
private:
	Vector<Row> rows;
	Vector<int> columnWidths;

	void setColumnWidths();

public:
	bool populateFromStream(std::fstream& stream);
	void writeToStream(std::fstream& stream) const;
	void reset();

	void print() const;
	void edit(int row, int col, const char* newContent);

	CellProtocol* getCell(int row, int col) const;
	int getColumnWidth(int column) const;
};

#endif
