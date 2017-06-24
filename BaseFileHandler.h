#ifndef BASE_FILE_HANDLER
#define BASE_FILE_HANDLER

class BaseFileHandler {
protected:	
	std::fstream file;
	char* currFilePath;
	bool gettingInput;
	bool fileOpened;

	virtual bool interpretInput(const char* command, const char* arguments);

	virtual bool open(const char* path);
	virtual void close();
	virtual bool save() = 0;
	virtual bool saveas(const char* path) = 0;
	void exit();
public:
	void startGettingInput();
	BaseFileHandler();
	// destructor to make sure the file is closed
	virtual ~BaseFileHandler(); 
};

#endif
