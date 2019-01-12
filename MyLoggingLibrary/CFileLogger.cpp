#include "stdafx.h"
#include "CFileLogger.h"
#include "CFile.h"

CFileLogger::CFileLogger()
{
	time_t t = time(0);
	tm tm;
	localtime_s(&tm, &t);
	char sz[255];
	memset(sz, 0, sizeof(sz));
	//asctime_s(sz, sizeof(sz), &tm);
	//std::cout << sz;
	//sprintf(sz, "%02d/%02d/%04d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon, tm.tm_year, tm.tm_hour, tm.tm_min, tm.tm_sec)
	sprintf_s(sz, sizeof(sz), "%04d%02d%02d.log", tm.tm_year + 1900, tm.tm_mon, tm.tm_mday);
	_filename = sz;
}

CFileLogger::CFileLogger(std::string filename) : _filename(filename)
{
}


CFileLogger::~CFileLogger()
{
}

void CFileLogger::InternalLog(std::string message, Level level)
{
	std::string line = GetDefaultMessage(message, level);

	CFile file;
	file.Open(_filename, FileMode::Append);
	//file.SeekToEnd();
	file.WriteLine(line);
	file.Close();
}
