#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	for(int i = 0; i < 50; i++){
        myRectangle[i].pos.x =100;   //ofRandom(ofGetWidth());
        myRectangle[i].pos.y =50;   //ofRandom(ofGetHeight());
    }
	
	// set the position of the rectangle:
	
	//myRectangle.pos.x = 100;
	//myRectangle.pos.y = 50;
	
}

//--------------------------------------------------------------
void testApp::update(){
	//myRectangle.xenoToPoint(mouseX, mouseY);
	
	myRectangle[0].xenoToPoint(mouseX, mouseY);
    for(int i = 1; i < 50;i++){
        myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x, myRectangle[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < 50;i++){
        myRectangle[i].draw();
    }
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
