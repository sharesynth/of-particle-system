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
#include "Params.hpp"

class Particle{
public:
    ofPoint pos; // Position
    ofPoint vel; // Velocity
    float time; // Time of living
    float lifeTime; // Allowed lifetime
    bool live;
    void setup(Params param); // Start particle
    void update( float dt ); // Recalculate physics
    void draw(); // Draw particle
    ofPoint randomPointInCircle( float maxRad );
};

#endif /* Particle_hpp */
