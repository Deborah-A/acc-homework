#include "ofApp.h"

int pic_width = 720;
int pic_height = 960;

//--------------------------------------------------------------
void ofApp::setup(){
    pic.load("image.JPG");
    ofSetWindowShape(pic_width, pic_height);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(25, 25, 25);
    pixelate(10);
}

void ofApp::pixelate(int size){
    for (int x=0; x<pic_width; x+=size) {
        for (int y=0; y<pic_height; y+=size) {
            picpixels = pic.getPixels();
            ofColor pColor = picpixels.getColor(x, y);
            ofNoFill();
            ofSetColor(pColor);
            
            ofDrawRectangle(x, y, size, size);
        }
    }
}
