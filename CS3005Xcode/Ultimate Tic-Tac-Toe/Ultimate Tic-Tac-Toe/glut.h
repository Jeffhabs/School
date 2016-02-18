//
//  glut.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/9/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef glut_h
#define glut_h

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

#endif /* glut_h */
