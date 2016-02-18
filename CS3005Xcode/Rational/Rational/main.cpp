//
//  main.cpp
//  Rational
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <iostream>
#include "Rational.h"

int main()
{
    Rational r1(3,8);
    Rational r2(1,6);
    Rational r3;
    
    r3 = r1 + r2;
    
    std::cout<<r3.getNumerator()<<"/"<<r3.getDenominator()<<std::endl;
    
}
