#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <future>
#include "TypeDefines.h"

#if defined(_WIN64) || defined(_WIN32)
	#define DATA_FOLDER "../../../../Database/Data/"
#elif defined(__linux__)
	#define DATA_FOLDER "../../Database/Data/"
#endif

using namespace std;

class FileReader
{
private:

public:
	FileReader(string fileName, bool &isFile, bool openStream = false);
	~FileReader();
	void DeleteBuffer();
	void LoadFile();
	string fileString;
	PListType fileStringSize;
	string fileName;
	ifstream *copyBuffer;
};