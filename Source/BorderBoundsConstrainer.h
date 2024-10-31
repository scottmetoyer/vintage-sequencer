#pragma once

#include <JuceHeader.h>

class BorderBoundsConstrainer : public juce::ComponentBoundsConstrainer {
  public:
    BorderBoundsConstrainer() : ComponentBoundsConstrainer() { }

    virtual void checkBounds(juce::Rectangle<int>& bounds, const juce::Rectangle<int>& previous,
                             const juce::Rectangle<int>& limits,
                             bool stretching_top, bool stretching_left,
                             bool stretching_bottom, bool stretching_right) override;

    void setBorder(juce::BorderSize<int> border) { border_ = border; }

  protected:
    juce::BorderSize<int> border_;
};
