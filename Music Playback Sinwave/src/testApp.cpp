#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	 
	
	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);	
	    ofToggleFullscreen();
    
    piano.loadSound("piano.mp3");
    piano.play();
    
    
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.listDevices();
	
	//if you want to set a different device id 
	//soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
	
	int bufferSize = 256;
	
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    // draw
    	radius = 50;
    x=500;
    y=300;
    xoffset=0;
    yoffset=0;
}

//--------------------------------------------------------------
void testApp::update(){
	//lets scale the vol up to a 0-1 range 
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
    // draw
    	radius = radius*scaledVol ;
    
    
    
}
//--------------------------------------------------------------
    void testApp::draw(){
	
	
//				ofSetColor(245, 58, 135);
//		ofFill();		
//		ofCircle(200, 200, scaledVol * 190.0f);
	
    
    // draw	

    float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	float angle = ofGetElapsedTimef()*3.5+scaledVol*100;
    
   if(  orin==1)   
   { 
       x = x +  cos(angle)*scaledVol*200;
       y = y - sin(angle)*scaledVol*200;} 
   else
       {   x = x +  cos(angle)*scaledVol*200;
           y = y + sin(angle)*scaledVol*200;};

        
        if(x>ofGetWidth()) { x=ofGetWidth();};
        if(y>ofGetHeight()) { y=ofGetHeight();};
        if(x<0){ x=0;};
        if(y<0){ y=0;};
//        if(ofGetElapsedTimef() > 5) {     
//           
//        y = y+ sin(angle)*scaledVol*100;
//        } 
//        
        
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
	if (points.size() > 500){
		points.erase(points.begin());
	}
	
    ofSetColor(255,255,255);
	
	ofNoFill();
	ofBeginShape();
	
        for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
    
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255,0,127);
	ofFill();
	ofCircle(x,y,scaledVol * 140.0f);
	

    
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		soundStream.start();
	}
	
	if( key == 'e' ){
		soundStream.stop();
	}
    
    if( key == 'q' ){orin=1
		;
	}
    
    if( key == 'w' ){ orin=0
		;
	}
    
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

