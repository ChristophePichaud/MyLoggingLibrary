# MyLoggingLibrary
A logging library

'
// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int main()
{
	CAppender appender1("log");
	appender1.SetLevel(Level::Debug);
	appender1.SetAppenderType(AppenderType::Console);

	// Appender 2 de type fichier
	CAppender appender2("log");
	appender2.SetLevel(Level::Info);
	appender2.SetAppenderType(AppenderType::File);

	// Objet de configuration
	CConfiguration config;
	config.AddAppender(appender1);
	config.AddAppender(appender2);

	// Get Logger(s) "log" & use => affichage en console et écriture en fichier
	std::unique_ptr<CLogger> logger = config.GetLogger("log", Level::Debug);
	for (int i = 0; i < 10; i++)
	{
		logger->Debug("Logging a Debug...");
		logger->Warning("Logging a Warning...");
		logger->Error("Logging an Error...");
		logger->Info("Logging an Info...");
	}
}
'
