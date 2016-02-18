//
//  Babbler.hpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Babbler_hpp
#define Babbler_hpp

#include <stdio.h>
#include "File.hpp"
#include "Shingle.hpp"
#include "Token.hpp"
#include <map>
#include <string>
#include <iostream>
#include <vector>


class Babbler
{
public:
    Babbler();
    Babbler(long length, int ngram, const std::string inFile, const std::string outFile);
    ~Babbler();
    
    bool readFile();
    bool writeFile();
    bool babble();
    bool print();
    
protected:
    
private:
    std::vector<std::string> mBabble;
    Shingles *mShingles;
    File *mFile;
    Tokens *mTokens;
    std::string mInFile;
    std::string mOutFile;
    long mLength;
    int mNgram;
};

#endif /* Babbler_hpp */
