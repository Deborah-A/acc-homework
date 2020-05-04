#include "ofApp.h"

int size = 4;
int camWidth = 1280;
int camHeight = 720;
int zLow = 10000;
int zHigh = -10000;
int z = 0;
int res = 4;
bool run = false;
int resIndex = 0;
int timePassed = 1;
//ofColor pColor = ;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100);
    ofSetWindowShape(camWidth, camHeight);
    ofSetFrameRate(24);
    
    //    ofEnableLighting();
    //    light.setPosition(0, 0, 150);
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(24);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if((int)ofGetElapsedTimef() % 60 == 0){
        camPixels = vidGrabber.getPixels();
        something();
        
        
    }
    
    cout << ((int)ofGetElapsedTimef() % 240) << endl;
    for(int i = 0; i < pixels.size(); ++i){
        pixels[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < pixels.size(); ++i){
        pixels[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ')
    {
        camPixels = vidGrabber.getPixels();
        //        setZValue();
        something();
        run = true;
    }
}

void ofApp::something(){
    //how do i clear the array pixels
    pixels.clear();
    
    setZValue();
    for (int x=0; x<camWidth; x+=(size*4)) {
        for (int y=0; y<camHeight; y+=(size*4)) {
            ofColor pColor = camPixels.getColor(x, y);
            float brightness = pColor.getBrightness();
            //            pColor.setSaturation(180);
            pixels.push_back(new Pixel(size, x, y, z, pColor, zLow, zHigh));
            
            if((camWidth/2)==x && (camHeight/2)==y ){
                if(brightness > 125){
                    ofSetBackgroundColor(100, 100, 100);
                }else{
                    ofSetBackgroundColor(200, 200, 200);
                }
            }
        }
    }
}

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
