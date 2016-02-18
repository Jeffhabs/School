//
//  Line.hpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/9/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>

#include "Point.hpp"

class Line {
public:
    
    Line(Point p1, Point p2);
    
    void draw();
    
    void setLP1(Point p);
    void setLP2(Point p);
    void setP1(Point p);
    void setP2(Point p);
    void setP3(Point p);
    void setP4(Point p);
    Point getLP1();
    Point getLP2();
    Point getP1();
    Point getP2();
    Point getP3();
    Point getP4();
    
    
    
protected:
    
    double mWidth;
    bool mVertical;
    Point mLP1;
    Point mLP2;
    
    Point mP1;
    Point mP2;
    Point mP3;
    Point mP4;
    
private:
    
    
};

#endif /* Line_hpp */
