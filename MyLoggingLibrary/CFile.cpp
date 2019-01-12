#include "stdafx.h"
#include "CFile.h"


CFile::CFile()
{
}

CFile::CFile(const std::string& filename, const FileMode& mode) : _filename(filename), _mode(mode)
{
}


CFile::~CFile()
{
	if (_file != nullptr)
	{
		Close();
	}
}

bool CFile::Open(const std::string& filename, const FileMode& mode)
{
	std::string sMode;
	_mode = mode;
	switch (mode)
	{
	case FileMode::Read:
		sMode = "r";
		break;

	case FileMode::Write:
		sMode = "w";
		break;

	case FileMode::Append:
		sMode = "a";
		break;
	}

	_filename = filename;
	fopen_s(&_file, _filename.c_str(), sMode.c_str());
	return true;
}

void CFile::ReadLine(std::string& data)
{
	char szBuffer[2048];
	memset(szBuffer, 0, sizeof(szBuffer));
	fgets(szBuffer, 2048, _file);

	std::string buffer(szBuffer);
	data = buffer;
}

void CFile::Read(std::string& data)
{
	char szBuffer[2048];
	memset(szBuffer, 0, sizeof(szBuffer));
	fread_s(szBuffer, 2048, 1, 2048, _file);

	std::string buffer(szBuffer);
	data = buffer;
}

void CFile::WriteLine(const std::string& data)
{
	fprintf(_file, "%s\n", data.data());
}

void CFile::Write(const std::string& data)
{
	fprintf(_file, "%s", data.data());
}

void CFile::SeekToEnd()
{
	fseek(_file, 0, SEEK_END);
}

void CFile::Close()
{
	fclose(_file);
	_file = nullptr;
}

FILE * CFile::GetFileHandle() const
{
	return _file;
}

const std::string& CFile::GetFileName() const
{
	return _filename;
}

