#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    x =0;
    y= 500;
    ofSetCircleResolution(100); //non ugly circles
}

//--------------------------------------------------------------
void ofApp::update(){
    //post incrementing -less effcient (post makes a copy of the variable then
    //x++;
    //pre incrementing -more efficient (pre doesnt need to make a copy)
    ++x;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawCircle(x,y,100);
}

