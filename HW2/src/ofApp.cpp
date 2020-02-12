#include "ofApp.h"

int x1 = 10;
int yVal1 = 250; //y1 was already used but I couldn't find it
int x2 = 10;
int y2 = 15;
int gap[50];
int topY[50];
int alpha[50];

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    ofSetFrameRate(30);
    
    ofBackground(ofRandom(150),ofRandom(150),ofRandom(150), 50);

    ofSetLineWidth(5);
    ofEnableAlphaBlending();
    
    for(int i =0; i<50;i++){
        gap[i] = ofRandom(100);
    }
    for(int i =0; i<50;i++){
        topY[i] = yVal1 +(5* ofRandom(10));
    }
    for(int i =0; i<50;i++){
        alpha[i] = ofRandom(255);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<50;i++){
        ofSetColor(255, alpha[i]);
        ofLine(x1 * i, 0, x2*i, topY[i] - gap[i]);
        ofLine(x1 * i, topY[i] + gap[i], x2*i, 500);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
