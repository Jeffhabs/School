//
//  Draw.hpp
//  Shapes
//
//  Created by Jeffrey Haberle on 10/28/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
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
#pragma once

const int INPUT_LEN = 500;
const int FILLED = 0;
const int OUTLINE = 1;

enum ShapeType
{
    NONE,
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
    
};

const ShapeType INITIAL_MODE = NONE;

//inital color is lime-green
const double INITIAL_RED = 0.0;
const double INITIAL_GREEN = 1;
const double INITIAL_BLUE = 0.0;
const double PANEL_WIDTH = 190.0;
//color of panel is grey
const double PANEL_RED = .6;
const double PANEL_BLUE = .6;
const double PANEL_GREEN = .6;
const double INITIAL_BUTTON_X = 15.0;
const double INITIAL_BUTTON_Y = 2.0;
const double INITIAL_BUTTON_WIDTH = PANEL_WIDTH - (2 * INITIAL_BUTTON_X);
const double INITIAL_BUTTON_HEIGHT = 20.0;
const double INITIAL_BUTTON_RED = 0.9;
const double INITIAL_BUTTON_GREEN = 0.9;
const double INITIAL_BUTTON_BLUE = 0.9;
const double PI = atan(1.0) * 4.0;
const int CURVE = 32;

void DrawRectangle(double x1, double y1, double x2, double y2);
void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
void DrawCircle(double x1, double y1, double radius);
void DrawText(double x, double y, char * input);
void setColor(double r, double g, double b);

ShapeType setShapeDisplay(ShapeType d);
void setFilled(bool s);
void DeselectAllShapes();



