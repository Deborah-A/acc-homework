#include "Pixel.hpp"

Pixel::Pixel(){} //default constructor

Pixel::Pixel(int s, int x, int y, int z, ofColor c, int zLow, int zHigh){
    size = s;
    
    pColor = c;
    brightness = pColor.getBrightness();
    saturation = pColor.getSaturation();
    
    xPos = x;
    yPos = y;
    zPos = ofMap(brightness, zHigh, zLow, -100, 100);
    //    zPos = z;
    
    //    brightness = b;
    
    
    res = ofMap(saturation, zLow, zHigh, 4, 20);
}

//make a deconstructor
Pixel::~Pixel(){
}

void Pixel::update(){
    //    res = timePassed;
    res+=0.1;
    //    cout << res << endl;
    deg+=5;
    
    
    //    res = ofWrap(res, 4, 20);
    //    ofSetSphereResolution(ofWrap(res, 4, 20));
}

void Pixel::draw(){
    ofFill();
    //    ofNoFill();
    ofSetColor(pColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    
    ofRotateXDeg(deg);
    ofRotateYDeg(deg);
    ofRotateZDeg(deg);
    ofSetSphereResolution(ofWrap(res, 4, 15));
    ofSetCircleResolution(ofWrap(res, 4, 15));
    
    ofDrawCircle(0, 0, zPos, size);
    
    ofPopMatrix();
    
}


