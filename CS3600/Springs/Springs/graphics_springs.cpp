//
//  graphics_springs.cpp
//  Springs
//
//  Created by Jeffrey Haberle on 2/10/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#include "graphics.h"
#include "particle.h"
#include "forces.h"

#include <GLUT/GLUT.h>


// Global Variables
// Some colors you can use, or make your own and add them
// here and in graphics.h
GLdouble redMaterial[] = {0.7, 0.1, 0.2, 1.0};
GLdouble greenMaterial[] = {0.1, 0.7, 0.4, 1.0};
GLdouble brightGreenMaterial[] = {0.1, 0.9, 0.1, 1.0};
GLdouble blueMaterial[] = {0.1, 0.2, 0.7, 1.0};
GLdouble whiteMaterial[] = {1.0, 1.0, 1.0, 1.0};
GLdouble blackMaterial[] = {0.0, 0.0, 0.0, 1.0};

double screen_x = 900;
double screen_y = 700;

std::clock_t START;
double last_update;
double nParticles;
double springForceUpdateInterval = .0009;
double speedIncrease = 0;

// The particle system.
ParticleSystem PS;

//
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<32; i++)
    {
        double theta = (double)i/32.0 * 2.0 * 3.1415926;
        double x = x1 + radius * cos(theta);
        double y = y1 + radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}

void DrawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glEnd();
}

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
void text_output(double x, double y, char *string)
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

double randomNumberInRange(double min, double max)
{
    return min + (rand() % (int)(max - min + 1));
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    double duration;
    
    duration = ( std::clock() - START ) / (double) CLOCKS_PER_SEC;
    
    if ((duration - last_update) >= springForceUpdateInterval)
    {
        Particle *spider = PS.GetParticle(nParticles - 1);
        Particle *newParticle = new Particle(spider->GetPositionx(), spider->GetPositiony(), 0, 0, .5, true);
        PS.AddParticle(newParticle);
        if (PS.GetNumParticles() > nParticles + 1)
        {
            double color[] = {randomNumberInRange(0, 255)/255, randomNumberInRange(0, 255)/255, randomNumberInRange(0, 255)/255, 1};
            Force *f = new SpringForce(PS.GetParticle(PS.GetNumParticles() - 2), newParticle, 100, 100, 1, color);
            PS.AddForce(f);
        }
        last_update = duration;
    }
    
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3dv(whiteMaterial);
    
    double DeltaT = PS.GetDeltaT() + speedIncrease;
    speedIncrease += .005;
    //EulerStep(PS, DeltaT);
    //MidpointStep(PS, DeltaT);
    RungeKuttaStep(PS, DeltaT);
    
    int N = PS.GetNumParticles();
    int NF = PS.GetNumForces();
    
    // Check Resulting particles for wall collisions
    for(i=0; i<N; i++)
    {
        Particle * p = PS.GetParticle(i);
        double radius = p->GetRadius();
        double x = p->GetPositionx();
        double y = p->GetPositiony();
        double xDir = p->GetDirectionx();
        double yDir = p->GetDirectiony();
        
        // bounce off left wall
        if(x - radius < 0)
        {
            p->SetPositionx(radius);
            p->SetDirectionx(fabs(xDir));
        }
        
        // bounce off right wall
        if(x + radius > screen_x)
        {
            p->SetPositionx(screen_x - radius);
            p->SetDirectionx(-fabs(xDir));
        }
        
        // bounce off bottom wall
        if(y - radius < 0)
        {
            p->SetPositiony(radius);
            p->SetDirectiony(fabs(yDir));
        }
        
        // bounce off top wall
        if(y + radius > screen_y)
        {
            p->SetPositiony(screen_y - radius);
            p->SetDirectiony(-fabs(yDir));
        }
    }
    
    
    // Draw Spring Forces as edges
    for(i=0; i<NF; i++)
    {
        Force * f = PS.GetForce(i);
        if(f->Type() == SPRING_FORCE)
        {
            SpringForce * sf = (SpringForce*)f;
            Particle * p1 = sf->GetParticle1();
            Particle * p2 = sf->GetParticle2();
            GLdouble color[] = {sf->GetRed(), sf->GetGreen(), sf->GetBlue(), 1.0};
            glColor3dv(color);
            DrawLine(p1->GetPositionx(), p1->GetPositiony(),  p2->GetPositionx(), p2->GetPositiony());
        }
    }
    
    // Draw Particles
    for(i=0; i<N; i++)
    {
        Particle * p = PS.GetParticle(i);
        double radius = p->GetRadius();
        
        double thePos[DIM];
        p->GetPosition(thePos);
        if(p->GetAnchored())
            glColor3dv(whiteMaterial);
        else
            glColor3dv(whiteMaterial);
        DrawCircle(thePos[0], thePos[1], radius);
    }
    
    glutSwapBuffers();
    glutPostRedisplay();
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
    screen_x = w;
    screen_y = h;
    
    // Set the pixel resolution of the final picture (Screen coordinates).
    glViewport(0, 0, w, h);
    
    // go into 2D mode
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the world coordinates.
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

void InitParticles1()
{
    string klass;
    string file;
    cout << "Which file would you like to use? ";
    cin >> file;
    bool flower = file.compare("flower.txt") == 0;
    bool validFile = file.compare("flower.txt") == 0 || file.compare("diamonds.txt") == 0;
    if (!validFile) {
        flower = true;
        file = "flower.txt";
    }
    string path = "/Users/jeffreyhaberle/Desktop/" + file;
    nParticles = flower ? 2 : 1;
    ifstream fin(path.c_str());
    double x, y, xDir, yDir, r_temp, pIndex1, pIndex2,
    spring_constant, damping_constant, rest_length, friction_temp,
    g1, g2, deltaT, red, green, blue, alpha;
    string anchored_temp;
    vector<Particle *>particles;
    if (!fin)
    {
        cerr << "unable to open file" << endl;
        return;
    }
    while (!fin.eof())
    {
        fin >> klass;
        if (klass == "particle")
        {
            fin >> x >> y >> xDir >> yDir >> r_temp >> anchored_temp >> ws;
            bool at = anchored_temp.compare("false") != 0;
            cout << x << endl;
            Particle *p = new Particle(x, y, xDir, yDir, r_temp, at);
            PS.AddParticle(p);
            particles.push_back(p);
        }
        else if (klass == "springForce")
        {
            fin >> pIndex1 >> pIndex2 >> spring_constant >> damping_constant >> rest_length >> red >> green >> blue >> alpha >> ws;
            Particle *p1 = particles[pIndex1 - 1];
            Particle *p2 = particles[pIndex2 - 1];
            double color[4] = {red/255, green/255, blue/255, alpha};
            Force *f = new SpringForce(p1, p2, spring_constant, damping_constant, rest_length, color);
            PS.AddForce(f);
        }
        else if (klass == "dragForce")
        {
            fin >> friction_temp >> ws;
            Force *df = new DragForce(friction_temp, &PS);
            PS.AddForce(df);
        }
        else if (klass == "gravityForce")
        {
            fin >> g1 >> g2 >> ws;
            double gravity[DIM] = {g1, g2};
            Force *f = new GravityForce(gravity, &PS);
            PS.AddForce(f);
        }
        else if (klass == "deltaT")
        {
            fin >> deltaT >> ws;
            PS.SetDeltaT(deltaT);
        }
    }
    
}


// Your initialization code goes here.
void InitializeMyStuff()
{
    InitParticles1();
}


int main(int argc, char **argv)
{
    START = std::clock();
    last_update = 0;
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screen_x, screen_y);
    glutInitWindowPosition(50, 50);
    
    int fullscreen = 0;
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
    
    glClearColor(0,0,0,0);
    InitializeMyStuff();
    
    glutMainLoop();
    
    return 0;
}