#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

    
    threshold=0;
    
    
    //CGDisplayHideCursor(kCGDirectMainDisplay);  
   // ofToggleFullscreen();
	ofSetVerticalSync(true);
	//ofBackgroundHex(0xfdefc2);
	ofSetCircleResolution(80);
    ofEnableAlphaBlending();
    ofBackground(0); 
    ofSetLogLevel(OF_LOG_NOTICE);

    
    //initialize the variable so it's off at the beginning
    usecamera = false;
    
    rectNum = 150; 
    
    number=0;
    
   piano.loadSound("EnglishSuite5-5.mp3");
   piano.play();
    
    
    //Sound input
	
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
    scaledVol1  =0.0; 
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
	for (int i=1; i<RECT_NUM;i++) {
        myRectangle[i].scl.x = 0 ;
        myRectangle[i].scl.y = 0 ;
        myRectangle[i].pos.x = ofGetWidth()/2;
        myRectangle[i].pos.y = ofGetHeight()/2;
        
    }
    
    for (int i=1; i<RECT_NUM;i++) {
        myRectangle2[i].scl.x = 0 ;
        myRectangle2[i].scl.y = 0 ;
        myRectangle2[i].pos.x = ofGetWidth()/2;
        myRectangle2[i].pos.y = ofGetHeight()/2;
        
    }
    
    
    for (int i=1; i<RECT_NUM;i++) {
        myRectangle3[i].scl.x = 0 ;
        myRectangle3[i].scl.y = 0 ;
        myRectangle3[i].pos.x = ofGetWidth()/2;
        myRectangle3[i].pos.y = ofGetHeight()/2;
        
    }

    
    
    
    
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
		

	
}

//--------------------------------------------------------------
void testApp::update() {
	
    
    
    // threshold
    
   
    if (threshold==1){
        amount+=0.1;
        threshold++;
    };
    
    
    if ( threshold==-1) {
        
        amount -=0.1;
        threshold++;
    };
    
    scaledVol= scaledVol1* (1.0+amount);    
    
    
    
	box2d.update();	
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	float minDis = ofGetKeyPressed() ? 300 : 5;    
	
    for(int i=0; i<circles.size(); i++) {
		float dis = mouse.distance(circles[i].getPosition());
		if(dis < minDis) circles[i].addRepulsionForce(mouse, 9);
		else circles[i].addAttractionPoint(mouse, 4.0);
		
		
	}
	for(int i=0; i<boxes.size(); i++) {
		float dis = mouse.distance(boxes[i].getPosition());
		if(dis < minDis) boxes[i].addRepulsionForce(mouse, 9);
		else boxes[i].addAttractionPoint(mouse, 4.0);
	}
    
    
    
    
    // no drawing
    if(number==10) {

    
//        myRectangle[0].scl.x = 0 ;
//        myRectangle[0].scl.y = 0 ;
//        myRectangle[0].pos.x =ofGetWidth()/2;
//         myRectangle[0].pos.y =ofGetHeight()/2;
        
        // myRectangle[0].catchUpSpeed = scaledVol*.5  ;
       // myRectangle[0].xenoToPoint(mouseX, mouseY);
        
        for (int i=0; i<RECT_NUM;i++) {
            
            
            myRectangle[i].scl.x = 0 ;
            myRectangle[i].scl.y = 0 ;
            myRectangle[i].pos.x = ofGetWidth()/2;
            myRectangle[i].pos.y= ofGetHeight()/2;
        }
        
        
        //second rectangle//
//        myRectangle2[0].scl.x = 0 ;
//        myRectangle2[0].scl.y = 0 ;
        // myRectangle2[0].catchUpSpeed = scaledVol*.5 ;
        //myRectangle2[0].xenoToPoint(mouseX*ofRandom((1+5*scaledVol),(1-5*scaledVol)), mouseY);
        
        for (int i=0; i<RECT_NUM;i++) {
            
            
            myRectangle2[i].scl.x = 0 ;
            myRectangle2[i].scl.y = 0 ;
            myRectangle2[i].pos.x = ofGetWidth()/2;
            myRectangle2[i].pos.y= ofGetHeight()/2;
        }
        
        
        //third rectangle//
//        myRectangle3[0].scl.x = 0 ;
//        myRectangle3[0].scl.y = 0 ;
        // myRectangle3[0].catchUpSpeed = scaledVol*.5 ;
        //myRectangle3[0].xenoToPoint(mouseX*ofRandom((1+5*scaledVol),(1-5*scaledVol)), mouseY);
        
        for (int i=0; i<RECT_NUM;i++) {
            
            
            myRectangle3[i].scl.x = 0 ;
            myRectangle3[i].scl.y = 0 ;
            myRectangle3[i].pos.x = ofGetWidth()/2;
            myRectangle3[i].pos.y= ofGetHeight()/2;
        }

         //six rectangle//
        for (int i=0; i<RECT_NUM;i++) {
            
            
            myRectangle6[i].scl.x = 0 ;
            myRectangle6[i].scl.y = 0 ;
            myRectangle6[i].pos.x = ofGetWidth()/2;
            myRectangle6[i].pos.y= ofGetHeight()/2;
        }
        
    } ;
    
    
    
    
    //first rectangle//
    
    
    if(number==0) {
        myRectangle[0].scl.x = 0 ;
        myRectangle[0].scl.y = 0 ;
        myRectangle[0].catchUpSpeed = scaledVol*.5  ;
        myRectangle[0].xenoToPoint(mouseX, mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle[i].scl.x = 0 ;
            myRectangle[i].scl.y = 0 ;
            myRectangle[i].pos.x = ofGetWidth()/2;
            myRectangle[i].pos.y= ofGetHeight()/2;
        }
        
        
        //second rectangle//
        myRectangle2[0].scl.x = 0 ;
        myRectangle2[0].scl.y = 0 ;
        // myRectangle2[0].catchUpSpeed = scaledVol*.5 ;
        //myRectangle2[0].xenoToPoint(mouseX*ofRandom((1+5*scaledVol),(1-5*scaledVol)), mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle2[i].scl.x = 0 ;
            myRectangle2[i].scl.y = 0 ;
            myRectangle2[i].pos.x = ofGetWidth()/2;
            myRectangle2[i].pos.y= ofGetHeight()/2;
        }
        
        
        //third rectangle//
        myRectangle3[0].scl.x = 0 ;
        myRectangle3[0].scl.y = 0 ;
        // myRectangle3[0].catchUpSpeed = scaledVol*.5 ;
        //myRectangle3[0].xenoToPoint(mouseX*ofRandom((1+5*scaledVol),(1-5*scaledVol)), mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle3[i].scl.x = 0 ;
            myRectangle3[i].scl.y = 0 ;
            myRectangle3[i].pos.x = ofGetWidth()/2;
            myRectangle3[i].pos.y= ofGetHeight()/2;
        }
    }
    
    
    
    
    
    
    if(number>0 & number<4) {
        
        myRectangle[0].scl.x = 20+ scaledVol * 590.0f ;
        myRectangle[0].scl.y = 1+ scaledVol ;
        myRectangle[0].catchUpSpeed = scaledVol*.5  ;
        myRectangle[0].xenoToPoint(mouseX, mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle[i].catchUpSpeed = 0.4 ;
            myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x, myRectangle[i-1].pos.y);
        }
        
        
        
        
    }
    
    
    
    
    
    if(number==1  ) {
        
        //rectangle2 disappear
        
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle2[i].scl.x = 0;
            myRectangle2[i].scl.y = 0;   
        }
        
        
        //rectangle3 disappear
        
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle3[i].scl.x = 0;
            myRectangle3[i].scl.y = 0;   
        }   
        
        
        
        //rectangle4   disappear
        
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle4[i].scl.x = 0;
            myRectangle4[i].scl.y = 0;   
        }
        
        //rectangle5  disappear 
        
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle5[i].scl.x = 0;
            myRectangle5[i].scl.y = 0;   
        }
        
        
        //rectangle6  disappear
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle6[i].scl.x = 0;
            myRectangle6[i].scl.y = 0;   
        }
        
        
        //rectangle7  disappear
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle7[i].scl.x = 0;
            myRectangle7[i].scl.y = 0;   
        }
        
    };
    
    
    
    
    
    
    //second rectangle//
    if(number>=2 & number <4) {
        
        //second rectangle//
        myRectangle2[0].scl.x = 20+ scaledVol * 590.0f ;
        myRectangle2[0].scl.y = 1+ scaledVol ;
        myRectangle2[0].catchUpSpeed = scaledVol*.5 ;
        myRectangle2[0].xenoToPoint(mouseX*ofRandom((1+5*scaledVol),(1-5*scaledVol)), mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle2[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle2[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle2[i].catchUpSpeed = 0.4 ;
            myRectangle2[i].xenoToPoint(myRectangle2[i-1].pos.x, myRectangle2[i-1].pos.y);
        }
        
    }
    
    
    
    
    //third rectangle//
    
    if(number==3)  {
        
        myRectangle3[0].scl.x = 20+ scaledVol * 590.0f ;
        myRectangle3[0].scl.y = 1+ scaledVol ;
        myRectangle3[0].catchUpSpeed = scaledVol*.6  ;
        myRectangle3[0].xenoToPoint(mouseX*ofRandom((1+3*scaledVol),(1-3*scaledVol)), mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle3[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle3[i].scl.y = myRectangle3[i-1].scl.y-0.01 ;
            myRectangle3[i].catchUpSpeed = 0.4 ;
            myRectangle3[i].xenoToPoint(myRectangle3[i-1].pos.x, myRectangle3[i-1].pos.y);
        }
        
        
    }  
    
    
    
    
    if(number==4 ) {
        
        
        myRectangle[0].scl.x = 20+ scaledVol * 590.0f ;
        myRectangle[0].scl.y = 1+ scaledVol ;
        myRectangle[0].catchUpSpeed = scaledVol*.5  ;
        myRectangle[0].xenoToPoint(mouseX, mouseY);
        
        for (int i=1; i<RECT_NUM;i++) {
            
            
            myRectangle[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle[i].catchUpSpeed = 0.4 ;
            myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x, myRectangle[i-1].pos.y);
            
            // rectangle duplicate1
            myRectangle4[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle4[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle4[i].catchUpSpeed = 0.3 ;
            myRectangle4[i].xenoToPoint(ofGetWidth()-myRectangle[i-1].pos.x, ofGetHeight()-myRectangle[i-1].pos.y);
            
            // rectangle duplicate2
            
            myRectangle5[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle5[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle5[i].catchUpSpeed = 0.3 ;
            myRectangle5[i].xenoToPoint(ofGetWidth()-myRectangle[i-1].pos.x+i*0.15, myRectangle[i-1].pos.y);
            
            // rectangle duplicate3
            
            myRectangle6[i].scl.x = 20+ scaledVol * 200.0f ;
            myRectangle6[i].scl.y = myRectangle[i-1].scl.y-0.01 ;
            myRectangle6[i].catchUpSpeed = 0.3 ;
            myRectangle6[i].xenoToPoint(myRectangle[i-1].pos.x+i*0.15, ofGetHeight()-myRectangle[i-1].pos.y);
            
        }
        
        
        
        
        myRectangle7[0].scl.x = (mouseX-myRectangle[0].pos.x)/3;
        myRectangle7[0].scl.y = 1 ;
        myRectangle7[0].pos.x = ofGetWidth()/2 + (mouseX-myRectangle[0].pos.x ) ;
        myRectangle7[0].pos.y = ofGetHeight()/2  ;
        
        for (int i=1; i<20;i++) {
            myRectangle7[i].scl.x = 5 ;
            myRectangle7[i].scl.y = 2 ;
            myRectangle7[i].catchUpSpeed =2;
            myRectangle7[i].xenoToPoint(myRectangle7[i-1].pos.x,myRectangle7[i-1].pos.y );
        }
        
        myRectangle7[20].scl.x = 1 ;
        myRectangle7[20].scl.y = (mouseX-myRectangle[0].pos.x)/3 ;
        myRectangle7[20].pos.x = ofGetWidth()/2  ;
        myRectangle7[20].pos.y = ofGetHeight()/2 + (mouseY-myRectangle[0].pos.y )   ;
        
        for (int i=21; i<40;i++) {
            myRectangle7[i].scl.x = 5 ;
            myRectangle7[i].scl.y = 2 ;
            myRectangle7[i].catchUpSpeed = 2 ;
            myRectangle7[i].xenoToPoint(myRectangle7[i-1].pos.x,myRectangle7[i-1].pos.y );
        }
        
        
        
        
        //rectangle2 disappear
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle2[i].scl.x = 0;
            myRectangle2[i].scl.y = 0;   
        }
        
        
        //rectangle3 disappear
        
        for (int i=0; i<RECT_NUM;i++) {
            
            myRectangle3[i].scl.x = 0;
            myRectangle3[i].scl.y = 0;   
        }   
        
        
        
    }
    
    
    //tail
    
    
    
    //tail with rectangle1
    timePoint temp;
    
    if(number==0) {  
        
        temp.x =  myRectangle[0].pos.x;
        temp.y = myRectangle[0].pos.y;
    }    
    
	temp.t = ofGetElapsedTimef() - startTime;
	pts.push_back(temp);
	
    
    if(number==0) {   
        
        if (pts.size() > 750){
            pts.erase(pts.begin());
        }
        
    }
    
    
    if(number>0) {   
        
        pts.erase(pts.begin());   // how to erase faster?????
        
    }  
    
    
    
    
    
    //lets scale the vol up to a 0-1 range 
	scaledVol1 = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
	//lets record the volume into an array
	volHistory.push_back( scaledVol1 );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}

    
    
    
}


//--------------------------------------------------------------
void testApp::draw() {
	
	
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		//ofSetHexColor(0xf6c738);
        ofSetColor(255) ;
		circles[i].draw();
	}
	
	for(int i=0; i<boxes.size(); i++) {
		ofFill();
		ofSetColor(255) ;
        //ofSetHexColor(0xBF2545);
		boxes[i].draw();
	}
	
	// draw the ground
	box2d.drawGround();
	
	
    for (int i=0; i<RECT_NUM;i++) {
        
        
        
        ofSetColor(255-i);
        // ofSetColor(ofMap(i, 0, 99, 255, 50),ofMap(i, 0, 99, 200, 100));  ///??
        
        
        myRectangle[i].draw();
        myRectangle4[i].draw();
        myRectangle5[i].draw();
        myRectangle6[i].draw();
        
        
        
        
        ofSetColor(255-i, 150-i, 0);
        myRectangle2[i].draw();
        
        ofSetColor(218-i,221,232-i);
        myRectangle3[i].draw();
        
        
        ofSetColor(150);
        myRectangle7[i].draw();
        
    }
    
    //tail
    
    ofSetColor(250);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i <pts.size() ;i++){
		ofVertex(pts[i].x, pts[i].y);
	}
	ofEndShape();

    
    
    
    
    
    
    
    
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
void testApp::keyPressed(int key) {
	
    if(key == 't') { ofToggleFullscreen();CGDisplayHideCursor(kCGDirectMainDisplay); }
	
    if(key == 'c') {
		float r = ofRandom(14, 20);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.9);
		circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle);
	}
	
	if(key == 'b') {
		float w = ofRandom(14, 20);	
		float h = ofRandom(14, 20);	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.9);
		rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);
	}
    
//    switch(key){
//        case 's':
//            soundStream.start();
//            break;
//        case 'e':
//            soundStream.stop();
//            break;
//        case '`':
//            number=0;   
//            break;
//            
//    }
	
    if( key == 's' ){
		soundStream.start();
	}
    
    if( key == 'e' ){
		soundStream.stop();
	}
    
    if( key == '`' ){
		number=0;
	}
    
    if( key == '1' ){
		number=1;
	}
    if( key == '2' ){
		number=2;
	}
    
    if( key == '3' ){
		number=3;
	}
    
    if( key == '4' ){
		number=4;
	}
    
    if( key == '5' ){
		number=5;
	}
    
    if( key == '6' ){
		number=6;
	}
    
    if( key == '7' ){
		number=7;
	}

    if( key == '0' ){
		number=10;
	}
    
    if( key == '=' ){
		threshold=1;
	}   
    
    
    if( key == '-' ){
		threshold=-1;
	}   
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}

