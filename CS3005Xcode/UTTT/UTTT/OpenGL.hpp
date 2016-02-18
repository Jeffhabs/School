//
//  OpenGL.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef OpenGL_hpp
#define OpenGL_hpp

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

#include "Game.hpp"

void save();
void load();
void undo();
void redo();
void clear();

void drawText(double x, double y, const char *string);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();

/*
#include <stdio.h>
#include "Headers.h"
#include "Grid.hpp"
#include "Square.hpp"


void undo();
void redo();
void save();
void load();
void clear();

void createBoard();

void playerTurn(int x, int y);
void checkWin();
void drawBoard();
void drawText(double x, double y, const char *string);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();
*/

#endif /* OpenGL_hpp */
