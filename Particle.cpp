//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#include "Particle.hpp"

void Particle::setup(Params param) {
    pos = param.eCenter + randomPointInCircle( param.eRad );
    vel = randomPointInCircle( param.velRad );
    time = 0;
    lifeTime = param.lifeTime;
    live = true; // true;
}

void Particle::update(float dt){
    if (live) {
        
        vel.rotate(0, 0, param.rotate * dt);
        
        ofPoint acc;
        ofPoint delta = pos - param.eCenter;
        float len = delta.length();
        if (ofInRange(len, 0, param.eRad)) {
            delta.normalize();
            
            acc += delta * param.force;
            
            acc.x += -delta.y * param.spinning;
            acc.y += delta.x * param.spinning;
        }
        
        vel += acc * dt;
        vel *= (1 - param.friction);
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

        ofColor color = ofColor::red;
        float hue = ofMap(time, 0, lifeTime, 128, 255);
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
