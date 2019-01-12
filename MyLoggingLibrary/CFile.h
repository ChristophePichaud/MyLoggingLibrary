#pragma once
#include <stdio.h>

enum FileMode
{
	Read,
	Write,
	Append
};

class MYLOGGINGLIBRARY_API CFile
{
public:
	CFile();
	CFile(const std::string& filename, const FileMode& mode);
	CFile(const CFile& file) = delete;
	~CFile();

public:
	CFile& operator=(const CFile& right) = delete;

public:
	bool Open(const std::string& filename, const FileMode& mode);
	void ReadLine(std::string& data);
	void Read(std::string& data);
	void WriteLine(const std::string& data);
	void Write(const std::string& data);
	void SeekToEnd();
	void Close();

public:
	FILE * GetFileHandle() const;
	const std::string& GetFileName() const;

private:
	FileMode _mode;
	FILE * _file;
	std::string _filename;
};

