#include "Grid.hpp"

Grid::Grid(){
    mySize = 60;
    width = 1920;
    height = 1920;
    ofSetColor(255, 0, 0);
//    ofSetColor(r, g, b, 50);
}

Grid::Grid(int size, int windowWidth, int windowHeight){
    mySize = size;
    width = windowWidth;
    height = windowHeight;
    ofSetColor(255, 0, 0);
//    ofSetColor(r, g, b, 50);
    
}

//triangles, hexagons, squares


void Grid::drawGrid(){
    
    int y = 0;
//    ofSetCircleResolution(mySides);
    for (int i = 0; i < 2*width/mySize; i++) {
        for (int j = 0; j < 2*height/mySize; j++) {
            if(j % 2 == 0 && i%2 == 0){
                ofFill();
            }else if(j%2 == 1 && i%2==1){
                ofFill();
            }
                else{
                ofNoFill();
            }
            ofPushMatrix();
//            ofRotateDeg(45);
            ofDrawRectangle(i*mySize,j*mySize, mySize, mySize);
            ofPopMatrix();
        }
        if(i%2 == 0){
            y = -.9*mySize;
        }else{
            y = 0;
        }
    }
}
