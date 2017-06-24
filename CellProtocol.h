#ifndef CELL_PROTOCOL
#define CELL_PROTOCOL

class CellProtocol {
public:	
	virtual double evaluate() const = 0;
	virtual int getStringLength() const = 0;
};

#endif
