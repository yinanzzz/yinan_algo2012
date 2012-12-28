#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.06f;
	
	pos.set(ofGetWidth()/2,ofGetHeight()/2);
	prevPos.set(0,0);
    scl.x=0;
    scl.y=0;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
   // ofSetColor(198,246,55);
	
	ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(angle * RAD_TO_DEG);
    ofRect( 0,0, scl.x, scl.y);
	
	
	ofPopMatrix();
	
	
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	
	ofPoint diff = ofPoint (catchX, catchY) - ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);
    
	prevPos.x = pos.x;
	prevPos.y = pos.y;
	
    
}
