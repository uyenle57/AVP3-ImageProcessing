//
//  Circle.hpp
//  AVP3-ImageProcessing
//
//  Created by Uyen on 04/12/2017.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"

class Circle {
    
public:
    Circle(float x, float y, ofColor c);
    
    void draw();
    void grow();
    bool isEdge();
    
    bool isGrowing;
    
    float posx, posy, radius;
    
    ofColor color;
};

#endif /* Circle_hpp */
