//
//  Circle.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#pragma ounce
#include <stdio.h>
#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(std::vector<Points *> points,
           const double r,
           const double g,
           const double b,
           bool filled);
    Points * getCenter() const {
        return mVertices[0];
    }
    double getRadius() const {
        return mRadius;
    }
    double getArea() const {
        return PI * mRadius * mRadius;
    }
    double getCircumference() const {
        return 2 * PI * mRadius;
    }
    void Draw();
    void Adjust(double x, double y, Points * selectedPoint);
    
protected:
    double mRadius;
};