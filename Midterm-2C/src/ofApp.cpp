#include "ofApp.h"

int size=50;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofBackground(200, 200, 200); //for scenario 1
//    ofBackground(25, 25, 25); //for scenario 2
//    ofBackground(?, ?, ?);    //for scenario 3
    ofSetFrameRate(10);
    
//    ofSetBackgroundAuto(false); //for scenario 2
    triangle.setup(3, 100, 1280/2, 720/2, 2, 0);
    square.setup(4, 200,  1280/2, 720/2, 4, 0);
    pentagon.setup(5, 300,  1280/2, 720/2, 6, 0);
    hexagon.setup(6, 400, 1280/2, 720/2, 8, 0);
    
    myServer.setName("OF Server");
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
    triangle.update(true);
    square.update(false);
    pentagon.update(true);
    hexagon.update(true);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 0, 50);
    triangle.createPoly(ofGetFrameNum());
    
    ofSetColor(255, 255, 0, 50);
    square.createPoly(ofGetFrameNum());
    
    ofSetColor(0, 255, 0, 50);
    pentagon.createPoly(ofGetFrameNum());
    
    ofSetColor(0, 0, 255, 50);
    hexagon.createPoly(ofGetFrameNum());
    
    myServer.publishScreen();
}
