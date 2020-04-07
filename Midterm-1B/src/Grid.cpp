#include "Grid.hpp"

Grid::Grid(){
    mySize = 100;
    width = 1280;
    height = 720;
}

Grid::Grid(int size, int windowWidth, int windowHeight){
    mySize = size;
    width = windowWidth;
    height = windowHeight;
    
    
}

//triangles, hexagons, squares
void Grid::drawPolygon(){
        int x1 = 0;
        int y1 = 0;
        int x2 = -mySize/2;
        int y2 = mySize;
        int x3 = mySize/2;
        int y3 = mySize;
    
    for (int i = 0; i < 2.5*width/mySize; i++) { //width/mySize -1
           for (int j = 0; j < 2*height/mySize; j++) { //height/mySize -1
//               ofPoint a(-i*mySize,j*mySize);
//               ofPoint b(i*mySize, j*mySize);
//               ofPoint c(i*mySize - mySize, (j*mySize/2));
                   ofPoint a(x1, y1+j*100);
                   ofPoint b(x2, y2+j*100);
                   ofPoint c(x3, y3+j*100);
                   
               
                   triangles.push_back(ofxSandTriangle(a, b, c));

                   
                          }
           if (i % 3 == 0) {
               x2 += (mySize + mySize/2);
               if (i % 2 == 0) {
                   y2 -= mySize;
               }
               else {
                   y2 += mySize;
               }
               
           }
           else if (i % 3 == 1) {
               x1 += (mySize + mySize/2);
               if (i % 2 == 0) {
                   y1 -= mySize;
               }
               else {
                   y1 += mySize;
               }
           }
           else {
               x3 += (mySize + mySize/2);
               if (i % 2 == 0) {
                   y3 -= mySize;
               }
               else {
                   y3 += mySize;
               }
       }
       }}
           

void Grid::drawGrid(){
    for (int i = 0; i < triangles.size(); i++) {
        triangles[i].setOffset(0.5);
            triangles[i].draw(500);
        
    }
}
void Grid::drawGrid2(){
        fbo.begin();
        drawGrid();
        fbo.end();
        fbo.setAnchorPoint(fbo.getWidth()/2, fbo.getHeight()/2);
    
}
