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
#include "RockTrack.h"
#include "Main.h"
//[/Headers]

#include "AppHeader.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AppHeader::AppHeader ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 45);


    //[Constructor] You can add your own custom stuff here..

	theLog->logMessage("Initialising header");

	addAndMakeVisible(menuBar = new MenuBarComponent(this));

	addAndMakeVisible(appTitle = new Label("appTitle", TRANS("RockTrack")));
	appTitle->setFont(Font("Tahoma",40.0f, Font::bold));
	appTitle->setJustificationType(Justification::topLeft);
	appTitle->setColour(Label::textColourId, Colours::white);
	appTitle->setEditable(false, false, false);

	addAndMakeVisible(appLogo = new ImageComponent("appLogo"));

	Image theLogo = ImageFileFormat::loadFrom(BinaryData::rockTrack_png, BinaryData::rockTrack_pngSize);
	if (theLogo.isValid())
		appLogo->setImage(theLogo,RectanglePlacement::centred + RectanglePlacement::onlyReduceInSize);

	resized();
    //[/Constructor]
}

AppHeader::~AppHeader()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
#if JUCE_MAC
	MenuBarModel::setMacMainMenu(nullptr);
#endif

	PopupMenu::dismissAllActiveMenus();

    //[/Destructor]
}

//==============================================================================
void AppHeader::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
	g.fillAll(Colours::darkslateblue);
    //[/UserPaint]
}

void AppHeader::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

	Rectangle<int>area = getLocalBounds();

	if (menuBar)
	{ 
		menuBar->setBounds(area.removeFromBottom(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
	}
		
	if (appLogo)
		appLogo->setBounds(area.removeFromLeft(50).reduced(2));

	if (appTitle)
		appTitle->setBounds(area.reduced(2));

    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void AppHeader::menuItemSelected(int menuItemID, int /* topLevelMenuIndex */)
{
	//
}

StringArray AppHeader::getMenuBarNames()
{
	const char * const names[] = { "File", nullptr };
	return StringArray(names);
}

PopupMenu AppHeader::getMenuForIndex(int menuIndex, const String& /*menuName*/)
{
	PopupMenu menu;
	ApplicationCommandManager* commandManager = &MainWindow::getApplicationCommandManager();

	theLog->logMessage("Menu index " + String(menuIndex));
	// Build the menu
	if (0 == menuIndex)
	{
		//
	}
	return menu;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AppHeader" componentName=""
                 parentClasses="public Component, public MenuBarModel" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="45">
  <BACKGROUND backgroundColour="800080"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
