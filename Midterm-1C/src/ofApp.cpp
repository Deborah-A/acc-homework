#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofBackground(255, 255, 0);
    ofSetFrameRate(12);
    Grid grid(60, 1920, 1080);
    Grid grid2(60, 1920, 1920);
//    ofSetColor(255);
    fbo.allocate(1920, 1920, GL_RGBA);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    myServer.setName("OF Server");
    }

//--------------------------------------------------------------
void ofApp::update(){
   fbo.begin();
    ofSetColor(255, 0, 0, 150);
      grid2.drawGrid();
   fbo.end();
    fbo.setAnchorPoint(fbo.getWidth()/2, fbo.getHeight()/2);

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
//    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(0, 0, 255, 150);
    grid.drawGrid();
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofRotateZ(ofGetFrameNum());
    ofSetColor(255, 0, 0, 150);
    fbo.draw(0,0);

    myServer.publishScreen();
    
    ofPopMatrix();
//    ofPopMatrix();
}

