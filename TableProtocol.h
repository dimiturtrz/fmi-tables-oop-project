#include "CellProtocol.h"

#ifndef TABLE_PROTOCOL
#define TABLE_PROTOCOL

class TableProtocol {
public:
	virtual CellProtocol* getCell(int row, int col) const = 0;
	virtual int getColumnWidth(int column) const = 0;
};

#endif
