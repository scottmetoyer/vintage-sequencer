#pragma once

#include <JuceHeader.h>
#include "SliderLookAndFeel.h"

class MainComponent :   public juce::Component,
                        public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;
    
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;
    
private:
    std::unique_ptr<juce::Drawable> backgroundImage;
    std::unique_ptr<juce::Drawable> functionButtonImage;
    std::unique_ptr<juce::Drawable> functionButtonPressedImage;
    std::unique_ptr<juce::Drawable> whiteButtonImage;
    std::unique_ptr<juce::Drawable> whiteButtonPressedImage;
    std::unique_ptr<juce::Drawable> softButtonImage;
    std::unique_ptr<juce::Drawable> softButtonPressedImage;
    std::unique_ptr<juce::Drawable> sliderKnobImage;
    
    std::unique_ptr<juce::DrawableButton> loadButton;
    juce::Label loadLabel;

    std::unique_ptr<juce::DrawableButton> writeButton;
    juce::Label writeLabel;

    std::unique_ptr<juce::DrawableButton> createButton;
    juce::Label createLabel;

    std::unique_ptr<juce::DrawableButton> editButton;
    juce::Label editLabel;

    std::unique_ptr<juce::DrawableButton> controlButton;
    juce::Label controlLabel;

    std::unique_ptr<juce::DrawableButton> selectButton;
    juce::Label selectLabel;

    std::unique_ptr<juce::DrawableButton> midiButton;
    juce::Label midiLabel;

    std::unique_ptr<juce::DrawableButton> locateButton;
    juce::Label locateLabel;

    std::unique_ptr<juce::DrawableButton> recordButton;
    juce::Label recordLabel;

    std::unique_ptr<juce::DrawableButton> stopButton;
    juce::Label stopLabel;

    std::unique_ptr<juce::DrawableButton> playButton;
    juce::Label playLabel;

    std::unique_ptr<juce::DrawableButton> softButtons[10];
    
    juce::Slider dataEntrySlider;
    SliderLookAndFeel sliderLookAndFeel;
    
    juce::String currentSizeAsString;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
