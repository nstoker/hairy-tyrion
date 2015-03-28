/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "AppHeader.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);

	addAndMakeVisible(appHeader);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colours::lightsteelblue);

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello world of Rocksmith!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
	Rectangle<int> area = getLocalBounds();

	appHeader.setBounds(area.removeFromTop(75));
}
