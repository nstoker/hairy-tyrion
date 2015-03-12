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

void initialiseLogger(String fileName);
void writeToLogger(String s);

extern ScopedPointer<FileLogger> theLog;


#endif  // LOGGER_H_INCLUDED
