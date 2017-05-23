//
//  Particle.hpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"
#include "Emitter.hpp"

class Particle{
public:
    ofPoint pos; // Position
    ofPoint vel; // Velocity
    float time; // Time of living
    float lifeTime; // Allowed lifetime
    bool live;
    void setup(Emitter param); // Start particle
    void update(float dt, Emitter param); // Recalculate physics
    void draw(); // Draw particle
    ofPoint randomPointInCircle(float maxRad);
};

#endif /* Particle_hpp */
