//
//  Button.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//


#include <stdio.h>
#include "Rectangle.hpp"
#pragma once

class Button : public Rectangle
{
public:
    Button(std::vector<Points *> points,
           const double r,
           const double g,
           const double b,
           const char * text,
           const int buttonType,
           const int associatedID);
    virtual void Draw();
    bool isButtonType(const int type) const {
        return mButtonType == type;
    }
    int getButtonID() const {
        return mButtonID;
    }
    bool setPressed(const bool b) {
        return mPressed = b;
    }
    bool isPressed() const {
        return mPressed;
    }
    const char * setText(const char * text);
protected:
    char mText[BUTTON_TEXT_MAX_LEN+ 1];
    int mButtonType;
    int mButtonID;
    bool mPressed;
};