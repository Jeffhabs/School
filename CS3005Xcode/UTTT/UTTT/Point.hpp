//
//  Point.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include "Headers.h"

class Point {
public:
    
    Point();
    Point(double x, double y);
    
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    
    //    virtual void draw();
    //    virtual void setColor(std::vector<double> color);
    //    virtual void save(std::ostream &os);
    //    virtual void load(std::istream &is);
    
    
protected:
    
private:
    
    double mX;
    double mY;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs);
std::istream &operator>>(std::istream &is, Point &rhs);

#endif /* Point_hpp */
