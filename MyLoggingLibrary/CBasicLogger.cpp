#include "stdafx.h"
#include "CBasicLogger.h"


CBasicLogger::CBasicLogger()
{
}


CBasicLogger::~CBasicLogger()
{
}

void CBasicLogger::InternalLog(std::string message, Level level)
{
	std::string line = GetDefaultMessage(message, level);
	std::cout << line << std::endl;
}
