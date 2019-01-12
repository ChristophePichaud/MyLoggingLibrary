#pragma once
#include "CLogger.h"

class MYLOGGINGLIBRARY_API CBasicLogger : public CLogger
{
public:
	CBasicLogger();
	virtual ~CBasicLogger();

protected:
	virtual void InternalLog(std::string message, Level level);
};

