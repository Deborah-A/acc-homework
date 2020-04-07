#include "ofApp.h"

vector<int> y;
vector<int> x;
vector<int> amp;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofBackground(0);
    //    ofSetFrameRate(30);
    ofSetBackgroundAuto(false);
        
    for(int i = 0; i < 10; ++i){
        y.push_back(ofRandom(100, ofGetWindowHeight()-100));
        x.push_back(-(ofRandom(300)));
        amp.push_back(ofRandom(50));
    }
    myServer.setName("OF Server");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    for(int i = 1; i < ofGetWindowWidth(); i+=spacing)
    for(int i = 0; i <x.size(); ++i){
        if(ofGetElapsedTimef() < 15){
            ofDrawCircle(++(x[i]),y[i],2);
        }else{
            ofDrawCircle(++x[i],(y[i])+(amp[i]*sin(x[i]*.05)),2);
            
        }
    }
    myServer.publishScreen();

}
