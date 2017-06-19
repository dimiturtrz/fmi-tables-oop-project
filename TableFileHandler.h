#include "Table.h"

#ifndef TABLE_FILE_HANDLER
#define TABLE_FILE_HANDLER

class TableFileHandler: public BaseFileHandler {
private:
	Table table;

	virtual bool interpretInput(const char* command, const char* arguments);

	virtual bool open(const char* path);
	virtual bool save();
	virtual bool saveas(const char* path);
	virtual void close();
	void print();	
	void edit(const char* arguments);

	bool populateTable();
	void writeTableToStream(std::fstream& stream); 
};

#endif
