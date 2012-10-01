#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
  
}

void rectangle::update(){

}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
	ofLine(50,50,60,60);
	ofLine(70,50,60,60);
	ofLine(60,60,60,70);
	ofLine(80,50,80,70);
	ofLine(90,50,90,70);
	ofLine(90,50,100,70);
	ofLine(100,50,100,70);
	ofLine(110,50,105,70);
	ofLine(110,50,115,70);
	ofLine(107.5,60,112.5,60);
	ofLine(120,50,120,70);
	ofLine(120,50,130,70);
	ofLine(130,50,130,70);
}
