#include "Pixel.hpp"



Pixel::Pixel(){} //default constructor

Pixel::Pixel(int s, int x, int y, int z, ofColor c, int zLow, int zHigh){
    size = s;
    
    pColor = c;
    brightness = pColor.getBrightness();
    saturation = pColor.getSaturation();
    
    xPos = x;
    yPos = y;
    zPos = ofMap(brightness, zHigh, zLow, -50, 50);
    
    res = ofMap(saturation, zLow, zHigh, 3, 10);
}

//make a deconstructor
Pixel::~Pixel(){
}

void Pixel::update(){
    colorNum += outlineIncrement;
    if(colorNum < 50 || colorNum > 200){
        outlineIncrement*=-1;
    }

    res+=0.1;
    deg+=5;
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
    
    ofSetCircleResolution(ofWrap(res, 3, 10));
    
    ofDrawCircle(0, 0, zPos, size);
    
    ofNoFill();
    ofSetColor(colorNum, 50);
    ofDrawCircle(0, 0, zPos, size);
    
    ofPopMatrix();
    
}


