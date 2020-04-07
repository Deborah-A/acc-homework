#include "ofApp.h"

int size=50;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
//    ofBackground(200, 200, 200); //for scenario 1
    ofBackground(25, 25, 25); //for scenario 2
//    ofBackground(?, ?, ?);    //for scenario 3
    ofSetFrameRate(10);
    
    ofSetBackgroundAuto(false); //for scenario 2
    hexagon.setup(6, 50, 100, 100, 2, 6);
    triangle.setup(3, 100, 1000, 460, 5, -5);
    pentagon.setup(5, 200, 500, 300, 7, 3);
    square.setup(4, 30, -100, 250, 3, 2);
    square2.setup(4, 120, 400, 654, 1, 4);
    hexagon2.setup(6, 170, 800, ofRandom(ofGetWindowHeight()), 10, -4);
     myServer.setName("OF Server");
}

//--------------------------------------------------------------
void ofApp::update(){
    hexagon.update(true);
    hexagon2.update(false);
    pentagon.update(true);
    square.update(false);
    square2.update(true);
    triangle.update(true);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    hexagon.createPoly(ofGetFrameNum());
    triangle.createPoly(ofGetFrameNum());
    pentagon.createPoly(ofGetFrameNum());
    hexagon2.createPoly(ofGetFrameNum());
    square2.createPoly(ofGetFrameNum());
    square.createPoly(ofGetFrameNum());
    myServer.publishScreen();
}
