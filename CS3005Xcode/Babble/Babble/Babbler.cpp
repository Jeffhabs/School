//
//  Babbler.cpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Babbler.hpp"
#include "Shingle.hpp"
#include "Token.hpp"


Babbler::Babbler()
{
    mFile = new File();
    mTokens = new Tokens();
    mShingles = new Shingles();
}

Babbler::Babbler(long length, int ngram, const std::string inFile, const std::string outFile)
:mLength(length), mNgram(ngram), mInFile(inFile), mOutFile(outFile)
{
    mFile = new File();
    mTokens = new Tokens(mFile->readTokens(inFile));
    mShingles = new Shingles(mFile->readTokens(outFile), ngram);
}

Babbler::~Babbler()
{
    delete mShingles;
    delete mTokens;
    delete mFile;
}

bool Babbler::readFile()
{
    if(!mTokens->addTokens(mFile->readTokens(mInFile)))
    {
        return false;
    }
    return true;
}

bool Babbler::writeFile()
{
    if(!mFile->writeOut(mOutFile, mBabble))
    {
        return false;
    }
    
    return true;
}

bool Babbler::babble()
{
    int i;
    std::string randomToken;
    std::vector<std::string> randomGroupBy;
    if (mLength < 1 || mNgram < 1) {
        return false;
    }
    mBabble.clear();
    randomGroupBy = mFile->initRand(mNgram);
    
    for (auto const itr : randomGroupBy) {
        mBabble.push_back(itr);
    }
    for (i = 0; i < mLength; i++) {
        randomToken = mShingles->getRandomShingle(mBabble);
        if (randomToken == "Error") {
            randomGroupBy = mFile->initRand(mNgram);
            for (auto const itr : randomGroupBy) {
                
                mBabble.push_back(itr);
            }
        } else {
            mBabble.push_back(randomToken);
        }
    }
    writeFile();
    return true;
}
    
bool Babbler::print() {
    mShingles->print();
    return true;
}


