#include "ofApp.h"
#include "Particle.hpp"

void ofApp::setup(){
    ofSetFrameRate(60);
    initializeVariables();
    setupDrawingBuffer();
    emitter.setup();
    setupGui();
}

void ofApp::setupDrawingBuffer() {
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F_ARB);
    fbo.begin();
    ofBackground(255, 255, 255);
    fbo.end();
}

void ofApp::initializeVariables() {
    drawInterface = true;
    history = 0.9;
    bornRate = 1500;
    bornCount = 0;
    time0 = ofGetElapsedTimef();
}

void ofApp::setupGui(){
    interf.setup();
    interf.addSlider("rate", &bornRate, 0, 3000);
    interf.addSlider("lifeTime", &emitter.lifeTime, 0, 5);
    interf.addSlider("history", &history, 0, 1);
    interf.addSlider("E. Radius", &emitter.radius, 0, 800);
    interf.addSlider("Vel. Limit", &emitter.velocityLimit, 0, 400);
    interf.addSlider("rotate", &emitter.rotate, -500, 500);
    interf.addSlider("spinning", &emitter.spinning, -1000, 1000);
    interf.addSlider("force", &emitter.force, -1000, 1000);
    interf.addSlider("friction", &emitter.friction, 0, 0.1);
}

void ofApp::deleteInactiveParticles() {
    int i = 0;
    while (i < p.size()) {
        if (!p[i].live) {
            p.erase(p.begin() + i);
        } else {
            i++;
        }
    }
}

float ofApp::computeDeltaTime() {
    float time = ofGetElapsedTimef();
    float dt = ofClamp(time - time0, 0, 0.1);
    time0 = time;
    return dt;
}

void ofApp::updateParticles(float dt) {
    for (int i = 0; i < p.size(); i++) {
        p[i].update(dt, emitter);
    }
}

void ofApp::addNewParticles(float dt) {
    bornCount += dt * bornRate;
    if (bornCount >= 1) {
        int bornN = int(bornCount);
        bornCount -= bornN;
        for (int i = 0; i < bornN; i++) {
            Particle newP;
            newP.setup(emitter);
            p.push_back(newP);
        }
    }
}

void ofApp::update(){
    deleteInactiveParticles();
    float dt = computeDeltaTime();
    addNewParticles(dt);
    updateParticles(dt);
}

void ofApp::draw(){
    ofBackground(255, 255, 255);
    drawParticles();
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
    if (drawInterface) {
        drawInstructions();
        interf.draw();
        drawEmitterRadius();
    }
}

void ofApp::drawParticles() {
    
    fbo.begin();
    ofEnableAlphaBlending();
    float alpha = (1 - history) * 255;
    ofSetColor(255, 255, 255, alpha);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    ofFill();
    
    for (int i = 0; i < p.size(); i++) {
        p[i].draw();
    }
    
    fbo.end();
}

void ofApp::drawInstructions() {
    string controlMessage = "Keys: Enter-toggle GUI, Space-screenshot, 1,2,...,9-load preset, Shift+1,2,...9-save preset";
    string particleMessage = "Particles: " + ofToString( p.size());
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(controlMessage, 20, 20);
    ofDrawBitmapString(particleMessage, 20, 40);
}

void ofApp::drawEmitterRadius() {
    ofSetCircleResolution(50);
    ofNoFill();
    ofSetColor(128, 128, 128);
    ofDrawCircle(emitter.eCenter, emitter.radius);
    ofSetCircleResolution(20);
}

void ofApp::saveRandomScreenshot() {
    ofImage image;
    image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    int n = ofRandom(0, 1000);
    string fileName = "screen" + ofToString( n ) + ".png";
    image.save(fileName);
}

void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        drawInterface = !drawInterface;
    }
    
    if (key == ' ') {
        saveRandomScreenshot();
    }

    if (key == '1') {
        interf.load(1);
    }
    
    if (key == '2') {
        interf.load(2);
    }
    
    if (key == '3') {
        interf.load(3);
    }
    
    if (key == '4') {
        interf.load(4);
    }
    
    if (key == '5') {
        interf.load(5);
    }
    
    if (key == '6') {
        interf.load(6);
    }
    
    if (key == '7') {
        interf.load(7);
    }
    
    if (key == '8') {
        interf.load(8);
    }
    
    if (key == '9') {
        interf.load(9);
    }
    
    // Save presets
    if (key == '!') {
        interf.save(1);
    }
    
    if (key == '@') {
        interf.save(2);
    }
    
    if (key == '#') {
        interf.save(3);
    }
    
    if (key == '$') {
        interf.save(4);
    }
    
    if (key == '%') {
        interf.save(5);
    }
    
    if (key == '^') {
        interf.save(6);
    }
    
    if (key == '&') {
        interf.save(7);
    }
    
    if (key == '*') {
        interf.save(8);
    }
    
    if (key == '(') {
        interf.save(9);
    }
}

void ofApp::mouseDragged(int x, int y, int button){
    if (drawInterface) {
        interf.mouseDragged(x, y);
    }
}

void ofApp::mousePressed(int x, int y, int button){
    if (drawInterface) {
        interf.mousePressed(x, y);
    }
}

void ofApp::mouseReleased(int x, int y, int button){
    interf.mouseReleased(x, y);
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}