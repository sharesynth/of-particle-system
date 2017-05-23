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
    void setup();
    ofPoint eCenter; // Emitter center
    float eRad; // Emitter radius
    float velRad; // Initial velocity limit
    float lifeTime; // Lifetime in seconds
    float rotate; // Direction rotation speed in angles per second
    float force; // Attraction/repulsion force inside emitter
    float spinning; // Spinning force inside emitter
    float friction; // Friction, in the range [0, 1]
};

#endif /* Emitter_hpp */
