#pragma once

#include "ofMain.h"
#include "Poly.hpp"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        
    ofxSyphonServer myServer;
    
    Poly hexagon;
    Poly triangle;
    Poly pentagon;
    Poly square;
    Poly square2;
    Poly hexagon2;
    
    
    ofMesh mesh;
};
