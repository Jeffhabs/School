//
//  Rational.cpp
//  Rational
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <stdio.h>
#include "Rational.h"
#include <iostream>

Rational::Rational()
: numerator(0), denominator(0)
{
    
}

Rational::Rational(const int n_in, const int d_in)
: numerator(n_in), denominator(d_in)
{
    simplify();
}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

void Rational::addition(const int n_in, const int d_in)
{
    int n = numerator * d_in + denominator * n_in;
    int d = denominator * d_in;
    numerator = n;
    denominator = d;
    simplify();
}

void Rational::simplify()
{
    int u = std::abs(numerator), v = std::abs(numerator);
    int t;
    while(v)
    {
        t = u;
        u = v;
        v = t % v;
    }
    numerator /= u;
    denominator /= u;
}

Rational Rational::operator+(const Rational &r2) const
{
    Rational result;
    result.numerator = r2.numerator;
    result.denominator = r2.denominator;
    result.addition(result.numerator, result.denominator);
    result.simplify();
    return result;
}












