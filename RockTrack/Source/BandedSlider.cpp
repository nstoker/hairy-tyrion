/*
  ==============================================================================

    BandedSlider.cpp
    Created: 21 Mar 2015 7:39:28pm
    Author:  user

  ==============================================================================
*/

#include "BandedSlider.h"
#include "../JuceLibraryCode/modules/juce_gui_extra/juce_gui_extra.h"

BandedSlider::BandedSlider() 
{
	
}

BandedSlider::BandedSlider(const String& componentName) : Slider(componentName)
{
	Slider::Slider(LinearHorizontal, TextBoxLeft);
}

BandedSlider::BandedSlider(SliderStyle style, TextEntryBoxPosition textBoxPosition) : Slider(style, textBoxPosition)
{
	//
}

BandedSlider::~BandedSlider()
{
	//
}
