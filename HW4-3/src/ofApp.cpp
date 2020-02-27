#include "ofApp.h"

int pic_width = 1344;
int pic_height = 1008;

//--------------------------------------------------------------
void ofApp::setup(){
    pic.load("image.JPG");
    ofSetWindowShape(pic_width, pic_height);
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50, 50, 50);
    pointilize(20);

}

void ofApp::pointilize(int size){
    for (int x=0; x<pic_width; x+=(size/2)) {
        for (int y=0; y<pic_height; y+=(size/2)) {
            
            picpixels = pic.getPixels();
            ofColor pColor = picpixels.getColor(x, y);
            ofFill();
            ofSetColor(pColor, pColor.getBrightness());
            
            ofDrawCircle(x,y,pColor.getSaturation()/size);
            
        }
    }
}
