// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <GLUT/glut.h>
#include <vector>
#include <math.h>

#include "Circle.hpp"
#include "Balls.hpp"


// Global Variables (Only what you need!)

double kNumCircles = 0;

double gDX = .2;
double gDY = .2;

double gDXRange = .05;
double gDYRange = .05;

double gRadius = 30;
double gRadiusRange = 20;

int gNumSides = 6;

Balls *BALLS;

bool circlesDoCollide(double x1, double y1, double r1, double x2, double y2, double r2)
{
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return d < r1 + r2;
}

//
// Functions that draw basic primitives
//
void DrawRectangle(double x1, double y1, double x2, double y2)
{
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x2,y1);
    glVertex2d(x2,y2);
    glVertex2d(x1,y2);
    glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3,y3);
    glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, char *string)
{
    void *font = GLUT_BITMAP_9_BY_15;
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    int len, i;
    glRasterPos2d(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
    
    glDisable(GL_BLEND);
}

void drawShape() {
    double radius = 300;
    double x1 = 500;
    double y1 = 400;
    glBegin(GL_POLYGON);
    for(int i=0; i<gNumSides; i++)
    {
        double theta = (double)i/gNumSides * 2.0 * 3.1415926;
        double x = x1 + radius * cos(theta);
        double y = y1 + radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawShape();
    
        for (int i=0; i<BALLS->getCircles().size(); i++)
        {
            Circle *circle = BALLS->getCircles()[i];
            circle->update(i, BALLS->getScreenX(), BALLS->getScreenY(), BALLS->getCircles());
            circle->draw();
            /*
             circle.update()
                dy -= gravity
                dy *= AIR_FRICTION which is .999
                dx *= AIR_FRICTION
    
               wall collisions
               ball-ball collisions
               update position
                    x += dx
                    y += dy
             circle.draw()
            */
        }
    
    glutSwapBuffers();
    glutPostRedisplay();
}

double randomNumberInRange(double min, double max)
{
    return min + (rand() % (int)(max - min + 1));
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    std::cout << c << std::endl;
    switch (c)
    {
        case '3':
            gNumSides = 3;
            break;
        case '4':
            gNumSides = 4;
            break;
        case '5':
            gNumSides = 5;
            break;
        case '6':
            gNumSides = 6;
            break;
        case '7':
            gNumSides = 7;
            break;
        case '8':
            gNumSides = 8;
            break;
        case '9':
            gNumSides = 9;
            break;
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
    BALLS->setScreenX(w);
    BALLS->setScreenY(h);
    
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
        double radius, dx, dy, r, g, b;
        bool isRed;
        radius = randomNumberInRange(gRadius - gRadiusRange, gRadius + gRadiusRange);
        dx = randomNumberInRange(gDX - gDXRange, gDX + gDXRange);
        dy = randomNumberInRange(gDY - gDYRange, gDY + gDYRange);
        r = randomNumberInRange(0, 255);
        g = randomNumberInRange(0, 255);
        b = randomNumberInRange(0, 255);
        isRed = false;
        BALLS->addCircle(new Circle(x, BALLS->getScreenY() - y, radius, dx, dy, r, g, b, isRed));
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
    std::srand((unsigned)time(NULL) );
    for (int i=0; i<kNumCircles; i++)
    {
        double x, y, radius, dx, dy, r, g, b;
        radius = randomNumberInRange(gRadius - gRadiusRange, gRadius + gRadiusRange);
        bool placeFound = false;
        while (i>0 && !placeFound)
        {
            x = randomNumberInRange(0 + radius, BALLS->getScreenX() - radius);
            y = randomNumberInRange(0 + radius, BALLS->getScreenY() - radius);
            bool collision = false;
            for (int j=0; j<i; j++)
            {
                Circle *circle = BALLS->getCircles()[j];
                if (circlesDoCollide(x, y, radius, circle->getx(), circle->gety(), circle->getradius()))
                {
                    collision = true;
                    break;
                }
            }
            if (!collision)
            {
                placeFound = true;
            }
            
        }
        if (i < 1)
        {
            x = randomNumberInRange(0 + radius, BALLS->getScreenX() - radius);
            y = randomNumberInRange(0 + radius, BALLS->getScreenY() - radius);
        }
        dx = randomNumberInRange(gDX - gDXRange, gDX + gDXRange);
        dy = randomNumberInRange(gDY - gDYRange, gDY + gDYRange);
                r = randomNumberInRange(0, 255);
                g = randomNumberInRange(0, 255);
                b = randomNumberInRange(0, 255);
        //g = 0;
        //b = 255;
        //r = 0;
        bool isRed = false;
        if (i < 5)
        {
            isRed = true;
            r = 255;
            b = 0;
        }
        BALLS->addCircle(new Circle(x, y, radius, dx, dy, r, g, b, isRed));
    }
}


int main(int argc, char **argv)
{
    BALLS = new Balls();
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(BALLS->getScreenX(), BALLS->getScreenY());
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
