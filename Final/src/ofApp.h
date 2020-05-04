#pragma once

#include "ofMain.h"
#include "Pixel.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
        void something();
        void setZValue();
//    void setRes();
    
        ofVideoGrabber vidGrabber;
        ofPixels camPixels;
        ofLight light;
        ofEasyCam camera;
        vector <Pixel*> pixels;
    vector <int> pixelRes;
        
		
};
