//
//  Square.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include <stdio.h>
#include <vector>
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

class Square {
public:
    Square(double x, double y, double size);
    void draw() const;
    bool contains(double x, double y) const;
    
    void adjust(double dx, double dy, double dsize);
    
    double getLeft() const;
    double getBottom() const;
    double getSize() const;
    
protected:
    double mLeft;
    double mBottom;
    double mSize;
    int mBoardSize;
};
/*
#include "Headers.h"
#include "Point.hpp"


class Square {
public:
    
    Square();
    Square(Point p1, Point p2);
    
    void setP1(Point p);
    void setP2(Point p);
    Point getP1();
    Point getP2();
    
    double getLeft();
    double getBottom();
    double getWidth();
    double getHeight();
    
    virtual void draw();
    //    virtual void setColor(std::vector<double> color);
    
protected:
    
    Point mP1;
    Point mP2;
    
private:
    
    
};
*/
#endif /* Square_hpp */
