#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.06f;
	
	pos.set(0,0);
	prevPos.set(0,0);
}

//------------------------------------------------------------------
void rectangle::draw() {
	
	float sinOfTime				= sin( ofGetElapsedTimef() );
	float sinOfTimeMapped		= ofMap( sinOfTime, 0, 1, 10, 15);
	
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
	
	ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotateZ(angle * RAD_TO_DEG);
	ofSetColor(198,200,55);
	ofRect(-70,0,100,3+sinOfTimeMapped*5);
	
	ofSetColor(198,246,55);
	for (int i = 0; i < 10; i++){
	ofRect( -i*3*sinOfTimeMapped,0, sinOfTimeMapped,sinOfTimeMapped);
	}
		ofRect(15,0,3,3);
	ofCircle(30,30,5);
	ofCircle(30,-30,5);
	
	ofPopMatrix();
	
	
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);

	prevPos.x = pos.x;
	prevPos.y = pos.y;
	

}
