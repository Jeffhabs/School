//
//  Line.cpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Line.hpp"

Line::Line(Point p1, Point p2)
{
    mWidth = 5;
    mVertical = p1.getY() > p2.getY();
    setLP1(p1);
    setLP2(p2);
}
void Line::draw()
{
    glColor3d(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP3.getX(), mP3.getY());
    glVertex2d(mP4.getX(), mP4.getY());
    glEnd();
}
void Line::setLP1(Point p)
{
    mLP1 = p;
    if (mVertical) {
        double x1 = mLP1.getX() - (mWidth / 2);
        double x2 = mLP1.getX() + (mWidth / 2);
        mP1 = Point(x1, mLP1.getY());
        mP2 = Point(x2, mLP1.getY());
    } else {
        double y1 = mLP1.getY() - (mWidth / 2);
        double y2 = mLP1.getY() + (mWidth / 2);
        mP1 = Point(mLP1.getX(), y1);
        mP2 = Point(mLP1.getX(), y2);
    }
}
void Line::setLP2(Point p)
{
    mLP2 = p;
    if (mVertical) {
        double x1 = mLP2.getX() + (mWidth / 2);
        double x2 = mLP2.getX() - (mWidth / 2);
        mP3 = Point(x1, mLP2.getY());
        mP4 = Point(x2, mLP2.getY());
    } else {
        double y1 = mLP2.getY() + (mWidth / 2);
        double y2 = mLP2.getY() - (mWidth / 2);
        mP3 = Point(mLP2.getX(), y1);
        mP4 = Point(mLP2.getX(), y2);
    }
}
Point Line::getLP1()
{
    return mLP1;
}
Point Line::getLP2()
{
    return mLP2;
}