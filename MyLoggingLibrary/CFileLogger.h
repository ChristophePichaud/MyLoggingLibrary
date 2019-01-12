#pragma once
#include "CLogger.h"

class MYLOGGINGLIBRARY_API CFileLogger : public CLogger
{
public:
	CFileLogger();
	CFileLogger(std::string filename);
	virtual ~CFileLogger();

protected:
	virtual void InternalLog(std::string message, Level level);

private:
	std::string _filename;
};

