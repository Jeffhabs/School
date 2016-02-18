//
//  Square.cpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Square.hpp"

Square::Square(double x, double y, double size)
:   mLeft(x),
mBottom(y),
mSize(size),
mBoardSize(3)
{
    
}

void Square::draw() const
{
    //    GL_QUADS
    glBegin(GL_LINE_LOOP);
    glVertex2d(mLeft, mBottom);
    glVertex2d(mLeft + mSize, mBottom);
    glVertex2d(mLeft + mSize, mBottom + mSize);
    glVertex2d(mLeft, mBottom + mSize);
    glEnd();
}

bool Square::contains(double x, double y) const
{
    return (x >= mLeft && x <= mLeft + mSize) && (y >= mBottom && y <= mBottom + mSize);
}

void Square::adjust(double dx, double dy, double dsize)
{
    mLeft += dx;
    mBottom += dy;
    mSize += dsize;
}

double Square::getLeft() const
{
    return mLeft;
}

double Square::getBottom() const
{
    return mBottom;
}

double Square::getSize() const
{
    return mSize;
}
/*
Square::Square()
{
    
}

Square::Square(Point p1, Point p2)
:   mP1(p1),
mP2(p2)
{
    
}

void Square::setP1(Point p)
{
    mP1 = p;
}

void Square::setP2(Point p)
{
    mP2 = p;
}

Point Square::getP1()
{
    return mP1;
}

Point Square::getP2()
{
    return mP2;
}

double Square::getLeft()
{
    return mP1.getX();
}

double Square::getBottom()
{
    return mP2.getY();
}

double Square::getWidth()
{
    return mP2.getX() - mP1.getX();
}

double Square::getHeight()
{
    return mP1.getY() - mP2.getY();
}

void Square::draw()
{
    glColor3d(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP1.getX(), mP2.getY());
    glEnd();
}
*/