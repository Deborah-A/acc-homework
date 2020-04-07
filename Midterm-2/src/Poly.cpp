#include "Poly.hpp"

//int lineX1;
//int lineX2;
//int lineY1;
//int lineY2;
int vSize =1;

//int numLines = 1;
//vector<ofVec3f> prevVertices;

Poly::Poly(){
    sides = 6;
    size = 10;
    x = 0;
    y = 0;
    rotation = 1;
}

//Poly::Poly(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed){
//    sides = polySides;
//    size = polySize;
//    x = initialX;
//    y = initialY;
//    position = ofVec2f(x, y);
//    rotation = rotationSpeed;
//    speed = polySpeed;
////    ofVec3f startPoint(x, y, 0);
////    prevVertices.push_back(startPoint);
//}

void Poly::setup(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed){
    sides = polySides;
    size = polySize;
    x = initialX;
    y = initialY;
    rotation = rotationSpeed;
    speed = polySpeed;
//    ofVec3f startPoint(x, y, 0);
//    prevVertices.push_back(startPoint);
}


void Poly::update(bool type){
    if(x > 1280 || y > 720){
        speed*=-1;
    }else if(x<0 || y<0){
        speed*=-1;
    }
    if(type){
    x += (speed);
    }else {
    y += (speed);
    }
    
}

//call in draw
void Poly::createPoly(int frameCount){
    if(sides == 6){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotateDeg(frameCount * rotation);
        
        ofPushMatrix();
        ofRotateDeg(60);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(120);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(180);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(240);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(300);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(360);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();

        ofPopMatrix();
    }else if(sides == 5){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotateDeg(frameCount * rotation);
        
        ofPushMatrix();
        ofRotateDeg(72);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(144);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(216);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(288);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(360);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        
        ofPopMatrix();
    }else if(sides == 4){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotateDeg(frameCount * rotation);
        
        ofPushMatrix();
        ofRotateDeg(90);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(180);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(270);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(360);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        
        ofPopMatrix();
    }else if(sides == 3){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotateDeg(frameCount * rotation);
        
        ofPushMatrix();
        ofRotateDeg(120);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(240);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        ofPushMatrix();
        ofRotateDeg(360);
        ofDrawCircle(0, size, vSize);
        ofPopMatrix();
        
        ofPopMatrix();
    }
    
}






//void Poly::sandLineTrailSetup(){
//
//    for(int i = 0; i<numLines; ++i){
//        float spacing = size/float(numLines);
//
//        auto start = prevVertices[i];
//        auto end = mesh.getVertices()[i];
//
//        ofxSandLine line;
//        line = ofxSandLine(start, end);
//        line.setMode(SAND_MODE_SPLINE);
//        line.setOffset(4, 2, 2, 4);
//
//        lines.push_back(line);
//
//    }
//}
//
//void Poly::sandLineTrail(){
//
//    for(int i = 0; i < lines.size() - 1; i++){
//
//        //getPoints returns all the points of that line
//        auto myPoints = lines[i].getPoints();
//
//        //get the points of the next line
//        auto nextPoints = lines[i+1].getPoints();
//
//        //We're setting the first point of the next line as the average between the current lines
//        //last point and the next lines first point
//
//        auto average = (myPoints[3] + nextPoints[0])/2.0;
//
//        lines[i+1].setPoint(1, average);
//    }
//
//}

