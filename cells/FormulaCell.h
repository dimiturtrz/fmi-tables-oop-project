#include "../Cell.h"
#include "../Row.h"
#include "../Table.h"
//#include "../helpers/Stack.h"

#ifndef FORMULA_CELL
#define FORMULA_CELL

class FormulaCell: public Cell {
private:
	const Table* tableDelegate;
	int row1, col1;
	int row2, col2;
	char sign;
	//Stack<Cell*> operands;
	//Stack<char> operations;
public:
	FormulaCell(const char* initialCellString, const Table* delegate);
	void getCell(const char* str, int& end, int& cRow, int& cCol);

	virtual Cell* clone();
	virtual double evaluate();

	virtual void writeToStream(std::fstream& stream);
	virtual void print();
};

#endif
