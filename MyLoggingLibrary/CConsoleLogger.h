#pragma once
#include "CLogger.h"

class MYLOGGINGLIBRARY_API CConsoleLogger : public CLogger
{
public:
	CConsoleLogger();
	virtual ~CConsoleLogger();

protected:
	virtual void InternalLog(std::string message, Level level);
};

