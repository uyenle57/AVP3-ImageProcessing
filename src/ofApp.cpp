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
    
    myPixels.allocate(myImage.getWidth(), myImage.getHeight(), 1);
    
    //Store the pixels of the image into 'myPixels'
    myPixels = myImage.getPixels();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

     myTexture.allocate(myPixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Resize the image so that it fits with the window size
    myImage.resize(ofGetWindowWidth(), ofGetWindowHeight());

    vector <ofColor> myColors;

    ///////
    for (int i=0; i < myPixels.getWidth(); i++) {
        for (int j=0; j < myPixels.getHeight(); j++) {
            
            ofColor color = myPixels.getColor(i, j);
            
            myColors.push_back(color);
        }
        
    }


    // Draw lots of circles all over the screen
    int spacing = 10;

    for(int i=0; i < myColors.size(); i++) {
        // colour each circle using the color pixel of the image
        ofSetColor(myColors[i]);
        
        ofDrawEllipse(ofRandom(ofGetWindowWidth() * spacing), ofRandom(ofGetWindowHeight() * spacing), 5,5);

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
