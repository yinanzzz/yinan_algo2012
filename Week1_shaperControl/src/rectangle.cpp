#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	shaper = 7;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(pos.x/2,60,pos.x/2);
    if (pos.x < 500) {
    	ofRect(500, 300, pos.x,1 );
    }
else {
	ofRect(500, 300, 500,pos.x-499 );
}

}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
	
	
	//powf (2, 3) = 8;
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	//pos.y = (1-pct) * posa.y + (pct) * posb.y;
}