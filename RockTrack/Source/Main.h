/*
  ==============================================================================

    Main.h
    Created: 28 Mar 2015 10:26:32pm
    Author:  user

  ==============================================================================
*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

class MainWindow : public DocumentWindow
{
public:
	MainWindow(String name);

	void closeButtonPressed() override;
	/*
	// This is called when the user tries to close this window. Here, we'll just
	// ask the app to quit when this happens, but you can change this to do
	// whatever you need.
	*/
	
	// (return the command manager object used to dispatch command events)
	static ApplicationCommandManager& getApplicationCommandManager();


	/* Note: Be careful if you override any DocumentWindow methods - the base
	class uses a lot of them, so by overriding you might break its functionality.
	It's best to do all your work in your content component instead, but if
	you really have to override any DocumentWindow methods, make sure your
	subclass also calls the superclass's method.
	*/

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
};


#endif  // MAIN_H_INCLUDED
