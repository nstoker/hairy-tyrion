/*
  ==============================================================================

    helperFunctions.cpp
    Created: 8 Mar 2015 9:29:56pm
    Author:  user

  ==============================================================================
*/

#include "helperFunctions.h"

void setLabel(Label* theLabel, Font theFont, Justification theJustification, Colour theTextColour)
{
	theLabel->setFont(theFont);
	theLabel->setJustificationType(theJustification);
	theLabel->setColour(Label::textColourId, theTextColour);
}