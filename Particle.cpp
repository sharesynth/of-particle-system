//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#include "Particle.hpp"

void Particle::setup(Emitter emitter) {
    pos = emitter.eCenter + randomPointInCircle(emitter.eRad);
    vel = randomPointInCircle(emitter.velRad);
    time = 0;
    lifeTime = emitter.lifeTime;
    live = true;
}

void Particle::update(float dt, Emitter emitter){
    if (live) {
        
        vel.rotate(0, 0, emitter.rotate * dt);
        
        ofPoint acc;
        ofPoint delta = pos - emitter.eCenter;
        float len = delta.length();
        if (ofInRange(len, 0, emitter.eRad)) {
            delta.normalize();
            
            acc += delta * emitter.force;
            
            acc.x += -delta.y * emitter.spinning;
            acc.y += delta.x * emitter.spinning;
        }
        
        vel += acc * dt;
        vel *= (1 - emitter.friction);
        pos += vel * dt;
        time += dt;
        
        if (time >= lifeTime) {
            live = false;
        }
    }
}

void Particle::draw(){
    if ( live ) {
        float size = ofMap(fabs(time - lifeTime * 0.5), 0, lifeTime * 0.5, 3, 1);
        float hue = ofMap(time, 0, lifeTime, 128, 255);
        
        ofColor color = ofColor::red;
        color.setHue(hue);
        ofSetColor(color);
        ofDrawCircle(pos, size);
    }
}

ofPoint Particle::randomPointInCircle(float maxRad){
    ofPoint pnt;
    float rad = ofRandom(0, maxRad);
    float angle = ofRandom(0, M_TWO_PI);
    pnt.x = cos(angle) * rad;
    pnt.y = sin(angle) * rad;
    return pnt;
}
