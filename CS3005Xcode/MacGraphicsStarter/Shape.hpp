//
//  Shape.hpp
//  Shapes
//
//  Created by Jeffrey Haberle on 10/28/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "Draw.hpp"
#include "Points.hpp"
#pragma once

//button types enumeration
enum ButtonType
{
    MODE_BUTTON,
    COLOR_BUTTON,
    RGB_SLIDER,
    FILL_BUTTON,
    OUTLINE_BUTTON,
    UNDO_BUTTON,
    CLEAR_BUTTON,
    SAVE_BUTTON,
    LOAD_BUTTON,
    QUIT_BUTTON,
    LABEL,
    
    NUM_BUTTON_TYPES
};

//Yuck! globals :(
const double POINT_RADIUS             = 4.0;
const double DEFAULT_POINT_RED        = 0.0;
const double DEFAULT_POINT_GREEN      = 0.0;
const double DEFAULT_POINT_BLUE       = 0.0;
const double BUTTON_OUTLINE_THICKNESS = 2.0;
const double BUTTON_TEXT_OFFSET_X     = 10.0;
const double BUTTON_TEXT_OFFSET_Y     = 15.0;
const int    BUTTON_TEXT_MAX_LEN      = 30;


class Shape
{
public:
    Shape(std::vector<Points *> points, const double r, const double b, const double g, bool filled);
    
    virtual ~Shape();
    virtual void Draw() = 0;
    virtual void DrawPoints();
    
    
    void setColor(double r, double b, double g);
    
    const double setRed(double r){
        return mRed = r;
    }
    const double setBlue(double b){
        return mBlue = b;
    }
    const double setGreen(double g){
        return mGreen = g;
    }
    const double getRed() const {
        return mRed;
    }
    const double getBlue() const {
        return mBlue;
    }
    const double getGreen() const {
        return mGreen;
    }
    const bool isFilled() const {
        return mFilled;
    }
    const ShapeType getShapeType() const {
        return mShapeType;
    }
    Points * getPoint(int i) const {
        return mVertices[i];
    }
    int numPoints() const {
        return (unsigned)mVertices.size();
    }
    bool setSelected(const bool s) {
        return mSelected = s;
    }
    bool isSelected() const {
        return mSelected;
    }
    
protected:
    std::vector<Points *> mVertices;
    double mRed, mBlue, mGreen, mNewRGB;
    ShapeType mShapeType;
    bool mSelected, mFilled;
   
};






































