/*
 ==============================================================================
 
 Synth.h
 Created: 4 Nov 2017 6:55:25pm
 Author:  Dylan
 
 ==============================================================================
 */

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int)//return true if sound played when midi note hit
    {
        return true;
    }
    bool appliesToChannel(int)//return true if sound triggered by midi on a channel
    {
        return true;
    }
};

