//
//  Student.hpp
//  Assignment5
//
//  Created by Jeffrey Haberle on 10/6/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>

class Student
{
public:
    Student();
    Student(const int age, const char* lastName, const char* firstName, const char* email, const char* ssn);
    //copy constructor
    Student(const Student &src);
    //destructor
    ~Student();
    //assignment operator
    Student &operator=(const Student &rhs);
    
    /* accessor methods*/
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
    /* data members */
    int mAge = 0;
    char * mLname;
    char * mFname;
    char * mEmail;
    char mSsn[12];
    
};



#endif /* Student_hpp */
