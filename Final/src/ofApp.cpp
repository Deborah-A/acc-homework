#include "ofApp.h"

int size = 2;
int camWidth = 1280;
int camHeight = 720;
int zLow = 10000;
int zHigh = -10000;
int z = 0;
int res = 4;
bool run = false;
int resIndex = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100);
    ofSetWindowShape(1280, 720);
    
//    ofEnableLighting();
//    light.setPosition(0, 0, 150);
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
//    for(int i = 0; i < pixels.size(); ++i){
//        pixels[i].update();
//    }
//
//                ++res;
//       ofWrap(res, 4, 20);
    
    
    //updates res for each circle.
    if(run){
//    vidGrabber.update();
    for(int i = 0; i < pixelRes.size(); ++i){
        ofWrap(++pixelRes[i], 4, 20);
    }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    if(run){
//    for(int i = 0; i < pixels.size(); ++i){
//        pixels[i].draw();
//    }
//    }
//    ofEnableDepthTest();
//    light.enable();
//    camera.begin();
    
    
    
    if(run){
    something();
    }
    
    
//    camera.end();
//    light.disable();
//    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c')
    {
                camPixels = vidGrabber.getPixels();
        setRes();
        run = true;

//                something();
        // camtex.loadData(vidGrabber.getPixels())
    }
}

//void ofApp::something(){
//        setZValue();
//    for (int x=0; x<camWidth; x+=(size*4)) {
//        for (int y=0; y<camHeight; y+=(size*4)) {
//            ofColor pColor = camPixels.getColor(x, y);
//            float brightness = pColor.getBrightness();
//            pixels.push_back(Pixel(x, y, z, brightness, pColor, zLow, zHigh));
//        }
//    }
//}

void ofApp::something(){
    setZValue();
    for (int x=0; x<camWidth; x+=(size*4)) {
        for (int y=0; y<camHeight; y+=(size*4)) {

            ofColor pColor = camPixels.getColor(x, y);
            float brightness = pColor.getBrightness();
//                        ofNoFill();
            z = ofMap(brightness, zLow, zHigh, -100, 100);
            ofSetColor(pColor);
//            ++res;
//            ofWrap(res, 4, 20);
//            res = ofMap(brightness, zLow, zHigh, 4, 20);
//            resIndex = pixelRes[x+camWidth*y];
            res = ofWrap(pixelRes[resIndex], 4, 20);
            ofSetCircleResolution(res); //suppose to change (also hopefully the equation works to pull the data since it could be the same size.
            ofDrawCircle(x, y, z, size);
            //            ofDrawRectangle(x, y, size, size);
//            if(resIndex)
            resIndex = ofWrap(resIndex, 0, pixelRes.size());
        }

    }

}

void ofApp::setRes(){
    for (int x=0; x<camWidth; x+=(size*4)) {
    for (int y=0; y<camHeight; y+=(size*4)) {
        ofColor pColor = camPixels.getColor(x, y);
        float brightness = pColor.getBrightness();
        res = ofMap(brightness, zLow, zHigh, 4, 20);
        pixelRes.push_back(res);
    }
    }
}

//void ofApp::createGrid(){
//    for (int x=0; x<camWidth; x+=(size*4)) {
// for (int y=0; y<camHeight; y+=(size*4)) {
//}

void ofApp::setZValue(){
    for (int x=0; x<ofGetWindowWidth(); x+=size) {
        for (int y=0; y<ofGetWindowHeight(); y+=size) {
            ofColor pColor = camPixels.getColor(x, y);
            float brightness = pColor.getBrightness();
            if(brightness < zLow){
                zLow = brightness;
            }
            if(brightness > zHigh){
                zHigh = brightness;
            }
        }
    }
}
