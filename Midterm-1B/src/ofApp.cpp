#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    ofBackground(0);
    ofSetFrameRate(60);
    Grid grid(25, ofGetWindowWidth(), ofGetWindowHeight());
    Grid grid2(25, 700, 700);
    ofSetColor(255);

    myServer.setName("OF Server");


    
}

//--------------------------------------------------------------
void ofApp::update(){
    grid.drawPolygon();
    grid2.drawPolygon();
        
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    grid.drawGrid();
    
    ofPushMatrix();
    
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofRotateDeg(ofGetFrameNum());
    grid2.drawGrid();

    ofPopMatrix();
    
    myServer.publishScreen();
}




