//
//  Slider.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/17/15.
//
//

#include "Slider.hpp"
#include <vector>


Slider::Slider(std::vector<Points *> points,
               const double r,
               const double g,
               const double b,
               const int associatedID)
: Button (points, r, g, b, " ", RGB_SLIDER, associatedID)
{
    mSliderLength = 0.0;
}

void Slider::Draw()
{
    glColor3d(0, 0, 0);
    DrawRectangle(mVertices[0]->getX(), mVertices[0]->getY(),
                  mVertices[1]->getX(), mVertices[1]->getY());
    
    // Draw the slider rectangle:
    glColor3d(mRed, mGreen, mBlue);
    DrawRectangle(mVertices[0]->getX(), mVertices[0]->getY(),
                  mSliderLength + mLeft, mVertices[1]->getY());
}

