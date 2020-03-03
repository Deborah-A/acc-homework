#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxPanel backgroundGUI;
        ofParameter<ofColor> bkgColor;
		
        ofxPanel gui;
        ofParameter<float> radiusSlider;
        ofParameter<float> maxLineWidthSlider;
        ofParameter<float> growthRateSlider;
        ofParameter<ofColor> colorChoice;
        ofxButton button;
        ofParameter<bool> toggle;
        ofParameter<int> circleRes;
        ofParameter<string> screenShot;
        ofParameter<glm::vec2> origin;
        ofParameter<float> stepSizeSlider;
        ofParameter<float> phaseShiftSlider;
        ofxIntField multiples;

        ofxPanel gui2;
        ofParameter<float> radiusSlider2;
        ofParameter<float> maxLineWidthSlider2;
        ofParameter<float> growthRateSlider2;
        ofParameter<ofColor> colorChoice2;
        ofxButton button2;
        ofParameter<bool> toggle2;
        ofParameter<int> circleRes2;
        ofParameter<string> screenShot2;
        ofParameter<glm::vec2> origin2;
        ofParameter<float> stepSizeSlider2;
        ofParameter<float> phaseShiftSlider2;
        ofxIntField multiples2;
        
        bool drawGui = true;
};
