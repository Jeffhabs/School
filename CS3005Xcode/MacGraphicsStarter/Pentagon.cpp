//
//  Pentagon.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 12/14/15.
//
//

#include "Pentagon.hpp"

Pentagon::Pentagon(std::vector<Points *> points,
                   const double r,
                   const double g,
                   const double b,
                   bool filled)
: Shape(points, r, g, b, filled)
{
    
    mShapeType = PENTAGON;
}

void Pentagon::Draw()
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
    glBegin(GL_POLYGON);
    glVertex2d(mVertices[0]->getX(), mVertices[0]->getY());
    glVertex2d(mVertices[1]->getX(), mVertices[1]->getY());
    glVertex2d(mVertices[2]->getX(), mVertices[2]->getY());
    glVertex2d(mVertices[3]->getX(), mVertices[3]->getY());
    glVertex2d(mVertices[4]->getX(), mVertices[4]->getY());
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    DrawPoints();
}