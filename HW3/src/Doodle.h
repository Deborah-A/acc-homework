#pragma once
#include "../../../libs/openFrameworks/app/ofBaseApp.h"
#include "ofMain.h"

class Doodle :
    public ofBaseApp
{

public:
    Doodle();
    Doodle(int size, int rotation);
    ~Doodle();
    void draw();
    
    int x;
    int y;

    ofImage pic;
    int rotationValue;
};
