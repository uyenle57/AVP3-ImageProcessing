#include "ofApp.h"

/*
 Advanced Audio-Visual Processing Coursework
 Project 3: Image Processing
 
 by Uyen Le
 tle004@gold.ac.uk
 
 ----------------
 A simple project that draws Phyllotaxis using pixel colours from an image.
 
 - First we load and process the image to get colour of each pixel.
 - Then draw the Phyllotaxis shape
 - And assign each pixel colour to each circle of the Phyllotaxis shape
 
 
 ----------------
 Credits:
 - Image from https://www.unsplash.com
 - Phyllotaxis tutorial: https://www.youtube.com/watch?v=KWoJgHFYWxY
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    ofSetVerticalSync(true);
    
    //Load the image
    myImage.load("/Users/uyenle/Desktop/AudioVisual/AVPCoursework_tle004/AVP3-ImageProcessing/bin/data/averie-woodard-111822.jpg");
    
    imagePixels.allocate(myImage.getWidth(), myImage.getHeight(), 1);
    
    //Store the pixels of the image into 'myPixels'
    imagePixels = myImage.getPixels();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    n++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //Resize the image so that it fits with the window size
    myImage.resize(ofGetWindowWidth(), ofGetWindowHeight());
    

    //Image pixels processing happens here

//    for (int i=0; i < myImage.getWidth(); i++) {
//        for (int j=0; j < myImage.getHeight(); j++) {
//
//            //Get the color of each pixel of the image
//            imageColor = myImage.getColor(i, j);
//
//            //Draw lots of tiny squares all over the screen and color each square using the pixel colour of the image
//            ofSetColor(imageColor, ofRandom(100)); //randomising alpha value gives glittering effect
//
//            ofDrawRectangle(i, j, 5, 5);
//
//        }
//    }
 
    camera.begin();
    
    glEnable(GL_DEPTH_TEST);
    
    ofSetColor(255, 255, 255);
    ofFill();
    
    ofPushMatrix();
    
    // Phyllotaxis shape
    double angle = n * ofRadToDeg(137.5); //137.3, 137.5, 137.6
    double radius = c * sqrt(n);
    
    double x = radius * cos(angle);
    double y = radius * sin(angle);
    
    ofDrawSphere(x, y, 0, 7);
    
    ofPopMatrix();
    
    camera.end();
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
