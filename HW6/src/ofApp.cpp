#include "ofApp.h"

ofColor red = ofColor(255, 0, 0, 150);
ofColor green = ofColor(0, 255, 0, 150);
ofColor blue = ofColor(0, 0, 255, 150);

//--------------------------------------------------------------
void ofApp::setup(){
    csv.load("Z_Solo_Best.csv");
//    ofSetBackgroundAuto(false);
    ofBackground(220, 220, 220);
    
    
    for (int i = 7; i < csv.getNumRows(); i++) {
        for (int j = 2; j < csv.getNumCols(); j += 3) {
            // very first time, initialize values
            if (i == 7 && j == 2) {
                xMin = ofToFloat(csv[i][j]);
                xMax = ofToFloat(csv[i][j]);
                yMin = ofToFloat(csv[i][j + 1]);
                yMax = ofToFloat(csv[i][j + 1]);
                zMin = ofToFloat(csv[i][j + 2]);
                zMax = ofToFloat(csv[i][j + 2]);
            }
            else {
                if (ofToFloat(csv[i][j]) < xMin) {
                    xMin = ofToFloat(csv[i][j]);
                }
                if (ofToFloat(csv[i][j]) > xMax) {
                    xMax = ofToFloat(csv[i][j]);
                }
                if (ofToFloat(csv[i][j + 1]) < yMin) {
                    yMin = ofToFloat(csv[i][j + 1]);
                }
                if (ofToFloat(csv[i][j]) > yMax) {
                    yMax = ofToFloat(csv[i][j + 1]);
                }
                if (ofToFloat(csv[i][j + 2]) < zMin) {
                    zMin = ofToFloat(csv[i][j + 2]);
                }
                if (ofToFloat(csv[i][j]) > zMax) {
                    zMax = ofToFloat(csv[i][j + 2]);
                }
            }
        }
    }
    
    ofSetFrameRate(30);
  
        for (int j = 2; j < csv.getNumCols(); j += 3) {
            mesh.addVertex(ofVec3f(ofMap(ofToFloat(csv[row][j]), xMin, xMax, 0, ofGetWindowWidth()), ofMap(ofToFloat(csv[row][j + 1]), yMax, yMin, 0, ofGetWindowHeight()),
                                   ofMap(ofToFloat(csv[row][j + 2]), zMax, zMin, 100, -100)));
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //    int numVerts = mesh.getNumVertices();
    //    for (int k=0; k<numVerts; ++k) {
    mesh.clearVertices();
        for (int j = 2; j < csv.getNumCols(); j += 3) {
            mesh.addVertex(ofVec3f(ofMap(ofToFloat(csv[row][j]), xMin, xMax, 0, ofGetWindowWidth()), ofMap(ofToFloat(csv[row][j + 1]), yMax, yMin, 0, ofGetWindowHeight()),
                                   ofMap(ofToFloat(csv[row][j + 2]), zMax, zMin, 100, -100)));
        }
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(50, 50, 50);
    ofDrawRectangle(0, ofGetWindowHeight()-500, ofGetWindowWidth(), ofGetWindowHeight());
    ofSetColor(red);
    mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    mesh.draw();
    
    ofPushMatrix();
    ofTranslate(-200, -200, -200);
    ofSetColor(green);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(-400, -400, -400);
    ofSetColor(blue);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY);
    mesh.draw();
    ofPopMatrix();
    
    ++row;
}

