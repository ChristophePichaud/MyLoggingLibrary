#include "stdafx.h"
#include "CLogger.h"
#include "CBasicLogger.h"
#include "CConsoleLogger.h"
#include "CFileLogger.h"
#include "CConfiguration.h"


CConfiguration::CConfiguration()
{
}


CConfiguration::~CConfiguration()
{
}

std::unique_ptr<CLogger> CConfiguration::GetLogger(std::string name, Level level)
{
	std::unique_ptr<CLogger> ptr = std::make_unique<CBasicLogger>();
	ptr->SetName(name);
	ptr->SetLevel(level);
	ptr->_pConfiguration = this;
	return ptr;
}
