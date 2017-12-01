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
 - Week 9 code example attachment: edges-dilations-blobs
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Load the image
    myImage.load("/Users/uyenle/Desktop/AudioVisual/AVPCoursework_tle004/AVP3-ImageProcessing/bin/data/averie-woodard-111822.jpg");
    
    //Allow memory for the pixels
    myPixels.allocate(myImage.getWidth(), myImage.getHeight(),1);
    
    myPixels2.allocate(myImage.getWidth(), myImage.getHeight(),1);
    
    myPixels3.allocate(myImage.getWidth(), myImage.getHeight(),1);
    
    //Stick the pixels into one of the copies. Makes things a bit clearer.
    pixelsCopy = myImage.getPixels();
    
    pixelsCopy.allocate(myImage.getWidth(), myImage.getHeight(),3);
    
    
    // Image processing happens here
    
    // GREYSCALE
//    for (int i =0; i < myImage.getWidth() * myImage.getHeight(); i++) {
//
//        int index = i*3; //get the current position of each pixel
//
//        myPixels[i] = (pixelsCopy[index] * 0.2126) + (pixelsCopy[index+1] * 0.7152) + (pixelsCopy[index+2] * 0.0722);
//
//        //if current position is larger than threshold level 128
//        if (myPixels[i] > 128) {
//            myPixels[i]=255; //set pixel colour to white
//        }
//        else {
//            myPixels[i]=0; //otherwise set pixel colour to black
//        }
//    }
//
//    //Apply the texture to the copy image using memory allocation
//    myTexture.allocate(myPixels);
    
    //EDGE DETECTION
    // We can also generate a list of pixel positions that represent the edge of the shape
//    for (int i = 1; i < myImage.getHeight(); i++) {
//
//        int coll = i * myImage.getWidth();
//
//        for (int j = 1; j < myImage.getWidth()-1; j++) {
//
//            if (abs(myPixels[coll+j]-myPixels[coll+(j-1)]) > 0) {
//                myPixels2[coll+j]=255;
//            }
//            else {
//                myPixels2[coll+j]=0;
//            }
//        }
//    }
//
//    myTexture.allocate(myPixels2);
    
    // EDGE BLUR
    // Now we can generate a new list of pixel positions that represent the edge of the blur
    for (int i = 1; i < myImage.getHeight();i++) {
        
        int coll=i*myImage.getWidth();
        
        for (int j = 1; j < myImage.getWidth()-1; j++) {
            
            // make every positive pixel maximum
            if (myPixels[coll+j] > 0) {
                
                myPixels[coll+j] = 255;
            }
            
            // Now we get a blob!
            if (abs(myPixels[coll+j]-myPixels[coll+(j-1)]) > 0) {
                
                myPixels3[coll+j]=255;
                
            } else {
                myPixels3[coll+j]=0;
                
            }
        }
    }
    myTexture.allocate(myPixels3);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //Resize the image so that it fits with the window size
    pixelsCopy.resize(ofGetWindowWidth(), ofGetWindowHeight());
    
    //Display the image
    myTexture.draw(0, 0);
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
