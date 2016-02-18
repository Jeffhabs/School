//
//  Pentagon.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 12/14/15.
//
//

#ifndef Pentagon_hpp
#define Pentagon_hpp

#include <stdio.h>
#include <vector>
#include "Shape.hpp"

class Pentagon : public Shape
{
public:
    Pentagon(std::vector<Points *> points,
             const double r,
             const double g,
             const double b,
             bool filled);
    void Draw();
};

#endif /* Pentagon_hpp */
