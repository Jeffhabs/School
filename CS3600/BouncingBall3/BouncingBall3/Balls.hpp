//
//  Balls.hpp
//  BouncingBall3
//
//  Created by Jeffrey Haberle on 1/25/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#ifndef Balls_hpp
#define Balls_hpp

#include <iostream>
#include <vector>
#include "Circle.hpp"

class Balls
{
public:
    Balls();
    std::vector<Circle *> getCircles();
    double getScreenX();
    double getScreenY();
    void setScreenX(double screenX);
    void setScreenY(double screenY);
    void addCircle(Circle *circle);
    
private:
    std::vector<Circle *>_circles;
    double _screenX;
    double _screenY;
};

#endif /* Balls_hpp */
