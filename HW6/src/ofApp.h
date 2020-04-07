#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofxCsv csv;

    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float zMin;
    float zMax;
    
    ofMesh mesh;
    
    int row = 7;
		
};
