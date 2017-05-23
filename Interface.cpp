//
//  Interface.cpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#include "Interface.hpp"

void Interface::setup(){
    selected = -1;
}

void Interface::addSlider( string title, float *value, float minV, float maxV ){
    Slider s;
    s.title = title;
    s.rect = ofRectangle( 20, 60 + slider.size() * 40, 150, 30 );
    s.value = value;
    s.minV = minV;
    s.maxV = maxV;
    slider.push_back( s );
}

void Interface::draw(){
    for (int i=0; i<slider.size(); i++) {
        Slider &s = slider[i];
        ofRectangle r = s.rect;
        ofFill();
        ofSetColor( 255, 255, 255 );
        ofDrawRectangle( r );
        ofSetColor( 0, 0, 0 );
        ofNoFill();
        ofDrawRectangle( r );
        ofFill();
        float w = ofMap( *s.value, s.minV, s.maxV, 0, r.width );
        ofDrawRectangle( r.x, r.y + 15, w, r.height - 15 );
        ofDrawBitmapString( s.title + " " + ofToString( *s.value, 2 ), r.x + 5, r.y + 12 );
    }
}

void Interface::mousePressed( int x, int y ){
    for (int i=0; i<slider.size(); i++) {
        Slider &s = slider[i];
        ofRectangle r = s.rect;
        if ( ofInRange( x, r.x, r.x + r.width ) && ofInRange( y, r.y, r.y + r.height ) ) {
            selected = i;
            *s.value = ofMap( x, r.x, r.x + r.width, s.minV, s.maxV, true );
        }
    }
}

void Interface::mouseDragged( int x, int y ){
    if ( selected >= 0 ) {
        Slider &s = slider[selected];
        ofRectangle r = s.rect;
        *s.value = ofMap( x, r.x, r.x + r.width, s.minV, s.maxV, true );
    }
}

void Interface::mouseReleased (int x, int y ){
    selected = -1;
}

void Interface::save( int index ){
    vector<string> list;
    for (int i=0; i<slider.size(); i++) {
        list.push_back( ofToString( *slider[i].value ) );
    }
    string text = ofJoinString( list," " );
    string fileName = "preset" + ofToString( index ) + ".txt";
    ofBuffer buffer = ofBuffer( text );
    ofBufferToFile( fileName, buffer );
}

void Interface::load( int index ){
    string fileName = "preset" + ofToString( index ) + ".txt";
    string text = string( ofBufferFromFile( fileName ) );
    vector<string> list = ofSplitString( text, " " );
    
    if ( list.size() == slider.size() ) {
        for (int i=0; i<slider.size(); i++) {
            *slider[i].value = ofToFloat( list[i] );
        }
    }
}