#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    backgroundImage             = juce::Drawable::createFromImageData (BinaryData::Background_svg,              BinaryData::Background_svgSize);
    functionButtonImage         = juce::Drawable::createFromImageData (BinaryData::Function_Button_svg,         BinaryData::Function_Button_svgSize);
    functionButtonPressedImage  = juce::Drawable::createFromImageData (BinaryData::Function_Button_Pressed_svg, BinaryData::Function_Button_Pressed_svgSize);
    whiteButtonImage            = juce::Drawable::createFromImageData (BinaryData::White_Button_svg,            BinaryData::White_Button_svgSize);
    whiteButtonPressedImage     = juce::Drawable::createFromImageData (BinaryData::White_Button_Pressed_svg,    BinaryData::White_Button_Pressed_svgSize);
    softButtonImage             = juce::Drawable::createFromImageData (BinaryData::Soft_Button_svg,             BinaryData::Soft_Button_svgSize);
    softButtonPressedImage      = juce::Drawable::createFromImageData (BinaryData::Soft_Button_Pressed_svg,     BinaryData::Soft_Button_Pressed_svgSize);
    sliderKnobImage             = juce::Drawable::createFromImageData (BinaryData::Slider_Knob_svg,             BinaryData::Slider_Knob_svgSize);
    
    loadButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    loadButton->setImages(whiteButtonImage.get(), whiteButtonImage.get(), whiteButtonPressedImage.get());
    addAndMakeVisible(*loadButton);
    
    writeButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    writeButton->setImages(whiteButtonImage.get(), whiteButtonImage.get(), whiteButtonPressedImage.get());
    addAndMakeVisible(*writeButton);
    
    createButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    createButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*createButton);
    
    editButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    editButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*editButton);
    
    controlButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    controlButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*controlButton);
    
    selectButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    selectButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*selectButton);
    
    midiButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    midiButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*midiButton);
    
    locateButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    locateButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*locateButton);
    
    recordButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    recordButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*recordButton);
    
    stopButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    stopButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*stopButton);
    
    playButton = std::make_unique<juce::DrawableButton>("Load", juce::DrawableButton::ButtonStyle::ImageStretched);
    playButton->setImages(functionButtonImage.get(), functionButtonImage.get(), functionButtonPressedImage.get());
    addAndMakeVisible(*playButton);

    // Create and configure the soft buttons and labels
    for (int i = 0; i < 10; ++i)
    {
        softButtons[i] = std::make_unique<juce::DrawableButton>("Soft " + juce::String(i + 1), juce::DrawableButton::ButtonStyle::ImageStretched);
        softButtons[i]->setImages(softButtonImage.get(), softButtonImage.get(), softButtonPressedImage.get());
        addAndMakeVisible(*softButtons[i]);
    }

    dataEntrySlider.setRange (0, 100);
    dataEntrySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    dataEntrySlider.setLookAndFeel(&sliderLookAndFeel);
    dataEntrySlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, false, false);
    dataEntrySlider.addListener (this);

    addAndMakeVisible (dataEntrySlider);
    
    setSize(800, 256);
}

MainComponent::~MainComponent() {
    dataEntrySlider.setLookAndFeel (nullptr);
}

//==============================================================================
void MainComponent::paint(juce::Graphics &g)
{
    using namespace juce;

    if (backgroundImage != nullptr)
    {
        auto bounds = getLocalBounds().toFloat();
        backgroundImage->drawWithin(g, bounds, juce::RectanglePlacement::stretchToFit, 1.0f);
    }
    
    // g.drawText (currentSizeAsString, getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    using namespace juce;
    
    auto bounds = getLocalBounds();
    
    currentSizeAsString = juce::String (getWidth()) + " x " + juce::String (getHeight());
    
    int newWidth = bounds.getWidth();
    int newHeight = bounds.getHeight();
    
    float scaleX  = newWidth / 800.0f;
    float scaleY  = newHeight / 256.0f;
    
    float buttonWidth     = 30.0f * scaleX;
    float buttonHeight    = 12.0f * scaleY;
    
    // const float labelFontSize   = 10.0f * scaleX;
    
    loadButton->setBounds       (660 * scaleX, 76 * scaleY, buttonWidth, buttonHeight);
    writeButton->setBounds      (720 * scaleX, 76 * scaleY, buttonWidth, buttonHeight);
    
    createButton->setBounds     (600 * scaleX, 120 * scaleY, buttonWidth, buttonHeight);
    editButton->setBounds       (660 * scaleX, 120 * scaleY, buttonWidth, buttonHeight);
    controlButton->setBounds    (720 * scaleX, 120 * scaleY, buttonWidth, buttonHeight);
    
    selectButton->setBounds     (600 * scaleX, 165 * scaleY, buttonWidth, buttonHeight);
    midiButton->setBounds       (660 * scaleX, 165 * scaleY, buttonWidth, buttonHeight);
    locateButton->setBounds     (720 * scaleX, 165 * scaleY, buttonWidth, buttonHeight);
    
    recordButton->setBounds     (600 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    stopButton->setBounds       (660 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    playButton->setBounds       (720 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    
    softButtons[0]->setBounds   (154 * scaleX, 86 * scaleY, buttonWidth, buttonHeight);
    softButtons[1]->setBounds   (240 * scaleX, 86 * scaleY, buttonWidth, buttonHeight);
    softButtons[2]->setBounds   (326 * scaleX, 86 * scaleY, buttonWidth, buttonHeight);
    softButtons[3]->setBounds   (412 * scaleX, 86 * scaleY, buttonWidth, buttonHeight);
    softButtons[4]->setBounds   (498 * scaleX, 86 * scaleY, buttonWidth, buttonHeight);
    softButtons[5]->setBounds   (154 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    softButtons[6]->setBounds   (240 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    softButtons[7]->setBounds   (326 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    softButtons[8]->setBounds   (412 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    softButtons[9]->setBounds   (498 * scaleX, 209 * scaleY, buttonWidth, buttonHeight);
    
    const float sliderWidth     = 28.0f * scaleX;
    const float sliderHeight    = 144.0f * scaleY;
    
    dataEntrySlider.setBounds (44 * scaleX, 73 * scaleY, sliderWidth, sliderHeight);
}

void MainComponent::sliderValueChanged(juce::Slider* slider)
{
    // Handle the slider change here
}
