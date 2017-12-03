#include "ofApp.h"

/*
 Advanced Audio-Visual Processing Coursework
 Project 3: Image Processing
 
 by Uyen Le
 tle004@gold.ac.uk
 
 ----------------
 A simple project that processes images using pixels.
 
 ----------------
 Credits:
 - Image from https://www.unsplash.com
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    //Load the image
    myImage.load("/Users/uyenle/Desktop/AudioVisual/AVPCoursework_tle004/AVP3-ImageProcessing/bin/data/averie-woodard-111822.jpg");
    
    imagePixels.allocate(myImage.getWidth(), myImage.getHeight(), 1);
    
    //Store the pixels of the image into 'myPixels'
    imagePixels = myImage.getPixels();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

     myTexture.allocate(imagePixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Resize the image so that it fits with the window size
    myImage.resize(ofGetWindowWidth(), ofGetWindowHeight());


    //Image pixels processing happens here
    
    for (int i=0; i < imagePixels.getWidth(); i++) {
        for (int j=0; j < imagePixels.getHeight(); j++) {
            
            //Get the color of each pixel of the image
            ofColor color = imagePixels.getColor(i, j);
            
            //Draw lots of circles all over the screen
            //and color each circle using the pixel colour of the image
            ofSetColor(color);
            
            int spacing = 5;
            
            ofDrawEllipse(ofRandom(ofGetWindowWidth() * spacing), ofRandom(ofGetWindowHeight() * spacing), 5,5);
        }
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
