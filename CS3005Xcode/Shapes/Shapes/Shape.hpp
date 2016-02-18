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
#pragma once

class Point2D
{
public:
    Point2D(const double x, const double y);
    ~Point2D() {}
    void Draw();
    const double setX(double x){
        return mX = x;
    }
    const double setY(double y){
        return mY = y;
    }
    const double getX() const {
        return mX;
    }
    const double getY() const {
        return mY;
    }
    bool Contains(double x, double y) const;
    
private:
    double mX, mY;
};

class Shape
{
public:
    Shape(std::vector<Point2D *> points,
          const double r,
          const double b,
          const double g,
          bool filled);
    
    virtual ~Shape();
    virtual void Draw() = 0;
    virtual void DrawPoints();
    virtual void Adjust(double x, double y, Point2D * selectedPoint);
    virtual void Move(double x, double y, Point2D * selectedPoint);
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
    Point2D * getPoint(int i) const {
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
    std::vector<Point2D *> mVertices;
    double mRed, mBlue, mGreen;
    ShapeType mShapeType;
    bool mSelected, mFilled;
   
};