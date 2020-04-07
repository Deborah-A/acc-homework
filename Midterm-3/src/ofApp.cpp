#include "ofApp.h"

int x1 ;
int x2 ;
int x3 ;
int x4 ;
int x5 ;
int y ;
int y2 ;
int y3 ;
int y4 ;
int y5 ;

int spacing;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofBackground(0);
    ofSetFrameRate(30);
    ofSetBackgroundAuto(false);
    
    spacing = ofGetWindowWidth()/100;
    
     x1 = ofRandom(100, ofGetWindowWidth()-100);
     x2 = ofRandom(100, ofGetWindowWidth()-100);
     x3 = ofRandom(100, ofGetWindowWidth()-100);
     x4 = ofRandom(100, ofGetWindowWidth()-100);
     x5 = ofRandom(100, ofGetWindowWidth()-100);
     y = -(ofRandom(200));
     y2 = 740;
     y3 = -(ofRandom(200));
     y4 = 850;
     y5 = -(ofRandom(200));
    
    myServer.setName("OF Server");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    for(int i = 1; i < ofGetWindowWidth(); i+=spacing)
    
    if(y > 500){
//    ofDrawCircle(x1 + ofGetFrameNum(), y, 50);
        ofDrawCircle(++x1, y, 30);
        ofDrawCircle(--x2, y2, 30);
        ofDrawCircle(++x3, y3, 30);
        ofDrawCircle(--x4, y4, 30);
        ofDrawCircle(++x5, y5, 30);
    }else{
        
        ofDrawCircle(x1, ++y, 30);
        ofDrawCircle(x2, --y2, 30);
        ofDrawCircle(x3, ++y3, 30);
        ofDrawCircle(x4, --y4, 30);
        ofDrawCircle(x5, ++y5, 30);
//        ++y;
    }
    myServer.publishScreen();

}

float val(){
    float num = ofRandom(0, 1);
    if(num < .5){
        num = -1;
    } else{
        num = 1;
    }
    return num;
}
