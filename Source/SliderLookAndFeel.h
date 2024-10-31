// SliderLookAndFeel.h
#pragma once
#include <JuceHeader.h>

class SliderLookAndFeel : public juce::LookAndFeel_V4
{
public:
    SliderLookAndFeel();
    void drawLinearSlider (juce::Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle, juce::Slider &) override;
    
private:
    std::unique_ptr<juce::Drawable> sliderKnobImage;
};
