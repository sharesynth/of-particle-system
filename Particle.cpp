//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#include "Particle.hpp"

void Particle::setup(Emitter emitter) {
    position = emitter.eCenter + randomPointInCircle(emitter.radius);
    velocity = randomPointInCircle(emitter.velocityLimit);
    time = 0;
    lifeTime = emitter.lifeTime;
    live = true;
}

void Particle::update(float deltaTime, Emitter emitter){
    if (live) {
        velocity.rotate(0, 0, emitter.rotate * deltaTime);
        ofPoint acceleration;
        ofPoint delta = position - emitter.eCenter;
        float len = delta.length();
        if (ofInRange(len, 0, emitter.radius)) {
            delta.normalize();
            acceleration += delta * emitter.force;
            acceleration.x += -delta.y * emitter.spinning;
            acceleration.y += delta.x * emitter.spinning;
        }
        
        velocity += acceleration * deltaTime;
        velocity *= (1 - emitter.friction);
        position += velocity * deltaTime;
        time += deltaTime;
        if (time >= lifeTime) {
            live = false;
        }
    }
}

void Particle::draw(){
    if (live) {
        float size = ofMap(fabs(time - lifeTime * 0.5), 0, lifeTime * 0.5, 3, 1);
        float hue = ofMap(time, 0, lifeTime, 128, 255);
        ofColor color = ofColor::red;
        color.setHue(hue);
        ofSetColor(color);
        ofDrawCircle(position, size);
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