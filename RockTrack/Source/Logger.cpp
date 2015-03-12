/*
  ==============================================================================

    Logger.cpp
    Created: 9 Mar 2015 7:55:57pm
    Author:  user

  ==============================================================================
*/

#include "Logger.h"

ScopedPointer<FileLogger> theLog;

void initialiseLogger(String appName)
{
	theLog = FileLogger::createDefaultAppLogger(appName, appName + ".log2", TRANS("Rocktrack application startup"), 128 * 1024);
}

File getLoggerPath()
{
	return theLog->getLogFile().getParentDirectory();
}

void writeToLogger(String s)
{
	theLog->writeToLog(s);
}

