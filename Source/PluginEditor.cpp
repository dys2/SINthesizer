/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SinthesizerAudioProcessorEditor::SinthesizerAudioProcessorEditor (SinthesizerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    setSize (800, 600);
}

SinthesizerAudioProcessorEditor::~SinthesizerAudioProcessorEditor()
{
}

//==============================================================================
void SinthesizerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    g.setFont (20.0f);
    g.drawFittedText ("SINthesizer", getLocalBounds(), Justification::top, 1);
}

void SinthesizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto size = getLocalBounds();
}
