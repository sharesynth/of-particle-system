//
//  Slider.hpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#ifndef Slider_hpp
#define Slider_hpp

#include "ofMain.h"

class Slider {
public:
    string title; // Title
    ofRectangle rect; // Rectangle for drawing
    float *value; // Pointer to value which the slider changes
    float minV, maxV; // Minimum and maximum values
};

#endif /* Slider_hpp */
