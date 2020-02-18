#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1000, 1000);
    ofSetFrameRate(30);
    w = ofGetWindowWidth();
    pic.load("image.png");

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

        ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * 30);
        pic.draw(0, 0, 1000, 1000);
    ofPopMatrix();

    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * 25);
        pic.drawSubsection(20, 0, 800, 800, 100, 100, 800, 800);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * 20);
        pic.drawSubsection(20, 0, 600, 600, 200, 200, 600, 600);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * 15);
        pic.drawSubsection(20, 00, 400, 400, 300, 300, 400, 400);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * 10);
        pic.drawSubsection(20, 0, 200, 200, 400, 400, 200, 200);
    ofPopMatrix();
    
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
