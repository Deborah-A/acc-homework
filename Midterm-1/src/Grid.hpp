#pragma once

#include "ofMain.h"

class Grid{
public:
    Grid();
    Grid(int sides, int size, int windowWidth, int windowHeight);
    
    //functions
    void drawPolygon();
    void drawGrid();
    
    //variables
private:
    int mySides;
    int mySize;
    int width;
    int height;
    
};

