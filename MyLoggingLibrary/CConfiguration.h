#pragma once
#include "CAppender.h"
#include "CLogger.h"

class MYLOGGINGLIBRARY_API CConfiguration
{
public:
	CConfiguration();
	~CConfiguration();

public:
	void AddAppender(const CAppender& appender) { _appenders.push_back(appender); }
	std::unique_ptr<CLogger> GetLogger(std::string name, Level level);
	std::vector<CAppender> GetAppenders() { return _appenders; }

private:	
	std::vector<CAppender> _appenders;
};

