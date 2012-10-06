#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	float modulator = ofMap( sin(ofGetElapsedTimef()*2.7), -1, 1, 0, 1);
	
	
	
	ofSetColor(255,255,255);
	
		for (int i = 0; i < 30; i++){
	float xpos		= ofMap( sin(ofGetElapsedTimef()*3*i) * modulator, -1, 1, 0, ofGetWidth()+i);
	float ypos		= ofMap( sin(ofGetElapsedTimef()*5*i), -1, 1, 0, ofGetWidth()/3);
	ofRect(xpos, ypos, 12+ofRandom(3),12+ofRandom(3));
		}
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

