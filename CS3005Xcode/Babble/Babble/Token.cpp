//
//  Token.cpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Token.hpp"

Tokens::Tokens()
{
    
}

Tokens::Tokens(std::vector<std::string> tokens)
{
    addTokens(tokens);
}

bool Tokens::addToken(std::string token)
{
    if (mTokens.count(token))
    {
        mTokens[token]++;
    }
    else
    {
        mTokens[token] = 1;
    }
    
    return true;
}

bool Tokens::addTokens(std::vector<std::string> tokens)
{
    for (auto const itr : tokens )
    {
        if(mTokens.count(itr))
        {
            mTokens[itr]++;
        }
        else
        {
            mTokens[itr] = 1;
        }
    }
    return true;
}


std::string Tokens::getToken(int i)
{
    long count = 0;
    for (auto const itr : mTokens)
    {
        count += itr.second;
        if(count >= i )
        {
            std::cout << "Random word is " << itr.first << std::endl;
            return itr.first;
        }
    }
    
    return "Error not found";
}

std::map<std::string, int> Tokens::getTokens()
{
    return mTokens;
}

std::string Tokens::getRandomToken()
{
    int i = std::rand() % size();
    
    return getToken(i);
}


unsigned long Tokens::size()
{
    unsigned long count = 0;
    for (auto const itr : mTokens)
    {
        count += itr.second;
    }
    
    return count;
}

void Tokens::print()
{
    std::cout << "Words:" << std::endl;
    for (auto const itr : mTokens)
    {
        std::cout << itr.first << " :: " << itr.second << std::endl;
    }
}