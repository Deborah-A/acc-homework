#pragma once

#include "ofMain.h"

class Pixel {

    public:
    Pixel();
    Pixel(int x, int y, int z, float b, ofColor c, int zLow, int zHigh);
        void setup(int x, int y, int z, float b, ofColor c, int zLow, int zHigh);
        void update();
    void draw();

private:
    int xPos;
    int yPos;
    int zPos;
    int res = 4;
    int size = 3;
    int deg = 0;
    int brightness;
    ofColor pColor;
};
