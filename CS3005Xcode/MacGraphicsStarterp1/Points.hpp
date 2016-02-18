//
//  Points.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#pragma once 
#include <stdio.h>

class Points {
public:
    Points(const double x, const double y);
    ~Points() {}
    void Draw();
    const double setX(double x){
        return mX = x;
    }
    const double setY(double y){
        return mY = y;
    }
    const double getX() const {
        return mX;
    }
    const double getY() const {
        return mY;
    }
    bool Contains(double x, double y) const;
    
private:
    double mX, mY;
};