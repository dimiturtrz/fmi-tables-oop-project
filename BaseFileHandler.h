#ifndef BASE_FILE_HANDLER
#define BASE_FILE_HANDLER

class BaseFileHandler {
protected:	
	std::fstream file;

	void interpretInput(const char* input);
	void open(const char* path);
	void close();
	void save();
	void saveas(const char* path);
	void exit();
public:
	void startGettingInput();
	// only destructor to make sure the file is closed
	~BaseFileHandler(); 
};

#endif
