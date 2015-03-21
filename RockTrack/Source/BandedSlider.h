/*
  ==============================================================================

    BandedSlider.h
    Created: 21 Mar 2015 7:39:28pm
    Author:  user

  ==============================================================================
*/

#ifndef BANDEDSLIDER_H_INCLUDED
#define BANDEDSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class BandedSlider : public Slider
{
public:
	BandedSlider();
	explicit BandedSlider(const String& componentName) ;
	BandedSlider(SliderStyle style, TextEntryBoxPosition textBoxPosition);
	~BandedSlider();
private:
	//
};




#endif  // BANDEDSLIDER_H_INCLUDED
