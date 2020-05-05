#pragma once

#include "ofMain.h"
#include "Pixel.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void createPixels();
    void setZValue();
    
    ofVideoGrabber vidGrabber;
    ofPixels camPixels;
    ofEasyCam camera;
    vector <Pixel*> pixels;;
    
    ofxPanel gui;
    ofParameter<float> sizeSlider;
    
    int camWidth = 1280;
    int camHeight = 720;
    int zLow = 10000;
    int zHigh = -10000;
    bool drawGui = false;
};
