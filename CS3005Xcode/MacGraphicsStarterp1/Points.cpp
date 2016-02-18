//
//  Points.cpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#include "Points.hpp"
#include "Shape.hpp"

Points::Points(const double x, const double y)
{
    mX = x;
    mY = y;
}

//draws the little dots on the screen when the user clicks
void Points::Draw()
{
    glColor3d(DEFAULT_POINT_RED, DEFAULT_POINT_GREEN, DEFAULT_POINT_BLUE);
    DrawCircle(mX, mY, POINT_RADIUS);
}

bool Points::Contains(double x, double y) const
{
    double distance = sqrt((x-mX) * (x - mX) + (y - mY) * (y - mY));
    
    return distance < POINT_RADIUS;
}