//
//  Point.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/9/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Point.hpp"

Point::Point()
{
    
}

Point::Point(double x, double y)
:   mX(x),
mY(y)
{
    
}

void Point::setX(double x)
{
    mX = x;
}

void Point::setY(double y)
{
    mY = y;
}

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << int(rhs.getX()) << " " << int(rhs.getY()) << " ";
    return os;
}

std::istream &operator>>(std::istream &is, Point &rhs)
{
    double x, y;
    is >> x >> y;
    rhs.setX(x);
    rhs.setY(y);
    return is;
}

double Point::getX() const
{
    return mX;
}

double Point::getY() const
{
    return mY;
}