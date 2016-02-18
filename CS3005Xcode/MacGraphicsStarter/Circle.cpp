//
//  Circle.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#include <vector>
#include "Circle.hpp"

//circle
Circle::Circle(std::vector<Points*> points,
               double r,
               double g,
               double b,
               bool filled)
: Shape(points, r, g, b, filled)
{
    if (mVertices.size() != 2)
    {
    }
    else
    {
        // Use the second vertex to determine the radius:
        mRadius = sqrt((mVertices[0]->getX() - mVertices[1]->getX()) *
                       (mVertices[0]->getX() - mVertices[1]->getX()) +
                       (mVertices[0]->getY() - mVertices[1]->getY()) *
                       (mVertices[0]->getY() - mVertices[1]->getY()));
    }
    
    mShapeType = CIRCLE;
}

void Circle::Draw()
{
    if (mFilled)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    glColor3d(mRed, mGreen, mBlue);
    DrawCircle(mVertices[0]->getX(), mVertices[0]->getY(), mRadius);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    DrawPoints();
}