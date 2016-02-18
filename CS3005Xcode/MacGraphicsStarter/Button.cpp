//
//  Button.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#include "Button.hpp"
#include <vector>

Button::Button(std::vector<Points*> points,
               const double r,
               const double g,
               const double b,
               const char * text,
               const int buttonType,
               const int associatedID)
: Rectangle (points, r, g, b, true)
{
    setText(text);
    mButtonType = buttonType;
    mButtonID= associatedID;
    mPressed = false;
    mSelected = false;
}

void Button::Draw()
{
    // Draw a black outline if the button is currently selected:
    if (mSelected)
    {
        glColor3d(0, 0, 0);
        double x1 = mVertices[0]->getX() < mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX();
        double x2 = mVertices[0]->getX() > mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX();
        double y1 = mVertices[0]->getY() > mVertices[1]->getY() ? mVertices[0]->getY() : mVertices[1]->getY();
        double y2 = mVertices[0]->getY() < mVertices[1]->getY() ? mVertices[0]->getY() : mVertices[1]->getY();
        
        DrawRectangle(x1 - BUTTON_OUTLINE_THICKNESS,
                      y1 + BUTTON_OUTLINE_THICKNESS,
                      x2 + BUTTON_OUTLINE_THICKNESS,
                      y2 - BUTTON_OUTLINE_THICKNESS);
    }
    
    // Draw the button (using an alternative color if currently pressed/clicked):
    if (mPressed)
        glColor3d(mRed - 0.5, mGreen - 0.5, mBlue - 0.5);
    else
        glColor3d(mRed, mGreen, mBlue);
    DrawRectangle(mVertices[0]->getX(), mVertices[0]->getY(),
                  mVertices[1]->getX(), mVertices[1]->getY());
    
    // Draw the button's text, if any (alternative color is pressed/clicked):
    if (mPressed)
        glColor3d(1.0, 1.0, 1.0);
    else
        glColor3d(0, 0, 0);
    DrawText((mVertices[0]->getX() < mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX()) + BUTTON_TEXT_OFFSET_X,
             (mVertices[0]->getY() > mVertices[1]->getY() ?
              mVertices[0]->getY() : mVertices[1]->getY()) -
             BUTTON_TEXT_OFFSET_Y,
             mText);
}

const char * Button::setText(const char * text)
{
    std::strncpy(mText, text, BUTTON_TEXT_MAX_LEN);
    mText[BUTTON_TEXT_MAX_LEN] = '\0';
    
    return mText;
}