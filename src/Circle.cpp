//
//  Circle.cpp
//  AVP3-ImageProcessing
//
//  Created by Uyen on 04/12/2017.
//

#include "Circle.hpp"


Circle::Circle(float x, float y, ofColor c) {
    
    posx = x;
    posy = y;
    color = c;
    radius = 1;
    
    isGrowing = true;
}

void Circle::grow() {
    if(isGrowing) {
        radius++;
    }
}

void Circle::draw() {
    
    ofSetColor(color);
    ofFill();
    
    ofDrawEllipse(posx, posy, radius*2, radius*2);
}

bool Circle::isEdge() {
    return (posx+radius>ofGetWindowWidth() || posx-radius<0 || posy+radius>ofGetWindowHeight() || posy-radius<0);
}
