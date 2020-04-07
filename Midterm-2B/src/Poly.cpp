#include "Poly.hpp"

int vSize =1;

Poly::Poly(){
    sides = 6;
    size = 10;
    x = 0;
    y = 0;
    rotation = 1;
}


void Poly::setup(int polySides, int polySize, int initialX, int initialY, int rotationSpeed, int polySpeed){
    sides = polySides;
    size = polySize;
    x = initialX;
    y = initialY;
    rotation = rotationSpeed;
    speed = polySpeed;
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
