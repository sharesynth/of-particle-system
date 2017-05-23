//
//  Emitter.cpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-23.
//
//

#include "Emitter.hpp"

void Emitter::setup() {
    eCenter = ofPoint( ofGetWidth() / 2, ofGetHeight() / 2 );
    radius = 100;
    velocityLimit = 0;
    lifeTime = 2.0;
    rotate = 0;
    force = 1000;
    spinning = 1000;
    friction = 0.05;
    spread = PI / 32;
}

void Emitter::setSpread(float value) {
    spread = PI / value;
};