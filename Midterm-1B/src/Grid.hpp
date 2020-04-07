#pragma once

#include "ofMain.h"
#include "ofxSandLine.h"

class Grid{
public:
    Grid();
    Grid(int size, int windowWidth, int windowHeight);
    
    //functions
    void drawPolygon();
    void drawGrid();
    void drawGrid2();
    
    //variables
    ofFbo fbo;
private:
    int mySides;
    int mySize;
    int width;
    int height;
    
    
    vector<ofxSandTriangle> triangles;
};

