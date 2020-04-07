#include "Grid.hpp"

Grid::Grid(){
    mySides = 6;
    mySize = 5;
    width = 1920;
    height = 1080;
}

Grid::Grid(int sides, int size, int windowWidth, int windowHeight){
    mySides = sides;
    mySize = size;
    width = windowWidth;
    height = windowHeight;
}

//triangles, hexagons, squares
void Grid::drawPolygon(){
    ofSetCircleResolution(mySides);
    ofDrawCircle(mySize/2, mySize/2, mySize);
}

void Grid::drawGrid(){
    int y = 0;
    ofSetCircleResolution(mySides);
    for (int i = 0; i < width/mySize; i++) {
        for (int j = 0; j < height/mySize; j++) {
            if(j % 2 == 0){
                ofFill();
            }else{
                ofNoFill();
            }
            ofDrawCircle(3*i*mySize/2,3.5*j*mySize/2 + y, mySize);
        }
        if(i%2 == 0){
            y = -.9*mySize;
        }else{
            y = 0;
        }
    }
}
