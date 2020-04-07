#pragma once

#include "ofMain.h"
#include "ofxSandLine.h"

class Poly{
public:
    Poly();
//    Poly(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed);
    void setup(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed); //might need more parameters
    
    //functions
    void createPoly(int frameCount);
//    void drawPoly(int frameCount, int type);
//    void sandLineTrailSetup();
//    void sandLineTrail();
    //    *void getPreviousVertex(int frameCount);
    void update(bool type);
    
    //variables
private:
    int sides;
    int size;
    int x;
    int y;
    int rotation;
    int speed;
    ofVec2f position;
    
    ofxSandTriangle triangle1;
    ofxSandTriangle triangle2;
    ofxSandTriangle triangle3;
    ofxSandTriangle triangle4;
    ofxSandTriangle triangle5;
    ofxSandTriangle triangle6;
    
};
