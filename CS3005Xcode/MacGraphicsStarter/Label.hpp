//
//  Label.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/4/15.
//
//

#pragma ounce
#include <stdio.h>
#include "Button.hpp"

class Label : public Button
{
public:
    Label(std::vector<Points *> points,
          const double r,
          const double g,
          const double b,
          const char* text);
    virtual void Draw();
};