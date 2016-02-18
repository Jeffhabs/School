//
//  OpenGL.cpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "OpenGL.hpp"

#include "Headers.h"
#include "Grid.hpp"
#include "Square.hpp"
// Global Variables (Only what you need!)
double SCREEN_X = 700;
double SCREEN_Y = 700;
Game GAME(0, 0, SCREEN_Y);


void undo()
{
    
}
void redo()
{
    
}
void save()
{
}
void load()
{
    
}
void clear()
{
    
}

// Outputs a string of text at the specified location.
void drawText(double x, double y, const char *string)
{
    void *font = GLUT_BITMAP_9_BY_15;
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    int len, i;
    glRasterPos2d(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
    
    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    GAME.draw();
    
    glutSwapBuffers();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    switch (c) {
        case 'q':
        case 27: // escape character means to quit the program
            exit(0);
            break;
        case 'u':
            // Undo Turn
            undo();
            break;
        case 'r':
            // Redo last Turn
            redo();
            break;
        case 's':
            // Save game to file
            save();
            break;
        case 'l':
            // Load game from file
            load();
            break;
        case 'x':
            // Start new game
            clear();
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
    SCREEN_X = w;
    SCREEN_Y = h;
    
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
void mouse(int mouse_button, int state, int x, int y_inverted)
{
    // translate pixel coordinates to display coordinates
    int y = SCREEN_Y - y_inverted;
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (GAME.click(x, y)) {
            glutPostRedisplay();
        }
        
    }
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        
    }
    glutPostRedisplay();
}

// Your initialization code goes here.
void initMyStuff()
{
    
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutInitWindowPosition(450, 250);
    
    int fullscreen = 0;
    if (fullscreen) {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    } else {
        glutCreateWindow("This appears in the title bar");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    
    glClearColor(.8, .8, .8, 0); // background color
    initMyStuff();
    
    glutMainLoop();
    
    return 0;
}
/*
// Global Variables (Only what you need!)
double SCREEN_X = 700;
double SCREEN_Y = 500;
Grid *GRID = 0;
double GRID_THICKNESS = 5;
int GRID_SIZE = 3;
int TURN = 0;


void undo()
{
    
}

void redo()
{
    
}

void save()
{
    
}

void load()
{
    
}

void clear()
{
    
}

void drawBoard()
{
    GRID->draw();
}

void playerTurn(int x, int y)
{
    
}

void checkWin()
{
    
}

void createBoard()
{
    Point p1 = Point(0, SCREEN_Y);
    Point p2 = Point(SCREEN_X, 0);
    Square square = Square(p1, p2);
    GRID = new Grid(GRID_SIZE, square);
    if (!GRID) {
        std::cout << "Grid not initialized!" << std::endl;
    }
}

// Outputs a string of text at the specified location.
void drawText(double x, double y, const char *string)
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


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Test lines that draw all three shapes and some text.
    // Delete these when you get your code working.
    drawBoard();
    
    glColor3d(1, 1, 1);
    drawText(200, 10, "CS-3005 - Ultimate Tic-Tac-Toe");
    
    glutSwapBuffers();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 'q':
        case 27: // escape character means to quit the program
            exit(0);
            break;
        case 'u':
            // Undo Turn
            undo();
            break;
        case 'r':
            // Redo last Turn
            redo();
            break;
        case 's':
            // Save game to file
            save();
            break;
        case 'l':
            // Load game from file
            load();
            break;
        case 'x':
            // Start new game
            clear();
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
    SCREEN_X = w;
    SCREEN_Y = h;
    
    // Set the pixel resolution of the final picture (Screen coordinates).
    glViewport(0, 0, w, h);
    
    // Set the projection mode to 2D orthographic, and set the world coordinates:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    
    GRID->resize(w, h);
    
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y_inverted)
{
    // translate pixel coordinates to display coordinates
    int y = SCREEN_Y - y_inverted;
    
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        playerTurn(x, y);
        checkWin();
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
void initMyStuff()
{
    createBoard();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutInitWindowPosition(50, 50);
    
    int fullscreen = 0;
    if (fullscreen)
    {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    }
    else
    {
        glutCreateWindow("CS-3005 - Ultimate Tic-Tac-Toe");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    glColor3d(0,0,0); // forground color
    glClearColor(0, 0, 0, 0); // background color
    initMyStuff();
    
    glutMainLoop();
    
    return 0;
}
*/