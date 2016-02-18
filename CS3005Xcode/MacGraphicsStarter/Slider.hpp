//
//  Slider.hpp
//  MacGraphicsStarter
//
//  Created by Jeffrey Haberle on 11/17/15.
//
//

#ifndef Slider_hpp
#define Slider_hpp

#include "Button.hpp"
#include <stdio.h>


class Slider : public Button
{
public:
    Slider(std::vector<Points *> points,
        const double r,
        const double g,
        const double b,
        const int associatedID);
    virtual void Draw();
    double setSliderLength(const double length){
        return mSliderLength = length;
    }
private:
    double mSliderLength;
    
    
};

#endif /* Slider_hpp */
