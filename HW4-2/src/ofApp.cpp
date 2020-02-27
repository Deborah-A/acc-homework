#include "ofApp.h"

int pic_width = 1344;
int pic_height = 1008;


//--------------------------------------------------------------
void ofApp::setup(){
    pic.load("image.JPG");
    ofSetFrameRate(30);
    ofSetWindowShape(pic_width, pic_height);
    picpixels = pic.getPixels();
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    CRTify(10);
}

void ofApp::CRTify(int size){
    int offset = 0;
    for (int x=0; x<pic_width; x+=size+1) {
        for (int y=offset; y<pic_height; y+=size+1) {

            ofColor pColor = picpixels.getColor(x, y);
            
            ofFill();
            ofSetColor(pColor.r, 0, 0);
            ofDrawCircle(x + (size/2), y +(0.25 * size), size/4.5);

            ofFill();
            ofSetColor(0,pColor.g, 0);
            ofDrawCircle(x + (size/5), y +(0.875 * size), size/4.5);

            ofFill();
            ofSetColor(0,0,pColor.b);
            ofDrawCircle(x + (4*(size/5)), y + (.875 * size), size/4.5);

        }
        if(x%2==1){
            offset = size/2;
        }else{
            offset = 0;
        }
        
    }
}

//horizontal slits instead of circles
//void ofApp::CRTify(int size){
//    int offset = 0;
//    for (int x=0; x<pic_width; x+=size+1) {
//        for (int y=offset; y<pic_height; y+=size+1) {
//
//            ofColor pColor = picpixels.getColor(x, y);
//
//            ofFill();
//            ofSetColor(pColor.r, 0, 0);
//            ofDrawRectangle(x, y, size/3, size);
//            ofNoFill();
//            ofSetColor(0);
//            ofDrawRectangle(x, y, size/3, size);
//
//            ofFill();
//            ofSetColor(0,pColor.g, 0);
//            ofDrawRectangle(x + (size/3), y, size/3, size);
//            ofNoFill();
//            ofSetColor(0);
//            ofDrawRectangle(x + (size/3), y, size/3, size);
//
//            ofFill();
//            ofSetColor(0,0,pColor.b);
//            ofDrawRectangle(x + (2*(size/3)), y, size/3, size);
//            ofNoFill();
//            ofSetColor(0);
//            ofDrawRectangle(x + (2*(size/3)), y, size/3, size);
//
//        }
//        if(x%2==1){
//            offset = size/2;
//        }else{
//            offset = 0;
//        }
//
//    }
//}
