#include "ofApp.h"

ofImage img;

float a = 0;
float a2 = 0;
float stepSize; //from 25 to 250
float stepSize2;
float time1 = 0;
float time2 = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetWindowShape(1920, 1080);
    
    // setting up our panel
    gui.setup("Shape 1");
    gui.setPosition(0, 0);
    gui.add(radiusSlider.set("Radius", 100, 12, ofGetWidth() / 10));
    gui.add(maxLineWidthSlider.set("Line Width", 5, 1, 10));
    gui.add(stepSizeSlider.set("Frequency", 10, 25, 250));
    gui.add(phaseShiftSlider.set("Phase Shift", 2.5, 0, 10));
    gui.add(growthRateSlider.set("Growth Rate", 0.001, 0.001, 0.01));
    gui.add(colorChoice.set("Color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
    gui.add(toggle.set("Now you see it", false));
    gui.add(circleRes.set("Circle Res", 10, 2, 50));
    gui.add(multiples.setup("Multiples", 50, 1, 100));
    gui.add(origin.set("Origin", ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    
    
    gui2.setup("Shape 2");
    gui2.setPosition(gui.getWidth()*1.1, 0);
    // 1st parameter - name
    // 2nd parameter - default value
    // 3rd parameter  - min value
    // 4th parameter - max value
    gui2.add(radiusSlider2.set("Radius", 100, 12, ofGetWidth() / 10));
    gui2.add(maxLineWidthSlider2.set("Line Width", 5, 1, 10));
    gui2.add(stepSizeSlider2.set("Frequency", 10, 25, 250));
    gui2.add(phaseShiftSlider2.set("Phase Shift", 2.5, 0, 10));
    gui2.add(growthRateSlider2.set("Growth Rate", 0.001, 0.001, 0.01));
    gui2.add(colorChoice2.set("Color", ofColor(0, 0, 255), ofColor(0), ofColor(255)));
    gui2.add(toggle2.set("Now you see it", false));
    gui2.add(circleRes2.set("Circle Res", 100, 2, 50));
    gui2.add(multiples2.setup("Multiples", 50, 1, 100));
    gui2.add(origin2.set("Origin", ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    
    backgroundGUI.setup("System");
    backgroundGUI.setPosition(ofGetWidth() - backgroundGUI.getWidth(), 0);
    backgroundGUI.add(bkgColor.set("Background Color", ofColor(255, 255, 255), ofColor(0), ofColor(255)));
    backgroundGUI.add(screenShot.set("Screenshot"));

}

//--------------------------------------------------------------
void ofApp::update(){
    stepSize = PI / stepSizeSlider;
    stepSize2 = PI / stepSizeSlider2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetBackgroundColor(bkgColor);
    
    if (toggle) {
        
        for(int i =0; i < multiples; i++){
            ofSetColor(colorChoice);
            ofSetCircleResolution(circleRes);
            ofSetLineWidth(maxLineWidthSlider *  sin(a+(i*phaseShiftSlider)));
            ofDrawCircle(origin->x, origin->y, radiusSlider*(time1/multiples)*(i*2));
        }
        
        time1+= growthRateSlider;
        a += stepSize;
        
    }
    
    if(toggle2){
        for(int j=0; j < multiples2; j++){
            ofSetColor(colorChoice2);
            ofSetCircleResolution(circleRes2);
            ofSetLineWidth(maxLineWidthSlider2 *  sin(a2+(j*phaseShiftSlider2)));
            ofDrawCircle(origin2->x, origin2->y, (radiusSlider2*time2/multiples2)*(j*2));
            
        }
        time2+=growthRateSlider2;
        a2 += stepSize;
    }
    
    if (drawGui) {
        gui.draw();
        gui2.draw();
        backgroundGUI.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x') {
        drawGui = !drawGui;
    }
    else if (key == 's') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(screenShot.toString() + ".png");
    }
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
