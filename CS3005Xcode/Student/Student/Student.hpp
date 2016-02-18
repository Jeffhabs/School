//
//  Student.hpp
//  Student
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>

class Student
{
public:
    Student();
    Student(const int age, const char* lastName, const char* firstName, const char* email, const char* ssn);
    
    /*accessor methods */
    int getAge() const;
    const char *getLast() const;
    const char *getFirst() const;
    const char *getEmail() const;
    const char *getSsn() const;
    bool setAge(const int age);
    bool setLast(const char last[]);
    bool setFirst(const char first[]);
    bool setEmail(const char email[]);
    bool setSsn(const char ssn[]);
    
    
private:
    int mAge  = 0;
    char mLname[64];
    char mFname[64];
    char mEmail[64];
    char mSsn[12];

};

std::ostream &operator<<(std::ostream &os, const Student &rhs);
std::istream &operator>>(std::istream &is, Student &rhs);

#endif /* Student_hpp */
