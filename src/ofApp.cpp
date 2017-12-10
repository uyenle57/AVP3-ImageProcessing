#include "ofApp.h"

/*
 Advanced Audio-Visual Processing Coursework
 Project 3: Image Processing
 
 by Uyen Le
 tle004@gold.ac.uk
 
 ----------------
 A simple project that explores image pixel manipulation of an image by drawing packed circles.
 
 ----------------
 Credits:
 - Image from Google.com 'The Kiss'
 - Animated Circle Packing tutorial: https://www.youtube.com/watch?v=QHEQuoIKgNE
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    ofSetFrameRate(100); //speed up frame rate so circles appear faster
    
    //Load the image
    myImage.load("/Users/uyenle/Desktop/AudioVisual/AVPCoursework_tle004/AVP3-ImageProcessing/bin/data/the-kiss-1908.jpg");
    
    imagePixels.allocate(myImage.getWidth(), myImage.getHeight(), 1);
    
    //Store the pixels of the image into 'myPixels'
    imagePixels = myImage.getPixels();

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Resize the image so that it fits with the window size
    myImage.resize(ofGetWindowWidth(), ofGetWindowHeight());

    
    // Create the animated packing circles
    float x = ofRandom(ofGetWindowWidth());
    float y = ofRandom(ofGetWindowHeight());
    
    bool validCircle = true;
    
    //Make sure circles don't grow inside each other
    for(Circle c : circles) {
        float dist = ofDist(x, y, c.posx, c.posy);
        
        //if position of current and nearby circle overlap
        //then it's no longer valid
        if (dist < c.radius) {
            validCircle = false;
            break;
        }
    }
    
    //Add a new valid circle every frame
    if (validCircle) {
        
        //Image pixels processing happens here
        
        int index = int(x) + int(y) * myImage.getWidth(); //Get the position of the current pixel
        
        ofColor color = myImage.getColor(x, y); //Get the colour of the current pixel
        
        circles.push_back(*new Circle(x, y, color)); //Create a new circle at the position of that pixel and colour it using that pixel's colour
    }

    for(int i=0; i < circles.size(); i++) {
        
        //Stop growing if touch the edge of the screen
        if (circles[i].isGrowing) {
            if(circles[i].isEdge()) {
                circles[i].isGrowing = false;
            }
            //Make sure circles don't overlap each other by disable growing once the radius of each circle touches the other's
            else {
                for (int j=0; j < circles.size(); j++) {
                    if((circles[i].posx != circles[j].posx) && (circles[i].posy != circles[j].posy)) {
                        
                        float dist = ofDist(circles[i].posx, circles[i].posy, circles[j].posx, circles[j].posy);
                        
                        if(dist < circles[i].radius + circles[j].radius) {
                            circles[i].isGrowing = false;
                            break;
                        }
                    }
                }
            }
        }
        circles[i].draw();
        circles[i].grow();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
