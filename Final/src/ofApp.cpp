#include "ofApp.h"

float bkgIncrement = 0.5;
float colorNum = 50;
int z = 0;

//Sets up the window width and height, webcam, opacity settings, and GUI
void ofApp::setup(){
    ofBackground(50);
    ofSetWindowShape(camWidth, camHeight);
    ofSetFrameRate(24);

    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(24);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    ofEnableAlphaBlending();
    
    gui.setup("Shape 1");
    gui.setPosition(0, 0);
    gui.add(sizeSlider.set("Shape Size", 2, 2, 10));

}

//Updates the Color of the background to go from black and white,
//automatically updates the shapes based on webcam photo,
//updates position of shapes with Pixel's update function
void ofApp::update(){
    colorNum += bkgIncrement;
    if(colorNum < 50 || colorNum > 100){
        bkgIncrement*=-1;
    }
    
    vidGrabber.update();
    
    if((int)ofGetElapsedTimef() % 65 == 0){
        camPixels = vidGrabber.getPixels();
        createPixels();
    }
    
    for(int i = 0; i < pixels.size(); ++i){
        pixels[i]->update();
    }
}

//Draws the background, draws the pixel shapes, draws GUI if drawGui is true
void ofApp::draw(){
    ofBackground(colorNum);
    
    for(int i = 0; i < pixels.size(); ++i){
        pixels[i]->draw();
    }
    
    if (drawGui) {
        gui.draw();
    }
}

//'X' key toggles the GUI, Spacebar allows manual update of camera
void ofApp::keyPressed(int key){
    if (key == 'x') {
        drawGui = !drawGui;
    }
    
    if(key == ' '){
        camPixels = vidGrabber.getPixels();
        createPixels();
    }
}

//clears the previous pixels array,
//resets the lowest and highest Z positions
//Goes through a 2 dimensional for-loop to create pixels at the right coords based on webcam footage
void ofApp::createPixels(){
    pixels.clear();
    
    setZValue();
    for (int x=0; x<camWidth; x+=(sizeSlider*4)) {
        for (int y=0; y<camHeight; y+=(sizeSlider*4)) {
            ofColor pColor = camPixels.getColor(x, y);
            pixels.push_back(new Pixel(sizeSlider, x, y, z, pColor, zLow, zHigh));
        }
    }
}

//Finds the lowest and highest brightness in the photo and sets that as the lowest and highest Z positions
void ofApp::setZValue(){
    for (int x=0; x<ofGetWindowWidth(); x+=sizeSlider) {
        for (int y=0; y<ofGetWindowHeight(); y+=sizeSlider) {
            ofColor pColor = camPixels.getColor(x, y);
            float brightness = pColor.getBrightness();
            if(brightness < zLow){
                zLow = brightness;
            }
            if(brightness > zHigh){
                zHigh = brightness;
            }
        }
    }
}
