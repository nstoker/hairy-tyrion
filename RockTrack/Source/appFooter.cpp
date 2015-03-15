/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "AppFooter.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AppFooter::AppFooter ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (100, 40);


    //[Constructor] You can add your own custom stuff here..
	addAndMakeVisible(appVersion = new Label("appVersion", TRANS("Version ") + ProjectInfo::versionString));
	appVersion->setFont(Font(10.0f, Font::plain));
	appVersion->setJustificationType(Justification::centredRight);
	appVersion->setColour(Label::textColourId, Colours::antiquewhite);
	appVersion->setEditable(false, false, false);
    //[/Constructor]
}

AppFooter::~AppFooter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AppFooter::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff31012d));

    //[UserPaint] Add your own custom painting code here..
	g.fillAll(Colour(Colours::purple));
    //[/UserPaint]
}

void AppFooter::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	Rectangle<int> area = getLocalBounds();
	if (appVersion)
		appVersion->setBounds(area.removeFromRight(100));
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AppFooter" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="100" initialHeight="40">
  <BACKGROUND backgroundColour="ff31012d"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
