#ifndef TABLE_FILE_HANDLER
#define TABLE_FILE_HANDLER

class TableFileHandler: public BaseFileHandler {
private:
	virtual bool interpretInput(const char* command, const char* arguments);

	virtual bool open(const char* path);
	virtual void save();
	virtual bool saveas(const char* path);
	void print();	
	void edit(const char* arguments);

	void populateTable();
	void writeTableToStream(std::fstream& stream); 
};

#endif
