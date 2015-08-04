LEDCube
================

**Author:** Robert Gallup (robertgallup.com, github.com/robertgallup)  
**Date:** 8/4/2015  
**Version:** 1.0  

Arduino Code for running a 3x3x3 LED cube. The shield supported is sold by Radio Shack, and this code was derived from their original code.

Extensive modifications have been made:

1. All animation data was placed in program memory (PROGMEM). This allows many more animations to be used.
2. Animation data was moved to a separate .h tab to make it easier to edit and understand
3. New animations were added
4. Total number of animations is calculated from the data rather than having to enter it manually
5. Many more comments were added (some of them may be correct :) )
6. Animation function was changed to display an arbitrary animation. This allows more flexibility in sequencing animation. The sample program displays them sequentially, but that could easily be changed to support random sequencing, or sequencing based on user input.

