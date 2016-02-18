//
//  Shingle.cpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Shingle.hpp"


Shingles::Shingles()
{

}

Shingles::Shingles(std::vector<std::string> tokens, int ngram)
:mNgram(ngram)
{
    if(ngram < 1)
    {
        mNgram = 1;
    }
    
    setShingle(tokens);
}

bool Shingles::setShingle(std::vector<std::string> tokens)
{
    mShingles.clear();
    std::vector<std::string> prev;
    
    for(auto const itr: tokens)
    {
        if(prev.size() < mNgram)
        {
            prev.push_back(itr);
        }
        else
        {
            addShingle(prev,itr);
            prev.erase(prev.begin());
            prev.push_back(itr);
        }
    }
    
    return true;
}

bool Shingles::addShingle(std::vector<std::string> tokens, std::string shingle)
{
        if(!mShingles.count(tokens))
        {
            mShingles[tokens];
        if(!mShingles[tokens].count(shingle))
        {
            mShingles[tokens][shingle] = 1;
        }
        else
        {
            mShingles[tokens][shingle] += 1;
        }
    
}
        else
        {
            if (!mShingles[tokens].count(shingle))
            {
                mShingles[tokens][shingle] = 1;
            }
            else
            {
                mShingles[tokens][shingle] += 1;
            }
        }
    
    return true;
}

std::string Shingles::getRandomShingle(std::vector<std::string> tokens)
{
    std::string random;
    if ( tokens.size() < mNgram)
    {
        for(auto const itr : mShingles)
        {
            std::string match = itr.first[itr.first.size() - 1];
            std::string token = tokens[tokens.size() - 1];
            
            if(match == token)
            {
                random = selectRandom(itr.second);
                return random;
            }
        }
    }
    
    std::vector<std::string> tokenGram = std::vector<std::string>(tokens.end() - mNgram, tokens.end());
    std::map<std::string, int> shingles;
    
    if(mShingles.count(tokenGram))
    {
        shingles = mShingles[tokenGram];
        random = selectRandom(shingles);
    }
    else
    {
        random = "oops!";
    }
    
    return random;
}

std::string Shingles::selectRandom(std::map<std::string, int> shingle)
{
    int i = 0;
    int count = 0;
    
    std::string randomShingle;
    
    for(auto const itr : shingle)
    {
        count += itr.second;
    }
    
    if(count < 1)
    {
        std::cout << "Select random was < 1" << std::endl;
        return "Error";
    }
    else if ( count == 1)
    {
        i = 1;
    }
    else
    {
        i = rand() % count;
    }
    
    count = 0;
    for(auto const itr : shingle)
    {
        count += itr.second;
        if(count >= i)
        {
            randomShingle = itr.first;
            return randomShingle;
        }
    }
    return "Error";
}

void Shingles::print()
{
    std::cout << "Printing shingles: " << std::endl;
    long count = 0;
    
    std::vector<std::string> theTokens = {"the"};
    for(auto const itr : mShingles[theTokens])
    {
        count += itr.second;
    }
    if(count < 1 )
    {
        std::cout << std::endl << "Count was zero " <<std::endl;
    }
    
    std::cout << "the " << count << " :: " << std::endl;
    for(auto const itr : mShingles[theTokens])
    {
        std::cout << itr.first << " : ";
        std::cout << itr.second << " : " << std::endl;
    }
    
    count = 0;
}












