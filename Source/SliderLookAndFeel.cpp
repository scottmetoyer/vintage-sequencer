// SliderLookAndFeel.cpp
#include "SliderLookAndFeel.h"

SliderLookAndFeel::SliderLookAndFeel()
{
    sliderKnobImage = juce::Drawable::createFromImageData(BinaryData::Slider_Knob_svg, BinaryData::Slider_Knob_svgSize);
}

void SliderLookAndFeel::drawLinearSlider (juce::Graphics &g,
                                          int x, int y, int width, int height,
                                          float sliderPos,
                                          float minSliderPos, float maxSliderPos,
                                          juce::Slider::SliderStyle style, juce::Slider &slider)
{
    
    auto bounds = slider.getLocalBounds();
    
    float proportion = slider.valueToProportionOfLength(slider.getValue());
    proportion = 1.0f - proportion;
    
    // Define thumb dimensions as a proportion of slider dimensions
    const float thumbWidth  = width * 1.0f;
    const float thumbHeight = bounds.getHeight() * 0.1f;

    // Center thumb within slider width
    float thumbX = x + (width - thumbWidth) / 2.0f;
   
    // Calculate thumbY based on the proportion and adjust for thumb height
    float thumbY = (proportion * (bounds.getHeight() - thumbHeight));

    juce::Rectangle<float> thumbBounds(thumbX, thumbY, thumbWidth, thumbHeight); 

    sliderKnobImage->drawWithin(g, thumbBounds, juce::RectanglePlacement::fillDestination, 1.0f);
}
