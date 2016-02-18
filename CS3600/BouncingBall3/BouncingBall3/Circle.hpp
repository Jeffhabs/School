//
//  Circle.hpp
//  BouncingBall3
//
//  Created by Jeffrey Haberle on 1/25/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include <vector>
#include <GLUT/glut.h>

class Circle
{
    
public:
    Circle(double x, double y, double radius, double dx, double dy, double red, double green, double blue, bool isRed);
    void update(int i, double screenX, double screenY, std::vector<Circle *>circles);
    void draw();
    double getx();
    double gety();
    double getradius();
    double getr();
    double getg();
    double getb();
    double getdx();
    double getdy();
    double getnextx();
    double getnexty();
    void setdx(double dx);
    void setdy(double dy);
    bool _isRed;
    
private:
    double _x, _y, _radius, _dx, _dy, _red, _green, _blue;
    bool _colliding;
};

#endif /* Circle_hpp */
