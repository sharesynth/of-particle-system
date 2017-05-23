//
//  Interface.hpp
//  ParticleSystem
//
//  Created by Jeremy Sykes on 2017-05-22.
//
//

#ifndef Interface_hpp
#define Interface_hpp

#include "ofMain.h"
#include "Slider.hpp"

class Interface {
public:
    void setup();
    void addSlider( string title, float *value, float minV, float maxV );
    void draw();
    void save( int index ); // Save preset
    void load( int index ); // Load preset
    void mousePressed( int x, int y );
    void mouseDragged( int x, int y );
    void mouseReleased (int x, int y );
    vector<Slider> slider; // Array of sliders
    int selected; // Index of selected slider
};

#endif /* Interface_hpp */
