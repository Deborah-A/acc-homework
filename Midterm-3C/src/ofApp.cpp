#include "ofApp.h"

int startX ;
int startY ;
vector<int> signX;
vector<int> signY;
vector<int> x;
vector<int> y;

//vector<int> speedX;
//vector<int> speedY;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofBackground(0);
//        ofSetFrameRate(30);
    ofSetBackgroundAuto(false);
    
    startX= 0;
    startY = 0;
    
    for(int i = 0; i < 20; ++i){
        
//        speedY.push_back(i);
        x.push_back(startX);
        y.push_back(startY+(64*i));
        signX.push_back(1);
        signY.push_back(1);
    }
    myServer.setName("OF Server");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i <20; ++i){
            ofDrawCircle(x[i],y[i],3);
        x[i] += i*signX[i];
        y[i] += i*signY[i];
        if(y[i] > ofGetWindowHeight()){
            signY[i] =-1;
        }
        if(y[i] < 0){
            signY[i] *=-1;
        }
        if(x[i] > ofGetWindowWidth()){
            signX[i] *=-1;
        }
        if(x[i] < 0){
            signX[i] *=-1;
        }
        }
    myServer.publishScreen();
    }

