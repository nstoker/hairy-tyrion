/*
  ==============================================================================

    Logger.h
    Created: 9 Mar 2015 7:55:57pm
    Author:  user

  ==============================================================================
*/

#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class CLogger {
public:
	CLogger(String appName);
	~CLogger(){};

	void initialise(String s);
	void write(String s);
	File getPath();

private:
	ScopedPointer<FileLogger> theLog;
};

#endif  // LOGGER_H_INCLUDED
