//
//  main.cpp
//  BouncingBall
//
//  Created by Jeffrey Haberle on 1/19/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <GLUT/glut.h>
#include <vector>

#include "Circle.hpp"

//Global variables
double screen_x = 700;
double screen_y = 500;

std::vector<Circle *> gAllCircles;

double numCircles = 10;

double gX = 200;
double gY = 200;

double gXRange = 100;
double gYRange = 100;


double gDX = 5;
double gDY = 5;

double gDXRange = 2;
double gDYRange = 2;

double gRadius = 50;
double gRadiusRange = 25;


void DrawCircle(double x1, double y1, double radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 32; i++)
    {
        double theta = (double)i/32.0 * 2.0 * 3.1415926;
        double x = x1 + radius * cos(theta);
        double y = y1 + radius * sin(theta);
        
        glVertex2d(x, y);
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i = 0; i<gAllCircles.size(); i++)
    {
        Circle *circle = gAllCircles[i];
        glColor3b(circle->red, circle->green, circle->blue);
        DrawCircle(circle->x, circle->y, circle->radius);
        circle->x += circle->dX;
        circle->y += circle->dY;
        
        if(circle->y - circle->radius <= 0 || circle->y + circle->radius > screen_y)
        {
            circle->dY = -circle->dY;
        }
        if(circle->x - circle->radius <= 0 || circle->x + circle->radius > screen_x)
        {
            circle->dX = -circle->dX;
        }
    }
    
    glutSwapBuffers();
    glutPostRedisplay();
}

double randomNumber(double min, double max)
{
    return min + (rand() % (int)(max - min + 1));
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 27: // escape character means to quit the program
            exit(0);
            break;
        case 'b':
            // do something when 'b' character is hit.
            break;
        default:
            return; // if we don't care, return without glutPostRedisplay()
    }
    
    glutPostRedisplay();
}

// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
    // Reset our global variables to the new width and height.
    screen_x = w;
    screen_y = h;
    
    // Set the pixel resolution of the final picture (Screen coordinates).
    glViewport(0, 0, w, h);
    
    // Set the projection mode to 2D orthographic, and set the world coordinates:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    }
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
    {
    }
    glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
    std::srand( (unsigned)time(NULL));
    for(int i = 0; i < numCircles; i++)
    {
        double x, y, radius, dx, dy, r, g, b;
        x = randomNumber(gX - gXRange, gX + gXRange);
        y = randomNumber(gY - gYRange, gY + gYRange);
        radius = randomNumber(gRadius - gRadiusRange, gRadius + gRadiusRange);
        dx = randomNumber(gDX - gDXRange, gDX + gDXRange);
        dy = randomNumber(gDY - gDYRange, gDY + gDYRange);
        r = randomNumber(0, 255);
        g = randomNumber(0, 255);
        b = randomNumber(0, 255);
        gAllCircles.push_back(new Circle(x, y, dx, dy, radius, r, g, b));
    }
   
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screen_x, screen_y); //screen_x and screen_y are global variables
    glutInitWindowPosition(50, 50);
    
    int fullscreen = 0;
    if (fullscreen)
    {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    }
    else
    {
        glutCreateWindow("This appears in the title bar");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    glColor3d(0,0,0); // forground color
    glClearColor(1, 1, 1, 0); // background color
    InitializeMyStuff();
    
    glutMainLoop();
    
    return 0;
}