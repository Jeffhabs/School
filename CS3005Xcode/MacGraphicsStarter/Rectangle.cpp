//
//  Rectangle.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//


#include "Rectangle.hpp"
#include <vector>
//rectangle

Rectangle::Rectangle(std::vector<Points *> points,
                     const double r,
                     const double g,
                     const double b,
                     bool filled)
:Shape(points, r, g, b, filled)
{
    if(mVertices.size() == 2)
    {
        mVertices.push_back(new Points(mVertices[0]->getX(), mVertices[1]->getY()));
        mVertices.push_back(new Points(mVertices[1]->getX(), mVertices[0]->getY()));
    }
    
   ///cuz this is dope tertionary
    mLeft = mVertices[0]->getX() < mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX();
    mRight = mVertices[0]->getX() > mVertices[1]->getX() ? mVertices[0]->getX() : mVertices[1]->getX();
    mTop = mVertices[0]->getY() > mVertices[1]->getY() ? mVertices[0]->getY() : mVertices[1]->getY();
    mBottom = mVertices[0]->getY() < mVertices[1]->getY() ? mVertices[0]->getY() : mVertices[1]->getY();
    
    mShapeType = RECTANGLE;
}

void Rectangle::Draw()
{
    if(mFilled)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    
    glColor3d(mRed, mGreen, mBlue);
    DrawRectangle(mLeft, mTop, mRight, mBottom);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    DrawPoints();
    
}

bool Rectangle::Contains(double x, double y) const
{
    return x > mLeft && x < mRight && y < mTop && y > mBottom;
}