/*
  ==============================================================================

    Logger.cpp
    Created: 9 Mar 2015 7:55:57pm
    Author:  user

  ==============================================================================
*/

#include "Logger.h"

CLogger::CLogger(String appName)
{
	//
}

void CLogger::initialise(String appName)
{
	theLog = FileLogger::createDefaultAppLogger(appName, appName + ".log", "RockTrack application startup", 128 * 1024);
}

File CLogger::getPath()
{
	return theLog->getLogFile().getParentDirectory()
}

void CLogger::write(String s)
{
	theLog->writeToLog(s);
}

