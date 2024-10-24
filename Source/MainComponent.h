#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::Component
{
public:
    MainComponent()
    {
        // Load the button images
        auto buttonUp = juce::ImageCache::getFromMemory(BinaryData::button_png, BinaryData::button_pngSize);
        auto buttonDown = juce::ImageCache::getFromMemory(BinaryData::downButton_png, BinaryData::downButton_pngSize);

        // Create and configure buttons and labels
        createButton(loadButton, loadLabel, "Load", buttonUp, buttonDown);
        createButton(writeButton, writeLabel, "Write", buttonUp, buttonDown);
        createButton(createButtonInstance, createLabel, "Create", buttonUp, buttonDown);
        createButton(editButton, editLabel, "Edit", buttonUp, buttonDown);
        createButton(controlButton, controlLabel, "Control", buttonUp, buttonDown);
        createButton(selectButton, selectLabel, "Select", buttonUp, buttonDown);
        createButton(midiButton, midiLabel, "MIDI", buttonUp, buttonDown);
        createButton(locateButton, locateLabel, "Locate", buttonUp, buttonDown);
        createButton(recordButton, recordLabel, "Record", buttonUp, buttonDown);
        createButton(stopButton, stopLabel, "Stop", buttonUp, buttonDown);
        createButton(playButton, playLabel, "Play", buttonUp, buttonDown);

        // Create and configure the soft buttons and labels
        for (int i = 0; i < 10; ++i)
        {
           softButtons[i] = std::make_unique<juce::ImageButton>("Soft " + juce::String(i + 1));
           softButtons[i]->setImages(
               false,  // should be rescaled
               true,   // preserve aspect ratio
               true,   // should highlight on mouse over
               buttonUp, 1.0f, {},  // normal image and opacity, no extra color overlay
               buttonDown, 1.0f, {},  // down image and opacity, no extra color overlay
               buttonUp, 1.0f, {}   // disabled image (use same as normal for now)
           );
           addAndMakeVisible(*softButtons[i]);
        }

        // Add components to main component
        addAndMakeVisible(imageComponent);

        setSize(800, 450); // Default window size
    }

    ~MainComponent() override {}

    void paint(juce::Graphics& g) override
    {
        g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    }

    void resized() override
    {
        using namespace juce;

        const float aspectRatio = 16.0f / 9.0f;  // Use the desired aspect ratio (16:9)
        auto bounds = getLocalBounds();  // Adds 20 pixels of padding
        int newWidth = bounds.getWidth();
        int newHeight = static_cast<int>(newWidth / aspectRatio);

        if (newHeight > bounds.getHeight())
        {
            newHeight = bounds.getHeight();
            newWidth = static_cast<int>(newHeight * aspectRatio);
        }
        
        auto gridBounds = juce::Rectangle<int>(0, 0, newWidth, newHeight);

        // Set the new size while maintaining the aspect ratio
        setSize(newWidth, newHeight);
        
        // Adjust the component layout as before
        auto scaleFactor = newWidth / 800.0f;  // Use the initial width (800) as the base reference

        // Define the size for the buttons and labels
        const float buttonWidth = 60.0f * scaleFactor;
        const float buttonHeight = 40.0f * scaleFactor;
        const float labelFontSize = 15.0f * scaleFactor; // Scale the label font size proportionally

        // Define the grid layout (6 rows x 6 columns)
        Grid grid;
        grid.templateRows = { Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr) };
        grid.templateColumns = { Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr),
                                   Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr),
                                   Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr), Grid::TrackInfo(1_fr) };
        
        grid.items = {
            GridItem(*softButtons[0]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 1
            GridItem(*softButtons[1]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 2
            GridItem(*softButtons[2]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 3
            GridItem(*softButtons[3]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 4
            GridItem(*softButtons[4]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 5
            GridItem(),
            GridItem(),
            GridItem(*loadButton).withWidth(buttonWidth).withHeight(buttonHeight),      // Load
            GridItem(*writeButton).withWidth(buttonWidth).withHeight(buttonHeight),     // Write
            
            GridItem().withArea(2, 1, 2, 7),
            GridItem(*createButtonInstance).withWidth(buttonWidth).withHeight(buttonHeight),    // Create
            GridItem(*editButton).withWidth(buttonWidth).withHeight(buttonHeight),              // Edit
            GridItem(*controlButton).withWidth(buttonWidth).withHeight(buttonHeight),           // Control
            
            GridItem().withArea(3, 1, 3, 7),
            GridItem(*selectButton).withWidth(buttonWidth).withHeight(buttonHeight),    // Select
            GridItem(*midiButton).withWidth(buttonWidth).withHeight(buttonHeight),      // MIDI
            GridItem(*locateButton).withWidth(buttonWidth).withHeight(buttonHeight),    // Locate
            
            GridItem(*softButtons[5]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 6
            GridItem(*softButtons[6]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 7
            GridItem(*softButtons[7]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 8
            GridItem(*softButtons[8]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 9
            GridItem(*softButtons[9]).withWidth(buttonWidth).withHeight(buttonHeight),  // Soft 10
            GridItem(),
 
            GridItem(*recordButton).withWidth(buttonWidth).withHeight(buttonHeight),    // Record
            GridItem(*stopButton).withWidth(buttonWidth).withHeight(buttonHeight),      // Stop
            GridItem(*playButton).withWidth(buttonWidth).withHeight(buttonHeight)       // Play
        };

        grid.alignItems = juce::Grid::AlignItems::center;
        grid.justifyItems = juce::Grid::JustifyItems::center;
        
        // Apply the grid layout
        grid.performLayout(gridBounds.toNearestInt());

        // Set label sizes and positions below buttons, using the grid layout
        setLabelPosition(loadButton, loadLabel, scaleFactor, labelFontSize);
        setLabelPosition(writeButton, writeLabel, scaleFactor, labelFontSize);
        setLabelPosition(createButtonInstance, createLabel, scaleFactor, labelFontSize);
        setLabelPosition(editButton, editLabel, scaleFactor, labelFontSize);
        setLabelPosition(controlButton, controlLabel, scaleFactor, labelFontSize);
        setLabelPosition(selectButton, selectLabel, scaleFactor, labelFontSize);
        setLabelPosition(midiButton, midiLabel, scaleFactor, labelFontSize);
        setLabelPosition(locateButton, locateLabel, scaleFactor, labelFontSize);
        setLabelPosition(recordButton, recordLabel, scaleFactor, labelFontSize);
        setLabelPosition(stopButton, stopLabel, scaleFactor, labelFontSize);
        setLabelPosition(playButton, playLabel, scaleFactor, labelFontSize);
    }
    
private:
    // Helper to create button and corresponding label
    void createButton(std::unique_ptr<juce::ImageButton>& button, juce::Label& label, const juce::String& buttonName, juce::Image buttonUp, juce::Image buttonDown)
    {
        button = std::make_unique<juce::ImageButton>(buttonName);
        button->setImages(
            false,
            true,
            true,
            buttonUp, 1.0f, {},
            buttonDown, 1.0f, {},
            buttonUp, 1.0f, {} `
        );
        addAndMakeVisible(*button);

        label.setText(buttonName, juce::dontSendNotification);
        label.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(label);
    }
    
    // Helper to position labels below buttons and resize them
    void setLabelPosition(std::unique_ptr<juce::ImageButton>& button, juce::Label& label, float scaleFactor, float fontSize)
    {
        auto buttonBounds = button->getBounds().toFloat();
        label.setFont(juce::Font(fontSize, juce::Font::plain).withTypefaceStyle("Regular"));  // Set the label font size proportionally
        label.setBounds(buttonBounds.translated(0, 30.0f * scaleFactor).toNearestInt());
    }

    // Image for the middle area
    juce::ImageComponent imageComponent;

    // Buttons and labels for the layout
    std::unique_ptr<juce::ImageButton> loadButton;
    juce::Label loadLabel;

    std::unique_ptr<juce::ImageButton> writeButton;
    juce::Label writeLabel;

    std::unique_ptr<juce::ImageButton> createButtonInstance;
    juce::Label createLabel;

    std::unique_ptr<juce::ImageButton> editButton;
    juce::Label editLabel;

    std::unique_ptr<juce::ImageButton> controlButton;
    juce::Label controlLabel;

    std::unique_ptr<juce::ImageButton> selectButton;
    juce::Label selectLabel;

    std::unique_ptr<juce::ImageButton> midiButton;
    juce::Label midiLabel;

    std::unique_ptr<juce::ImageButton> locateButton;
    juce::Label locateLabel;

    std::unique_ptr<juce::ImageButton> recordButton;
    juce::Label recordLabel;

    std::unique_ptr<juce::ImageButton> stopButton;
    juce::Label stopLabel;

    std::unique_ptr<juce::ImageButton> playButton;
    juce::Label playLabel;

    // Soft buttons and labels
    std::unique_ptr<juce::ImageButton> softButtons[10];
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
