#include "../Cell.h"
#include "../Row.h"
#include "../Table.h"
//#include "../helpers/Stack.h"

#ifndef FORMULA_CELL
#define FORMULA_CELL

class FormulaCell: public Cell {
private:
	const TableProtocol* tableDelegate;
	int row1, col1;
	int row2, col2;
	double const1, const2;
	char sign;
	//Stack<Cell*> operands;
	//Stack<char> operations;
public:
	FormulaCell(const char* initialCellString, const TableProtocol* delegate);

	void readCell(const char* str, int& end, int& row, int& col);
	double readConst(const char* reader, int& end) const;

	CellProtocol* getCell(int row, int col) const;

	virtual Cell* clone();
	virtual double evaluate() const;

	virtual void writeToStream(std::fstream& stream) const;
	virtual void print(int width) const;
};

#endif
