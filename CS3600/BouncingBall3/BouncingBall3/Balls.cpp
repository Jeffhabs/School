//
//  Balls.cpp
//  BouncingBall3
//
//  Created by Jeffrey Haberle on 1/25/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include "Balls.hpp"

Balls::Balls()
{
    _screenX = 1000;
    _screenY = 800;
}

std::vector<Circle *> Balls::getCircles()
{
    return _circles;
}

void Balls::addCircle(Circle *circle)
{
    _circles.push_back(circle);
}

double Balls::getScreenX()
{
    return _screenX;
}

double Balls::getScreenY()
{
    return _screenY;
}

void Balls::setScreenX(double screenX)
{
    _screenX = screenX;
}

void Balls::setScreenY(double screenY)
{
    _screenY = screenY;
}