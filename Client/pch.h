// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <memory>
#include <iomanip>

// TODO: add headers that you want to pre-compile here
#include "..\MyLoggingLibrary\MyLoggingLibrary.h"

#include "..\MyLoggingLibrary\CFile.h"
#include "..\MyLoggingLibrary\CLogger.h"
#include "..\MyLoggingLibrary\CConsoleLogger.h"
#include "..\MyLoggingLibrary\CFileLogger.h"
#include "..\MyLoggingLibrary\CConfiguration.h"
#include "..\MyLoggingLibrary\CAppender.h"

#pragma comment(lib, "..\\MyLoggingLibrary\\x64\\Debug\\MyLoggingLibrary.lib")

#endif //PCH_H
