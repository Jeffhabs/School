//
//  Rectangle.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//



#include <stdio.h>
#include "Shape.hpp"
#include <vector>
#pragma once

class Rectangle : public Shape
{
public:
    Rectangle(std::vector<Points *> points, const double r, const double g, const double b,   bool filled);
    void Draw();
    void Adjust(double x, double y, Points * selectedPoint);
    void Move(double x, double y, Points * selectedPoint);
    bool Contains(double x, double y) const;
    double getTop() const {
        return mTop;
    }
    double getBottom() const {
        return mBottom;
    }
    double getRight() const {
        return mRight;
    }
    double getLeft() const {
        return mLeft;
    }
    double getLength() const {
        return mRight - mLeft;
    }
    double getHeight() const {
        return mTop - mBottom;
    }
    
protected:
    double mTop, mBottom, mRight, mLeft;
};

