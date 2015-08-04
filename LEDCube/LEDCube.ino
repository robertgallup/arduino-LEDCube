////////////////////////////////////////////////////////////////////////////////////////
//
// LED Cube Sample
//
// Several sample animations for a 3x3x3 LED Cube shield from Radio Shack.
// It is based on the original Radio Shack code, but with animation data in program memory
// it allows many more animations
//
// By Robert Gallup (http://www.robertgallup.com, http://www.github.com/robertgallup)
//
////////////////////////////////////////////////////////////////////////////////////////

#include "AnimationData.h"

// Number of animations
const unsigned int animations = (sizeof(animation) / 2 / 4 / 16);

void setup() {
  
  // Number of animations
//  animations = (sizeof(animation) / 2 / 4 / 16);
  
  // Initialize pins 2-13 for output
  for(int p=2; p<=13; p++) pinMode(p, OUTPUT);

}

void loop() {

  // Loop through each animation
  for (int i=0; i<animations; i++) showAnimation (i);

}
