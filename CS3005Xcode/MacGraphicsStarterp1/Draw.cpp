//
//  Draw.cpp
//  Shapes
//
//  Created by Jeffrey Haberle on 10/28/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//

#include "Draw.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Button.hpp"
#include "Label.hpp"

#include <cmath>
#include <cstring>
#include <cstdlib>
#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

double gScreenX          = 900;
double gScreenY          = 600;
bool gLeftDragging       = false;
//bool gRightDragging      = false;
//bool gPressingShift      = false;
Points* gSelectedPoint = NULL;
Shape * gSelectedShape   = NULL;

std::vector<Points*> gPoints;
std::vector<Shape *> gShapes;
std::vector<Button *> gButtons;
std::vector<Label *> gLabels;
ShapeType gShapeMode;

double gRed, gGreen, gBlue;
bool gFilled;

void DrawRectangle(double x1, double y1, double x2, double y2)
{
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glVertex2d(x1, y2);
    glEnd();
}

void DrawTriangle(double x1, double y1,
                  double x2, double y2,
                  double x3, double y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3,y3);
    glEnd();
}

void DrawCircle(double x1, double y1, double radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < CURVE; i++)
    {
        double theta = (double) i / CURVE* 2.0 * PI;
        double x = x1 + radius * cos(theta);
        double y = y1 + radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}

void DrawText(double x, double y, char * string)
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

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw all user-created shapes:
    std::vector<Shape *>::iterator shapeI;
    for (shapeI = gShapes.begin(); shapeI < gShapes.end(); shapeI++)
    {
        (*shapeI)->Draw();
    }
    
    // Draw all user-created points that are not yet part of a shape:
    std::vector<Points*>::iterator pointI;
    for (pointI= gPoints.begin(); pointI< gPoints.end(); pointI++)
    {
        (*pointI)->Draw();
    }
   
    // Draw the control panel on the left side of the screen:
    glColor3d(PANEL_RED, PANEL_GREEN, PANEL_BLUE);
    DrawRectangle(0, 0, PANEL_WIDTH, gScreenY);
    
    std::vector<Label *>::iterator labelI;
    for (labelI= gLabels.begin(); labelI< gLabels.end(); labelI++)
    {
        (*labelI)->Draw();
    }
    std::vector<Button *>::iterator buttonI;
    for (buttonI= gButtons.begin();
         buttonI< gButtons.end();
         buttonI++)
    {
        (*buttonI)->Draw();
    }
    
    glutSwapBuffers();
}

void keyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 'q':
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

void reshape(int w, int h)
{
    // Reset our global variables to the new width and height:
    gScreenX = w;
    gScreenY = h;
    
    // Set the pixel resolution of the final picture (screen coordinates):
    glViewport(0, 0, w, h);
    
    // Set the projection mode to 2D orthographic, and set the world coordinates:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}


void mouse(int mouse_button, int state, int x, int y)
{
    y = gScreenY - y;
    
    // Left mouse button:
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Left-clicking within the canvas:
        if (x > PANEL_WIDTH)
        {
            
            // If not already dragging and a point's clicked, select it for dragging:
            if (!gLeftDragging)
            {
                std::vector<Points*>::iterator pointI;
                for (pointI= gPoints.begin();
                     pointI< gPoints.end();
                     pointI++)
                {
                    if ((*pointI)->Contains(x, y))
                    {
                        gSelectedPoint = (*pointI);
                        gLeftDragging = true;
                        break;
                    }
                }
                if (!gLeftDragging)
                {
                    std::vector<Shape *>::iterator shapeIter;
                    for (shapeIter = gShapes.begin();
                         shapeIter < gShapes.end();
                         ++shapeIter)
                    {
                        for (int i = 0; i < (*shapeIter)->numPoints(); ++i)
                        {
                            if ((*shapeIter)->getPoint(i)->Contains(x, y))
                            {
                                gSelectedPoint = (*shapeIter)->getPoint(i);
                                DeselectAllShapes();
                                gSelectedShape = (*shapeIter);
                                gSelectedShape->setSelected(true);
                                gLeftDragging = true;
                                break;
                            }
                        }
                        if (gLeftDragging)
                            break;
                    }
                }
            }
            
            // If a point wasn't clicked, a new point should be created:
            if (!gLeftDragging)
            {
                if (gPoints.empty())
                {
                    DeselectAllShapes();
                }
                gPoints.push_back(new Points(x, y));
               
                switch(gShapeMode)
                {
                    /*
                    case LINE:
                        if (gPoints.size() >= 2)
                        {
                            DeselectAllShapes();
                            gShapes.push_back(new Line(gPoints, gRed, gGreen, gBlue));
                            gPoints.clear();
                        }
                        break;
                    */
                    case RECTANGLE:
                        if (gPoints.size() >= 2)
                        {
                            DeselectAllShapes();
                            gShapes.push_back(new Rectangle(gPoints,
                                                            gRed,
                                                            gGreen,
                                                            gBlue,
                                                            gFilled));
                            gPoints.clear();
                        }
                        break;
                        
                    case TRIANGLE:
                        if (gPoints.size() >= 3)
                        {
                            DeselectAllShapes();
                            gShapes.push_back(new Triangle(gPoints,
                                                           gRed,
                                                           gGreen,
                                                           gBlue,
                                                           gFilled));
                            gPoints.clear();
                        }
                        break;
                        
                    case CIRCLE:
                        if (gPoints.size() >= 2)
                        {
                            DeselectAllShapes();
                            gShapes.push_back(new Circle(gPoints,
                                                         gRed,
                                                         gGreen,
                                                         gBlue,
                                                         gFilled));
                            gPoints.clear();
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        
        // Left-clicking within the control panel:
        else
        {
            std::vector<Button *>::iterator buttonIter;
            for (buttonIter = gButtons.begin();
                 buttonIter < gButtons.end();
                 ++buttonIter)
            {
                if ((*buttonIter)->Contains(x, y))
                {
                    (*buttonIter)->setPressed(true);
                    if ((*buttonIter)->isButtonType(MODE_BUTTON))
                    {
                        setShapeDisplay((ShapeType) (*buttonIter)->getButtonID());
                    }
                    /*
                    else if ((*buttonIter)->isButtonType(FILL_BUTTON))
                    {
                        setFilled(true);
                    }
                    */
                    else if ((*buttonIter)->isButtonType(OUTLINE_BUTTON))
                    {
                        setFilled(false);
                    }
                    /*
                    else if ((*buttonIter)->isButtonType(COLOR_BUTTON))
                    {
                        setColor((*buttonIter)->getRed(),
                                 (*buttonIter)->getGreen(),
                                 (*buttonIter)->getBlue());
                    }
                    
                    else if ((*buttonIter)->isButtonType(UNDO_BUTTON))
                    {
                        if (!gPoints.empty())
                        {
                            gPoints.pop_back();
                        }
                        else if (!gShapes.empty())
                        {
                            gShapes.pop_back();
                        }
                    }
                    else if ((*buttonIter)->isButtonType(CLEAR_BUTTON))
                    {
                        gShapes.clear();
                        gPoints.clear();
                    }
                    else if ((*buttonIter)->isButtonType(QUIT_BUTTON))
                    {
                        exit(0);
                    }
                    break;
                    */
                }
            }
        }
    }
    
    // When left button is released, ensure no point is selected for dragging:
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        gLeftDragging  = false;
        gSelectedPoint = NULL;
        
        std::vector<Button *>::iterator iter;
        for (iter = gButtons.begin(); iter < gButtons.end(); ++iter)
        {
            if ((*iter)->isPressed())
            {
                (*iter)->setPressed(false);
            }
        }
    }
    /*
    // Right mouse button:
    if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // Right-clicking within the canvas:
        if (x > PANEL_WIDTH)
        {
            // If not dragging and a point's been clicked, select it for dragging:
            if (!gRightDragging)
            {
                std::vector<Points*>::iterator pointIter;
                for (pointIter = gPoints.begin();
                     pointIter < gPoints.end();
                     ++pointIter)
                {
                    if ((*pointIter)->Contains(x, y))
                    {
                        gSelectedPoint = (*pointIter);
                        gRightDragging = true;
                        break;
                    }
                }
                if (!gRightDragging)
                {
                    std::vector<Shape *>::iterator shapeIter;
                    for (shapeIter = gShapes.begin();
                         shapeIter < gShapes.end();
                         ++shapeIter)
                    {
                        for (int i = 0; i < (*shapeIter)->numPoints(); ++i)
                        {
                            if ((*shapeIter)->getPoint(i)->Contains(x, y))
                            {
                                gSelectedPoint = (*shapeIter)->getPoint(i);
                                DeselectAllShapes();
                                gSelectedShape = (*shapeIter);
                                gSelectedShape->setSelected(true);
                                gRightDragging = true;
                                break;
                            }
                        }
                        if (gRightDragging)
                            break;
                    }
                }
            }
        }
     
    }
    */
   
    /*
    // When right button is released, ensure no point is selected for dragging:
    if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        gRightDragging = false;
        gSelectedPoint = NULL;
        
        std::vector<Button *>::iterator iter;
        for (iter = gButtons.begin(); iter < gButtons.end(); ++iter)
        {
            if ((*iter)->isPressed())
            {
                (*iter)->setPressed(false);
            }
        }
    }
    */
    
    // Middle mouse button:
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
    {
    }
    
    glutPostRedisplay();
}
/*
void motion(int x, int y)
{
    y = gScreenY - y;
    
    if (gRightDragging)
    {
        if (gSelectedShape)
        {
            if (gSelectedPoint)
            {
                gSelectedShape->Adjust(x, y, gSelectedPoint);
            }
        }
        else if (gSelectedPoint)
        {
            gSelectedPoint->setX(x);
            gSelectedPoint->setY(y);
        }
    }
    else if (gLeftDragging)
    {
        if (gSelectedShape)
        {
            gSelectedShape->Move(x, y, gSelectedPoint);
        }
        else if (gSelectedPoint)
        {
            gSelectedPoint->setX(x);
            gSelectedPoint->setY(y);
        }
    }
    
    glutPostRedisplay();
}
*/

void AddButton(const double x1,
               const double y1,
               const double x2,
               const double y2,
               const double r,
               const double g,
               const double b,
               const char * text,
               const int buttonType,
               const int associatedID)
{
    gPoints.clear();
    gPoints.push_back(new Points(x1, y1));
    gPoints.push_back(new Points(x2, y2));
    gButtons.push_back(new Button(gPoints, r, g, b, text, buttonType, associatedID));
    gPoints.clear();
    
}

void AddLabel(const double x1,
              const double y1,
              const double x2,
              const double y2,
              const double r,
              const double g,
              const double b,
              const char * text)
{
    gPoints.clear();
    gPoints.push_back(new Points(x1, y1));
    gPoints.push_back(new Points(x2, y2));
    gLabels.push_back(new Label(gPoints, r, g, b, text));
    gPoints.clear();
}


void InitializeMyStuff()
{
    int n = 1;
    
    gShapes.clear();
    gPoints.clear();
    gButtons.clear();
    gLabels.clear();
    gRed   = INITIAL_RED;
    gGreen = INITIAL_GREEN;
    gBlue  = INITIAL_BLUE;
    
    AddButton(INITIAL_BUTTON_X,
              gScreenY - n * INITIAL_BUTTON_Y-
              (n - 1) * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_X + INITIAL_BUTTON_WIDTH,
              gScreenY - n * INITIAL_BUTTON_Y -
              n * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_RED,
              INITIAL_BUTTON_GREEN,
              INITIAL_BUTTON_BLUE,
              "Rectangle",
              MODE_BUTTON,
              RECTANGLE);
    n++;
    
    AddButton(INITIAL_BUTTON_X,
              gScreenY - n * INITIAL_BUTTON_Y -
              (n - 1) * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_X + INITIAL_BUTTON_WIDTH,
              gScreenY - n * INITIAL_BUTTON_Y -
              n * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_RED,
              INITIAL_BUTTON_GREEN,
              INITIAL_BUTTON_BLUE,
              "Triangle",
              MODE_BUTTON,
              TRIANGLE);
    n++;
    
    AddButton(INITIAL_BUTTON_X,
              gScreenY - n * INITIAL_BUTTON_Y -
              (n - 1) * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_X + INITIAL_BUTTON_WIDTH,
              gScreenY - n * INITIAL_BUTTON_Y -
              n * INITIAL_BUTTON_HEIGHT,
              INITIAL_BUTTON_RED,
              INITIAL_BUTTON_GREEN,
              INITIAL_BUTTON_BLUE,
              "Circle",
              MODE_BUTTON,
              CIRCLE);
    ++n;
    
    
    setShapeDisplay(INITIAL_MODE);
    setColor(INITIAL_RED, INITIAL_GREEN, INITIAL_BLUE);
    setFilled(true);

}

void setFilled(bool b)
{
    gFilled = b;
    
    std::vector<Button *>::iterator iter;
    for (iter = gButtons.begin(); iter < gButtons.end(); ++iter)
    {
        if ((*iter)->isButtonType(FILL_BUTTON))
        {
            if (gFilled)
                (*iter)->setSelected(true);
            else
                (*iter)->setSelected(false);
        }
        else if ((*iter)->isButtonType(OUTLINE_BUTTON))
        {
            if (!gFilled)
                (*iter)->setSelected(true);
            else
                (*iter)->setSelected(false);
        }
    }
}

void setColor(double r, double g, double b)
{
    gRed   = r;
    gGreen = g;
    gBlue  = b;
    
    std::vector<Button *>::iterator iter;
    for (iter = gButtons.begin(); iter < gButtons.end(); ++iter)
    {
        if ((*iter)->isButtonType(CLEAR_BUTTON))
        {
            if ((*iter)->getRed()   == r &&
                (*iter)->getGreen() == g &&
                (*iter)->getBlue()  == b)
            {
                (*iter)->setSelected(true);
            }
            else
            {
                (*iter)->setSelected(false);
            }
        }
    }
    
    if (gSelectedShape)
    {
        gSelectedShape->setColor(r, g, b);
    }
}

ShapeType setShapeDisplay(ShapeType m)
{
    gShapeMode = m;
    gPoints.clear();
    
    std::vector<Button *>::iterator iter;
    for (iter = gButtons.begin(); iter < gButtons.end(); ++iter)
    {
        if ((*iter)->isButtonType(MODE_BUTTON))
        {
            if ((*iter)->getButtonID() == gShapeMode)
            {
                (*iter)->setSelected(true);
            }
            else
            {
                (*iter)->setSelected(false);
            }
        }
    }
    
    return gShapeMode;
}

void DeselectAllShapes()
{
    std::vector<Shape *>::iterator iter;
    for (iter = gShapes.begin(); iter < gShapes.end(); ++iter)
    {
        (*iter)->setSelected(false);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(gScreenX, gScreenY);
    glutInitWindowPosition(50, 50);
    
    bool fullscreen = false;
    if (fullscreen)
    {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    }
    else
    {
        glutCreateWindow("Shapes");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    // Background color:
    glClearColor(1, 1, 1, 0);
    
    InitializeMyStuff();
    
    glutMainLoop();
    
    return 0;
}