#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofSetFrameRate(12);
    ofBackground(0);
    
    myServer.setName("OF Server");
    
    Grid grid(6, 60, 1920, 1080);
    Grid grid2(6, 60, 1920, 1920);
    ofSetColor(255);
    
    fbo.allocate(1920, 1920, GL_RGBA);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    }

//--------------------------------------------------------------
void ofApp::update(){
   fbo.begin();
      grid2.drawGrid();
   fbo.end();
    fbo.setAnchorPoint(fbo.getWidth()/2, fbo.getHeight()/2);

}

//--------------------------------------------------------------
void ofApp::draw(){
    grid.drawGrid();
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofRotateDeg(ofGetFrameNum());
    fbo.draw(0,0);
    
    ofPopMatrix();
    
    myServer.publishScreen();
}

