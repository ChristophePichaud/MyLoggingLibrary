#pragma once
#include "Mode.h"

class MYLOGGINGLIBRARY_API CAppender
{
public:
	CAppender();
	CAppender(std::string name);
	~CAppender();

	public:
	std::string GetName() const { return _name; }
	void SetName(std::string name) { _name = name; }
	Level GetLevel() const { return _mode; }
	void SetLevel(Level mode) { _mode = mode; }
	AppenderType GetAppenderType() const { return _appendertype; }
	void SetAppenderType(AppenderType appendertype) { _appendertype = appendertype; }

private:
	std::string _name;
	Level _mode = Level::Debug;
	AppenderType _appendertype = AppenderType::Console;
};

