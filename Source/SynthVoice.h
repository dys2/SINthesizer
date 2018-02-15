/*
 ==============================================================================
 
 SynthVoice.h
 Created: 4 Nov 2017 6:55:52pm
 Author:  Dylan
 
 ==============================================================================
 */

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public  SynthesiserVoice
{
public:
    bool canPlaySound (SynthesiserSound* sound) //return true if voice is capable of playing sound
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr; //if castsound to synthsound is successful it returns true;
    }
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)  //starts a new note when called
    {
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }
    
    void stopNote(float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;
        if (velocity == 0) clearCurrentNote();
    }
    
    void pitchWheelMoved (int newPitchWheelValue) //lets voice know wheel has been moved
    {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        env1.setAttack(2000);
        env1.setDecay(500);
        env1.setSustain(0.8);
        env1.setRelease(2000);
        
        for (int sample = 0; sample < numSamples; ++sample, ++startSample)
        {
            double sineWave = osc1.sinewave(frequency);
            double theSound = env1.adsr(sineWave, env1.trigger) * level;
            double filteredSound = filter1.lores(theSound, 200, 0.1);
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
        }
    }
private:
    double level;
    double frequency;
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
};

