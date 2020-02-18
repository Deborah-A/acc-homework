#include "Doodle.h"

Doodle::Doodle()
{
    pic.load("image.png");
    x = 0;
    y = 0;
    rotationValue = 0;
}

float picSize;

Doodle::Doodle(int size, int rotation)
{
    pic.load("image.png");
//    pic.crop(size/2, size/2, size, size);
    rotationValue = rotation;
    picSize = size;
}

void Doodle::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
        ofTranslate(500, 500);
        ofRotateZ(ofGetElapsedTimef() * rotationValue);
        pic.draw(0, 0, picSize, picSize);
    ofPopMatrix();
}


Doodle::~Doodle()
{
}
