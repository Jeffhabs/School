//
//  Student.cpp
//  Student
//
//  Created by Jeffrey Haberle on 9/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Student.hpp"
#include <iostream>


Student::Student()
: mAge(0)
{
    mLname[0] = 0;
    mFname[0] = 0;
    mEmail[0] = 0;
    mSsn[0] = 0;
}
Student::Student(const int age, const char* lastName, const char* firstName, const char* email, const char* ssn)
:mAge(age)
{
    setLast(lastName);
    setFirst(firstName);
    setEmail(email);
    setSsn(ssn);
    
}

int Student::getAge() const
{
    if(mAge >= 0 && mAge <= 150)
    {
        return mAge;
    }
    return 0;
}


//how do you type that const char *getLast() const
const char* Student::getLast() const
{
    return mLname;
}

const char* Student::getFirst() const
{
    return mFname;
}

const char* Student::getEmail() const
{
    return mEmail;
}

const char* Student::getSsn() const
{
    return mSsn;
}

bool Student::setAge(const int age)
{
    if(age >= 0 && age <= 150)
    {
        mAge = age;
        return true;
    }
    else
    {
        mAge = 0;
        return false;
    }
}

bool Student::setLast(const char last[])
{
    if(std::strlen(last) < 63)
    {
        std::strcpy(mLname, last);
        return true;
    }
    else
    {
        std::strncpy(mLname, last, 63);
        mLname[63] = 0;
        return false;
    }
}

bool Student::setFirst(const char first[])
{
    if(std::strlen(first) < 63)
    {
        std::strcpy(mFname, first);
        return true;
    }
    else
    {
        std::strncpy(mFname, first, 63);
        mFname[63] = 0;
        return false;
    }
}

bool Student::setEmail(const char email[])
{
    if(std::strlen(email) < 63)
    {
        std::strcpy(mEmail, email);
        return true;
    }
    else
    {
        std::strncpy(mEmail, email, 63);
        mEmail[63] = 0;
        return false;
    }
}

bool Student::setSsn(const char ssn[])
{
    if(std::strlen(ssn) < 11)
    {
        std::strcpy(mSsn, ssn);
        return true;
    }
    else
    {
        mSsn[11] = 0;
        return false;
    }
    
}

std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
    
    os << rhs.getAge() <<  " ";
    
    if(rhs.getLast()[0] == 0)
    {
        os << "NONE" << " ";
    }
    else{
        os << rhs.getLast() << " ";
    }
    
    if(rhs.getFirst()[0] == 0)
    {
        os << "NONE" << "";
    }
    else{
        os << rhs.getFirst() << " ";
    }
    
    if(rhs.getEmail()[0] == 0)
    {
        os << "NONE" << "";
    }
    else{
        os << rhs.getEmail() << " ";
    }
    
    if(rhs.getSsn()[0] == 0)
    {
        os << "NONE" <<  " ";
    }
    else{
        os << rhs.getSsn();
    }
    
    return os;
    
}


std::istream &operator>>(std::istream &is, Student &rhs)
{
    const int MAX_LENGTH = 63;
    
    int age;
    char fName [MAX_LENGTH];
    char lName [MAX_LENGTH];
    char email [MAX_LENGTH];
    char ssn [MAX_LENGTH];
    
    is >> age;
    if(is)
    {
        rhs.setAge(age);
    }
    else{
        rhs.setAge(0);
    }
    
    is >> lName;
    if(is)
    {
        rhs.setLast(lName);
    }
    else{
        rhs.setLast(0);
    }
    
    is >> fName;
    if(is)
    {
        rhs.setFirst(fName);
    }
    else{
        rhs.setFirst(0);
    }
    
    is >> email;
    if(is)
    {
        rhs.setEmail(email);
    }
    else{
        rhs.setEmail(0);
    }
    
    is >> ssn;
    if(is)
    {
        rhs.setSsn(ssn);
    }
    else{
        rhs.setSsn(0);
    }
    
    return is;
}








