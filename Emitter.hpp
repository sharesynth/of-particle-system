//
//  Emitter.hpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-23.
//
//

#ifndef Emitter_hpp
#define Emitter_hpp

#include "ofMain.h"

class Emitter{
public:
    ofPoint eCenter; // Emitter center
    float radius; // Emitter radius
    float velocityLimit; // Initial velocity limit
    float lifeTime; // Lifetime in seconds
    float rotate; // Direction rotation speed in angles per second
    float force; // Attraction/repulsion force inside emitter
    float spinning; // Spinning force inside emitter
    float spread; // Allowed range of angles
    float friction; // Friction, in the range [0, 1]
    
    void setup();
    void setSpread(float value);
};

#endif /* Emitter_hpp */
