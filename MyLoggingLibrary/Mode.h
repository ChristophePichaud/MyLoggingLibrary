#pragma once

enum AppenderType
{
	Console,
	File
};

enum Level
{
	Debug = 0,
	Warning = 1,
	Info = 2,
	Error = 3
};

class MYLOGGINGLIBRARY_API CModeHelper
{
public:
	static std::string ToString(Level mode)
	{
		std::string m;
		
		switch (mode)
		{
		case Level::Debug:
			m = "DEBUG";
			break;
		case Level::Warning:
			m = "WARNING";
			break;
		case Level::Error:
			m = "ERROR";
			break;
		case Level::Info:
			m = "INFO";
			break;
		}

		return m;
	}
};
