#pragma once

#include "ofMain.h"
#include "Grid.hpp"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
     ofxSyphonServer myServer;
    
    Grid grid;
    Grid grid2;

};
