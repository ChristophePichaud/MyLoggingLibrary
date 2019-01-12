#pragma once
#include "Mode.h"

class CConfiguration;

class MYLOGGINGLIBRARY_API CLogger
{
public:
	CLogger();
	virtual ~CLogger();

public:
	Level GetLevel() const { return _level; }
	void SetLevel(Level level) { _level = level; }
	std::string GetName() const { return _name; }
	void SetName(std::string name) { _name = name; }

public:
	void Debug(std::string message);
	void Info(std::string message);
	void Warning(std::string message);
	void Error(std::string message);
	void Log(std::string message, Level level);
	std::string GetDefaultMessage(std::string message, Level level);

protected:
	virtual void InternalLog(std::string message, Level level) = 0;

private:
	Level _level = Level::Debug;
	std::string _name;
	CConfiguration * _pConfiguration;

	friend class CConfiguration;
};

