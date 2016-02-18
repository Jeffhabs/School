//
//  Circle.cpp
//  BouncingBall3
//
//  Created by Jeffrey Haberle on 1/25/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#include "Circle.hpp"
#include <vector>
#include <math.h>

double GRAVITY = .1;
double AIR_FRICTION = .999;
const double COLLISION_FRICTION = 1;

//
// Collision Detection
//
struct vectortype
{
    double x;
    double y;
};

void Collide(int p1, int p2, std::vector<Circle *>particles)
{
    vectortype en; // Center of Mass coordinate system, normal component
    vectortype et; // Center of Mass coordinate system, tangential component
    vectortype u[2]; // initial velocities of two particles
    vectortype um[2]; // initial velocities in Center of Mass coordinates
    double umt[2]; // initial velocities in Center of Mass coordinates, tangent component
    double umn[2]; // initial velocities in Center of Mass coordinates, normal component
    vectortype v[2]; // final velocities of two particles
    double m[2];	// mass of two particles
    double M; // mass of two particles together
    vectortype V; // velocity of two particles together
    double size;
    int i;
    
    double xdif=particles[p1]->getnextx() - particles[p2]->getnextx();
    double ydif=particles[p1]->getnexty() - particles[p2]->getnexty();
    
    // set Center of Mass coordinate system
    size=sqrt(xdif*xdif + ydif*ydif);
    xdif/=size; ydif/=size; // normalize
    en.x=xdif;
    en.y=ydif;
    et.x=ydif;
    et.y=-xdif;
    
    // set u values
    u[0].x=particles[p1]->getdx();
    u[0].y=particles[p1]->getdy();
    m[0]=particles[p1]->getradius()*particles[p1]->getradius();
    u[1].x=particles[p2]->getdx();
    u[1].y=particles[p2]->getdy();
    m[1]=particles[p2]->getradius()*particles[p2]->getradius();
    
    // set M and V
    M=m[0]+m[1];
    V.x=(u[0].x*m[0] + u[1].x*m[1])/M;
    V.y=(u[0].y*m[0] + u[1].y*m[1])/M;
    
    // set um values
    um[0].x=m[1]/M * (u[0].x-u[1].x);
    um[0].y=m[1]/M * (u[0].y-u[1].y);
    um[1].x=m[0]/M * (u[1].x-u[0].x);
    um[1].y=m[0]/M * (u[1].y-u[0].y);
    
    // set umt and umn values
    for(i=0;i<2;i++)
    {
        umt[i] = um[i].x * et.x + um[i].y * et.y;
        umn[i] = um[i].x * en.x + um[i].y * en.y;
    }
    
    // set v values
    for(i=0;i<2;i++)
    {
        v[i].x = umt[i] * et.x - umn[i] * en.x + V.x;
        v[i].y = umt[i] * et.y - umn[i] * en.y + V.y;
    }
    
    // reset particle values
    particles[p1]->setdx(v[0].x*COLLISION_FRICTION);
    particles[p1]->setdy(v[0].y*COLLISION_FRICTION);
    particles[p2]->setdx(v[1].x*COLLISION_FRICTION);
    particles[p2]->setdy(v[1].y*COLLISION_FRICTION);
    
} /* Collide */

bool circlesCollide(Circle *circle1, Circle *circle2)
{
    double d = sqrt(pow(circle2->getnextx() - circle1->getnextx(), 2) + pow(circle2->getnexty() - circle1->getnexty(), 2));
    return d < circle1->getradius() + circle2->getradius() && ((circle1->_isRed && circle2->_isRed) || (!circle1->_isRed && !circle2->_isRed));
}

// Drawing
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

Circle::Circle(double x, double y, double radius, double dx, double dy, double red, double green, double blue, bool isRed)
{
    _x = x;
    _y = y;
    _radius = radius;
    _dx = dx;
    _dy = dy;
    _red = red;
    _green = green;
    _blue = blue;
    _colliding = false;
    _isRed = isRed;
}

void Circle::update(int i, double screenX, double screenY, std::vector<Circle *>circles)
{
    _dy -= GRAVITY;
    _dy *= AIR_FRICTION;
    _dx *= AIR_FRICTION;
    
    // wall collisions
    if (_y - _radius <= 0)
        _dy = abs(_dy) == 0 ? COLLISION_FRICTION : abs(_dy);
    else if (_y + _radius >= screenY)
        _dy = -abs(_dy) == 0 ? -COLLISION_FRICTION : -abs(_dy);
    
    if (_x - _radius <= 0)
        _dx = abs(_dx) == 0 ? COLLISION_FRICTION : abs(_dx);
    else if (_x + _radius >= screenX)
        _dx = -abs(_dx) == 0 ? -COLLISION_FRICTION : -abs(_dx);
    
    // ball-ball collisions
    bool collideCheck = false;
    for (int j=i+1; j<circles.size(); j++)
    {
        if (circlesCollide(this, circles[j]))
        {
            collideCheck = true;
            if (!_colliding)
            {
                Collide(i, j, circles);
                _colliding = true;
            }
        }
    }
    if (!collideCheck) _colliding = false;
    
    // update position
    _x += _dx;
    _y += _dy;
    
}

void Circle::draw()
{
    glColor3ub(_red, _green, _blue);
    DrawCircle(_x, _y, _radius);
}

double Circle::getx() { return _x; }
double Circle::gety() { return _y; }
double Circle::getradius() { return _radius; }
double Circle::getr() { return _red; }
double Circle::getg() {return _green;}
double Circle::getb() { return _blue; }
double Circle::getdx() { return _dx; }
double Circle::getdy() { return _dy; }
double Circle::getnextx() { return _x + _dx; }
double Circle::getnexty() { return _y + _dy; }

void Circle::setdx(double dx) { _dx = dx; }
void Circle::setdy(double dy) { _dy = dy; }