#include "stdafx.h"
#include "CAppender.h"
#include "CLogger.h"
#include "CConsoleLogger.h"
#include "CFileLogger.h"
#include "CConfiguration.h"


CLogger::CLogger()
{
}


CLogger::~CLogger()
{
}

void CLogger::Log(std::string message, Level level)
{
	for (CAppender appender : _pConfiguration->GetAppenders())
	{
		if (appender.GetName() == GetName())
		{
			if (appender.GetAppenderType() == AppenderType::Console)
			{
				std::unique_ptr<CLogger> ptr = std::make_unique<CConsoleLogger>();
				ptr->SetName(GetName());
				ptr->SetLevel(appender.GetLevel());
				ptr->_pConfiguration = _pConfiguration;
				
				if (ptr->GetLevel() <= level)
					ptr->InternalLog(message, level);
			}
				
			if (appender.GetAppenderType() == AppenderType::File)
			{
				std::unique_ptr<CLogger> ptr = std::make_unique<CFileLogger>();
				ptr->SetName(GetName());
				ptr->SetLevel(appender.GetLevel());
				ptr->_pConfiguration = _pConfiguration;
				
				if (ptr->GetLevel() <= level)
					ptr->InternalLog(message, level);
			}
		}
	}
}

void CLogger::Debug(std::string message)
{
	Log(message, Level::Debug);
}

void CLogger::Warning(std::string message)
{
	Log(message, Level::Warning);
}

void CLogger::Info(std::string message)
{
	Log(message, Level::Info);
}

void CLogger::Error(std::string message)
{
	Log(message, Level::Error);
}

std::string CLogger::GetDefaultMessage(std::string message, Level level)
{
	time_t t = time(0);
	tm tm;
	localtime_s(&tm, &t);

	std::string slevel = CModeHelper::ToString(level);

	std::stringstream ss;
	ss << std::setw(4) << std::setfill('0') << tm.tm_year + 1900
		<< std::setw(2) << std::setfill('0') << tm.tm_mon
		<< std::setw(2) << std::setfill('0') << tm.tm_mday
		<< "."
		<< std::setw(2) << std::setfill('0') << tm.tm_hour
		<< std::setw(2) << std::setfill('0') << tm.tm_min
		<< std::setw(2) << std::setfill('0') << tm.tm_sec
		<< " | " << slevel << " | " << message;

	std::string line = ss.str();
	return line;
}
