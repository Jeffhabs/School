//
//  Student.cpp
//  Assignment5
//
//  Created by Jeffrey Haberle on 10/6/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Student.hpp"
#include <iostream>
#include <cstring>

Student::Student()
:mAge(0), mLname(0), mFname(0), mEmail(0)
{
    mSsn[0] = 0;

    
}

Student::Student(const int age, const char* lastName, const char* firstName, const char* email, const char* ssn)
:mAge(0), mLname(0), mFname(0), mEmail(0)
{
    this->setAge(age);
    this->setLast(lastName);
    this->setFirst(firstName);
    this->setEmail(email);
    this->setSsn(ssn);
}

/*copy constructor to safely copy values*/
Student::Student(const Student &src)
:mAge(0), mLname(0), mFname(0), mEmail(0)
{
    *this = src;
}

/*destructor, deallocates memory if accessed*/
Student::~Student()
{
    if(this->mLname)
    {
        delete [] this->mLname;
        this->mLname = 0;
    }
    if(this->mFname)
    {
        delete [] this->mFname;
        this->mFname = 0;
    }
    if(this->mEmail)
    {
        delete [] this->mEmail;
        this->mEmail = 0;
    }
}

//assignment operator to safely copy values
Student &Student::operator=(const Student &rhs)
{
    this->setLast(rhs.mLname);
    this->setFirst(rhs.mFname);
    this->setEmail(rhs.mEmail);
    return *this;
}

int Student::getAge() const
{
    if(mAge >= 0 && mAge <= 150)
    {
        return this->mAge;
    }
    return 0;
}

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
    return false;
}

bool Student::setLast(const char last[])
{
    if(this->mLname)
    {
        delete [] this->mLname;
        this->mLname = 0;
    }
    
    this->mLname = new char [std::strlen(last)+1];
    
    if(this->mLname)
    {
        std::strcpy(this->mLname, last);
        return true;
    }
    else{
        return false;
    }
    
}

bool Student::setFirst(const char first[])
{
    if(this->mFname)
    {
        delete [] this->mFname;
        this->mFname = 0;
    }
    
    this->mFname = new char [std::strlen(first)+1];
    
    if(this->mFname)
    {
        std::strcpy(this->mFname, first);
        return true;
    }
    else{
        return false;
    }
}

bool Student::setEmail(const char email[])
{
    if(this->mEmail)
    {
        delete [] this->mEmail;
        this->mEmail = 0;
    }
    
    this->mEmail = new char [std::strlen(email)+1];
    
    if(this->mEmail)
    {
        std::strcpy(this->mEmail, email);
        return true;
    }
    else{
        return false;
    }
}


bool Student::setSsn(const char ssn[])
{
    if(std::strlen(ssn) == 11)
    {
        std::strcpy(this->mSsn, ssn);
        return true;
    }
    else{
        mSsn[0] = 0;
        return false;
    }
}








