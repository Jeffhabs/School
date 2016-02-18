//
//  Point.cpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
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

//void Point::draw()
//{
//    glColor3d(mColor[0], mColor[1], mColor[2]);
//    glBegin(GL_POLYGON);
//    for(int i = 0; i < 32; i++) {
//        double theta = (double)i / 32.0 * 2.0 * 3.1415926;
//        double x = mX + mRadius * cos(theta);
//        double y = mY + mRadius * sin(theta);
//        glVertex2d(x, y);
//    }
//    glEnd();
//}
//
//void Point::setColor(std::vector<double> color)
//{
//    mColor = color;
//}
//
//void Point::save(std::ostream &os)
//{
//
//}
//
//void Point::load(std::istream &is)
//{
//
//}

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