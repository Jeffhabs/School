//
//  Label.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#include "Label.hpp"
#include <vector>

Label::Label(std::vector<Points*> points,
             const double r,
             const double g,
             const double b,
             const char * text)
: Button (points, r, g, b, text, LABEL, NONE)
{}

void Label::Draw()
{
    // Draw the background rectangle:
    glColor3d(mRed, mGreen, mBlue);
    DrawRectangle(mVertices[0]->getX(), mVertices[0]->getY(),
                  mVertices[1]->getX(), mVertices[1]->getY());
    
    // Draw the label's text:
    glColor3d(0, 0, 0);
    DrawText((mVertices[0]->getX() < mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX()) +
             BUTTON_TEXT_OFFSET_X,
             (mVertices[0]->getY() > mVertices[1]->getY() ?
              mVertices[0]->getY() : mVertices[1]->getY()) -
             BUTTON_TEXT_OFFSET_Y,
             mText);
}