#pragma once

#include "ofMain.h"

class Poly{
public:
    Poly();
    void setup(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed); //might need more parameters
    
    //functions
    void createPoly(int frameCount);
    void update(bool type);
    
    //variables
private:
    int sides;
    int size;
    int x;
    int y;
    int rotation;
    int speed;
 
    
};
