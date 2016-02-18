//
//  Shape.cpp
//  Shapes
//
//  Created by Jeffrey Haberle on 10/28/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Slider.hpp"
#include "Pentagon.hpp"

#include <cmath>
#include <vector>
#ifdef _WIN32
    #include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

Shape::Shape(std::vector<Points *> points,
             const double r,
             const double g,
             const double b,
             bool filled)
{
    std::vector<Points *>::iterator i;
    for(i = points.begin(); i < points.end(); ++i)
    {
        mVertices.push_back(*i);
    }
    
    setColor(r, g, b);
    mShapeType = NONE;
    mFilled = filled;
    mSelected = true;
}

Shape::~Shape()
{
    mVertices.clear();
}

void Shape::DrawPoints()
{
   if(!mSelected)
   {
       return;
   }
    
    std::vector<Points *>::iterator i;
    for(i = mVertices.begin(); i < mVertices.end(); i++)
    {
        (*i)->Draw();
    }
}
//void Shape::Adjust
//void Shape::Move

void Shape::setColor(double r, double g, double b)
{
    mRed = r;
    mGreen = g;
    mBlue = b;
}
/*
Line::Line(std::vector<Points *> points,
           const double r,
           const double g,
           const double b)
:Shape(points, r, g, b, false)
{
   if(mVertices.size() != 2)
   {
       
   }
    mShapeType = LINE;
}
void Line::Draw()
{
    glColor3d(mRed, mGreen, mBlue);
    glBegin(GL_LINES);
    glVertex2d(mVertices[0]->getX(), mVertices[0]->getY());
    glVertex2d(mVertices[1]->getY(), mVertices[1]->getY());
    glEnd();
    
    DrawPoints();
}
*/










// Button methods:






