//
//  Rational.h
//  Rational
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Rational_h
#define Rational_h

class Rational
{
public:
    Rational();
    Rational(const int n_in, const int d_in);
    int getNumerator() const;
    int getDenominator() const;
    
    Rational operator+(const Rational &r2) const;
    
protected:
    void addition(const int n_in, const int d_in);
    void multiplication(const int n_in, const int d_in);
    void simplify();
    
    int numerator;
    int denominator;
};


#endif /* Rational_h */
