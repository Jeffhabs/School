//
//  Triangle.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//
#include <vector>
#include "Triangle.hpp"

//triangle
Triangle::Triangle(std::vector<Points*> points,
                   const double r,
                   const double g,
                   const double b,
                   bool filled)
: Shape(points, r, g, b, filled)
{
    /*
    if (mVertices.size() != 3)
        std::cerr << "Error: "
        << mVertices.size()
        << " vertices passed to Triangle constructor."
        << std::endl;
    */
    mShapeType = TRIANGLE;
}

void Triangle::Draw()
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
    DrawTriangle(mVertices[0]->getX(), mVertices[0]->getY(),
                 mVertices[1]->getX(), mVertices[1]->getY(),
                 mVertices[2]->getX(), mVertices[2]->getY());
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    DrawPoints();
}

