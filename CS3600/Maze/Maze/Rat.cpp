//
//  Rat.cpp
//  Maze
//
//  Created by Nate Armstrong on 2/6/14.
//  Copyright (c) 2014 Nate Armstrong. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <GLUT/GLUT.h>

#include "Rat.h"

void DrawRectangle(double x1, double y1, double x2, double y2)
{
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x2,y1);
    glVertex2d(x2,y2);
    glVertex2d(x1,y2);
    glEnd();
}

Maze* Rat::getMaze()
{
    return maze;
}

double Rat::getX()
{
    return x;
}

double Rat::getY()
{
    return y;
}

double Rat::getDegrees()
{
    return degrees;
}

void Rat::setX(double x)
{
    this->x = x;
}

void Rat::setY(double y)
{
    this->y = y;
}

void Rat::setDegrees(double degrees)
{
    this->degrees = degrees;
}

void Rat::setMaze(Maze *maze)
{
    this->maze = maze;
}

// END GETTERS AND SETTERS //

Rat::Rat()
{
    x = y = .5;
    degrees = 0;
}

void Rat::draw(double invisible)
{
    glPushMatrix(); // the following changes should happen to a copy.
    
    glTranslated(x, y, 0); // translate to its actual position.
    glRotated(degrees, 0, 0, 1); // `degrees` will be the `direction` if it is stored in degrees.
    glScaled(.5, .5, 1); // have a variable that is the scale of the rat.
    glTranslated(-x, -y, 0);
    if (invisible) { glColor3ub(255, 255, 255); }
    
    glBegin(GL_POLYGON); // draw the rat
    DrawRectangle(x - .5, y - .5, x + .5, y + .5);
    glEnd();
    
    glPopMatrix();
}

void Rat::move(double dt)
{
    double rad = degrees/180.0 * M_PI;
    double dx = cos(rad) * MOVE_SPEED * dt;
    double dy = sin(rad) * MOVE_SPEED * dt;
    double r = .25;
    if (maze->isLegal(x + dx, y + dy, r))
    {
        x += dx;
        y += dy;
    }
    else if (maze->isLegal(x+dx, y, r))
    {
        x += dx;
    }
    else if (maze->isLegal(x, y+dy, r))
    {
        y += dy;
    }
}

void Rat::spinLeft(double dt)
{
    degrees += SPIN_SPEED * dt * 360;
}

void Rat::spinRight(double dt)
{
    degrees -= SPIN_SPEED * dt * 360;
}