#include "stdafx.h"
#include "CConsoleLogger.h"


CConsoleLogger::CConsoleLogger()
{
}


CConsoleLogger::~CConsoleLogger()
{
}

void CConsoleLogger::InternalLog(std::string message, Level level)
{
	std::string line = GetDefaultMessage(message, level);
	std::cout << line << std::endl;
}
