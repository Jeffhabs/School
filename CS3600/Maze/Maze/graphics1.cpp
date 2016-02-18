//
//  graphics1.cpp
//  Maze
//
//  Created by Jeffrey Haberle on 1/28/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include <stdio.h>
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
#include <iostream>
#include "Rat.h"
#include "Tga.h"
#include <GLUT/GLUT.h>


// Global Variables (Only what you need!)
double screen_x = 1000;
double screen_y = 800;
bool gLeft, gMiddle, gRight, gFirstPerson;
double gRatHeight = 0.15;

// Textures
const int num_textures = 4;
GLuint texName[num_textures];

Maze gMaze;
Rat gRat;

double GetDeltaTime()
{
    static clock_t start_time = clock();
    static int current_frame = 0;
    clock_t current_time = clock();
    current_frame += 1;
    double total_time = double(current_time - start_time)/CLOCKS_PER_SEC;
    if (total_time == 0)
        total_time = .00001;
    double frames_per_second = (double)current_frame / total_time;
    double DT = 1.0 / frames_per_second;
    return DT;
}

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

//void DrawRectangle(double x1, double y1, double x2, double y2)
//{
//	glBegin(GL_QUADS);
//	glVertex2d(x1,y1);
//	glVertex2d(x2,y1);
//	glVertex2d(x2,y2);
//	glVertex2d(x1,y2);
//	glEnd();
//}

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


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    glLoadIdentity();
    double dt = GetDeltaTime();
    if (gFirstPerson)
    {
        double rad = gRat.getDegrees()/180.0 * M_PI;
        double dx = cos(rad) * MOVE_SPEED * dt;
        double dy = sin(rad) * MOVE_SPEED * dt;
        gluLookAt(gRat.getX(), gRat.getY(), gRatHeight, gRat.getX() + dx, gRat.getY() + dy, gRatHeight, 0, 0, 1);
        // when doing rat, calculate at point but z will stay.
    }
    else
    {
        gluLookAt(M*.5, -N*.5, 15, M*.5, N*.5, 0, 0, 0, 1); // 3 eye, 3 at point, 3 z-axis up
    }
    
    gMaze.draw();
    gRat.draw(gFirstPerson);
    
    if (gLeft) gRat.spinLeft(dt);
    if (gRight) gRat.spinRight(dt);
    if (gMiddle) gRat.move(dt);
    
    if (gFirstPerson)
    {
        gluPerspective(.02, (double)screen_x/screen_y, .0001, .0001);
    }
    else
    {
        gluPerspective(40, (double)screen_x/screen_y, N*.5, 3*(M+N));
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
            gRatHeight -= .02;
            if (gRatHeight < .15) {
                gRatHeight = .15;
            }
            break;
        case 'a':
            gRatHeight += .02;
            if (gRatHeight > 1) {
                gRatHeight = 1;
            }
            break;
        case 'd':
            gMiddle = !gMiddle;
            break;
        case '1':
            gFirstPerson = !gFirstPerson;
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
    //	gluOrtho2D(-.5, M+.5, -.5, N+.5);
    if (gFirstPerson)
    {
        gluPerspective(60, (double)w/h, .0001, M*N);
    }
    else
    {
        gluPerspective(40, (double)w/h, N*.5, 3*(M+N));
    }
    glMatrixMode(GL_MODELVIEW);
    
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        gLeft = true;
    }
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        gLeft = false;
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        gMiddle = true;
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
    {
        gMiddle = false;
    }
    if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        gRight = true;
    }
    if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        gRight = false;
    }
    glutPostRedisplay();
}

// textures

gliGenericImage *readTgaImage(char *filename)
{
    FILE *file;
    gliGenericImage *image;
    
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open \"%s\"\n", filename);
        return NULL;
    }
    image = gliReadTGA(file, filename);
    fclose(file);
    if (image == NULL) {
        printf("Error: could not decode file format of \"%s\"\n", filename);
        return NULL;
    }
    return image;
}

// Return true if h is a perfect power of 2 (up to 4096)
bool PowerOf2(int h)
{
    if(h!= 2 && h!=4 && h!=8 && h!=16 && h!=32 && h!=64 && h!=128 &&
       h!=256 && h!=512 && h!=1024 && h!=2048 && h!=4096)
        return false;
    else
        return true;
}

// Generic image loader code.
gliGenericImage *readImage(char *filename)
{
    size_t size = strlen(filename);
    if(toupper(filename[size-3]) == 'T' && toupper(filename[size-2]) == 'G' && toupper(filename[size-1]) == 'A')
    {
        gliGenericImage * result = readTgaImage(filename);
        if(!result)
        {
            std::cerr << "Error opening " << filename << std::endl;
            exit(1);
        }
        return result;
    }
    else
    {
        std::cerr << "Unknown Filetype!\n";
        exit(1);
    }
}

// This resets the edges of the texture image to a given "border color".
// You must call this for clamped images that do not take up the whole polygon.
// Otherwise, the texture edges will smear outward across the rest
// of the polygon.
void SetBorder(gliGenericImage * image)
{
    // set a border color.
    unsigned int border_r=50;
    unsigned int border_g=50;
    unsigned int border_b=255;
    int x,y;
    y=0;
    for(x=0; x<image->width; x++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    y=1;
    for(x=0; x<image->width; x++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    y=image->height-1;
    for(x=0; x<image->width; x++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    y=image->height-2;
    for(x=0; x<image->width; x++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    
    x=0;
    for(y=0; y<image->height; y++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    x=1;
    for(y=0; y<image->height; y++)
    {
        image->pixels[ 3*(y*image->width + x) + 0]=border_r;
        image->pixels[ 3*(y*image->width + x) + 1]=border_g;
        image->pixels[ 3*(y*image->width + x) + 2]=border_b;
    }
    x=image->width-1;
    for(y=0; y<image->height; y++)
    {
        int index = 3*(y*image->width + x);
        image->pixels[ index + 0]=border_r;
        image->pixels[ index + 1]=border_g;
        image->pixels[ index + 2]=border_b;
    }
    x=image->width-2;
    for(y=0; y<image->height; y++)
    {
        int index = 3*(y*image->width + x);
        image->pixels[ index + 0]=border_r;
        image->pixels[ index + 1]=border_g;
        image->pixels[ index + 2]=border_b;
    }
}

void initTextures() {
    gliGenericImage *image[num_textures];
    int n=0;
    image[n++] = readImage("/Users/nate/school/3600/Maze/Maze/hedge.tga");
    image[n++] = readImage("/Users/nate/school/3600/Maze/Maze/snow.tga");
    image[n++] = readImage("/Users/nate/school/3600/Maze/Maze/sky.tga");
    image[n++] = readImage("/Users/nate/school/3600/Maze/Maze/johnny.tga");
    if(n!=num_textures)
    {
        printf("Error: Wrong number of textures\n");
        exit(1);;
    }
    
    glGenTextures(num_textures, texName);
    
    for(int i=0; i<num_textures; i++)
    {
        glBindTexture(GL_TEXTURE_2D, texName[i]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        int repeats = i == 1 || i == 3;
        int needs_border = false; // i == 3; // Needed if clamping and not filling the whole polygon.
        if(repeats)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        }
        if(needs_border)
        {
            // set a border.
            SetBorder(image[i]);
        }
        
        bool mipmaps = false;
        if(!PowerOf2(image[i]->height) || !PowerOf2(image[i]->width))
        {
            // WARNING: Images that do not have width and height as
            // powers of 2 MUST use mipmaps.
            mipmaps = true;
        }
        
        if (mipmaps)
        {
            gluBuild2DMipmaps(GL_TEXTURE_2D, image[i]->components,
                              image[i]->width, image[i]->height,
                              image[i]->format, GL_UNSIGNED_BYTE, image[i]->pixels);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                            //GL_LINEAR_MIPMAP_LINEAR);
                            GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                            //GL_LINEAR);
                            GL_NEAREST);
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, image[i]->components,
                         image[i]->width, image[i]->height, 0,
                         image[i]->format, GL_UNSIGNED_BYTE, image[i]->pixels);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
    }
}

// Your initialization code goes here.
void InitializeMyStuff()
{
    gRat.setMaze(&gMaze);
    gFirstPerson = true;
    
    initTextures();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
        glutCreateWindow("This appears in the title bar");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    glColor3d(0,0,0); // forground color
    glClearColor(1, 1, 1, 0); // background color
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    InitializeMyStuff();
    
    glutMainLoop();
    
    return 0;
}