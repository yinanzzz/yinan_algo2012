#ifndef _TEST_APP
#define _TEST_APP

#define RECT_NUM 150 

//#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "rectangle.h"
#include "timePoint.h"

// -------------------------------------------------

class testApp : public ofBaseApp {
	
public:
    
    int rectNum;
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
    //void windowResized(int w, int h);
    //void dragEvent(ofDragInfo dragInfo);
    //void gotMessage(ofMessage msg);

	
	
	ofxBox2d						box2d;			  //	the box2d world
	vector		<ofxBox2dCircle>	circles;		  //	default box2d circles
	vector		<ofxBox2dRect>		boxes;			  //	defalut box2d rects
	
    
    
    
    void audioIn(float * input, int bufferSize, int nChannels); 
	
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    float scaledVol1;
    
    
    vector < timePoint > pts;
    float startTime;
    
    
    rectangle myRectangle[RECT_NUM];
    rectangle myRectangle2[RECT_NUM];
    rectangle myRectangle3[RECT_NUM];
    rectangle myRectangle4[RECT_NUM];
    rectangle myRectangle5[RECT_NUM];
    rectangle myRectangle6[RECT_NUM];
    rectangle myRectangle7[RECT_NUM];
    
    ofSoundStream soundStream;
    
    // music
    ofSoundPlayer piano;
    
    int number;
    
    
    //our camera objects for looking at the scene from multiple perspectives
	ofCamera camera;
	
	//if usecamera is true, we'll turn on the camera view
    bool usecamera;

    
    int threshold; 
    float amount;
    
};
#endif	
