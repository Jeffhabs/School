//
//  Shape.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "Headers.h"


class Shape {
public:
    
    Shape();
    Shape(std::vector<double> color);
    virtual void draw() = 0;
    virtual void setColor(std::vector<double> color) = 0;
    virtual void save(std::ostream &os) = 0;
    virtual void load(std::istream &is) = 0;
    
protected:
    
    std::vector<double> mColor;
    
private:
    
};
#endif /* Shape_hpp */
