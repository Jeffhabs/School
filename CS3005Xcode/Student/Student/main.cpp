//
//  main.cpp
//  Student
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
#include <cstring>

int main()
{
    const int  age = 1;
    const char *last = "a";
    const char *first = "b";
    const char *email = "c";
    const char *ssn = "999-99-9999";
    Student s(age, last, first, email, ssn);
    
    std::stringstream ss;
    ss << "0 NONE NONE NONE NONE";
    ss >> s;
}


