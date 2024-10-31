/*
  ==============================================================================

    BorderBoundsConstrainer.cpp
    Created: 29 Oct 2024 1:50:05pm
    Author:  Scott Metoyer

  ==============================================================================
*/

#include "BorderBoundsConstrainer.h"

void BorderBoundsConstrainer::checkBounds(juce::Rectangle<int>& bounds, const juce::Rectangle<int>& previous,
                                          const juce::Rectangle<int>& limits,
                                          bool stretching_top, bool stretching_left,
                                          bool stretching_bottom, bool stretching_right) {
  border_.subtractFrom(bounds);
  juce::ComponentBoundsConstrainer::checkBounds(bounds, previous, limits,
                                          stretching_top, stretching_left,
                                          stretching_bottom, stretching_right);
  border_.addTo(bounds);
}
