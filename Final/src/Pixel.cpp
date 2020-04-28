#include "Pixel.hpp"

Pixel::Pixel(){} //default constructor

Pixel::Pixel(int x, int y, int z, float b, ofColor c, int zLow, int zHigh){
    xPos = x;
    yPos = y;
    zPos = z;
    brightness = b;
    pColor = c;
    res = ofMap(brightness, zLow, zHigh, 4, 20);
}

void Pixel::setup(int x, int y, int z, float b, ofColor c, int zLow, int zHigh){
    xPos = x;
    yPos = y;
    zPos = z;
    brightness = b;
    pColor = c;
    res = ofMap(brightness, zLow, zHigh, 4, 20);
}

void Pixel::update(){
    ++res;
//    res = ofWrap(res, 4, 20);
    ofSetSphereResolution(ofWrap(res, 4, 20));
}

void Pixel::draw(){
//    float brightness = pColor.getBrightness();
    ofNoFill();
    ofSetColor(pColor);
    
    ofPushMatrix();
//    ofRotateDeg(ofWrap(++deg, 0, 360));
    ofDrawSphere(xPos, yPos, zPos, size);
    
    ofPopMatrix();
}
