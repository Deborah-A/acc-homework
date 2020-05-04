#pragma once

#include "ofMain.h"

class Pixel {

    public:
    Pixel();
    Pixel(int size, int x, int y, int z, ofColor c, int zLow, int zHigh);
    ~Pixel();
    void update();
    void draw();

private:
    int xPos;
    int yPos;
    int zPos;
    float res = 4;
    int size = 5;
    int deg = 0;
    int brightness;
    ofColor pColor;
    int camWidth = 1280;
    int camHeight = 720;
    int saturation = 0;
};
