//
//  Triangle.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#pragma ounce
#include "Shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(std::vector<Points *> points,
             const double r,
             const double g,
             const double b,
             bool filled);
    void Draw();
};