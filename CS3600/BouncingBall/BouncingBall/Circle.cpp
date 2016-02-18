//
//  Circle.cpp
//  BouncingBall
//
//  Created by Jeffrey Haberle on 1/19/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include "Circle.hpp"


Circle::Circle(double x, double y, double dX, double dY, double radius, double red, double green, double blue)
{
    this->x = x;
    this->y = y;
    this->dX = dX;
    this->dY = dY;
    this->radius = radius;
    this->red = red;
    this->green = green;
    this->blue = blue;
}