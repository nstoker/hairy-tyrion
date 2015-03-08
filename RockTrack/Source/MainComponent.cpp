/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);

	addAndMakeVisible(appHeader);
	addAndMakeVisible(appFooter);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello world of Rocksmith!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
	Rectangle<int> area = getLocalBounds();

	appHeader.setBounds(area.removeFromTop(45));
	appFooter.setBounds(area.removeFromBottom(20));
}
