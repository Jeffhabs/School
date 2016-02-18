//
//  Circle.hpp
//  BouncingBall
//
//  Created by Jeffrey Haberle on 1/19/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

class Circle
{
public:
    Circle(double x, double y, double dX, double dY, double radius,
           double red,
           double green,
           double blue);
    double x, y, dX, dY, radius;
    double red, green, blue;
};



#endif /* Circle_hpp */
