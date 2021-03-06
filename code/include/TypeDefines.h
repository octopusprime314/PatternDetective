/** @file TypeDefines.h
 *  @brief Contains all special types used for pattern processing
 *
 *  List of data types for pattern processing
 *
 *  @author Peter J. Morley (pmorley)
 */
#pragma once
#include <sstream>
#include <vector>
#define GREATERTHAN4GB 0
using namespace std;

#define ARCHIVE_FOLDER LOGGERPATH

#if defined(_WIN64) || defined(_WIN32)
#define HELPFILEPATH "../../HELP.txt"
#define DATA_FOLDER "../../database/data/"
#elif defined(__linux__)
#define HELPFILEPATH "../HELP.txt"
#define DATA_FOLDER "../database/data/"
#endif

/** Defines the size of pattern index storage. 
 *  If the file size is greater than 4 GB than the address space
 *  size has to be increased from 32 bit to 64 bit storage.
 */
#if GREATERTHAN4GB
using PListType = unsigned long long;
using PListSignedType = signed long long;
#else
using PListType = unsigned long;
using PListSignedType = signed long;
#endif

using PatternType = string;
using PatternData = vector<vector<PListType>*>;

/** Level package keeps track of level processing information */
struct LevelPackage
{
	unsigned int currLevel;
	unsigned int threadIndex;
	unsigned int inceptionLevelLOL;
	unsigned int coreIndex;
	bool useRAM;
    bool prevLevelProcType;
};

/** Pattern search methods */
enum PatternDiscoveryType
{
	OVERLAP_PATTERNS,
	NONOVERLAP_PATTERNS,
	ANY_PATTERNS
};
