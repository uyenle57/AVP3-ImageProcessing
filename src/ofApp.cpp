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
    
    myImage.load("/Users/uyenle/Desktop/AudioVisual/AVPCoursework_tle004/AVP3-ImageProcessing/bin/data/averie-woodard-111822.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myImage.resize(ofGetWindowWidth(), ofGetWindowHeight());
    myImage.draw(0, 0);
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
