#pragma once
#include "JuceHeader.h"
#include "WavetableOscillator.h"

class WavetableSynth
{
public:
	void prepareToPlay(double sampleRate);
	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
	static std::vector<float> generateSineWaveTable();
	static float midiNoteNumberToFrequency(int midiNoteNumber);
	void intializeOscillators();
	void handleMidiEvent(const juce::MidiMessage& midiEvent);
	void render(juce::AudioBuffer<float>& buffer, int startSample, int endSample);
	
	double sampleRate;
    std::vector<WavetableOscillator> oscillators;

};

	

