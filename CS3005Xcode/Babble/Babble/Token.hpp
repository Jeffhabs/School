//
//  Token.hpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>


class Tokens {
    
public:
    
    Tokens();
    Tokens(std::vector<std::string> tokens);
    
    bool addToken(std::string token);
    bool addTokens(std::vector<std::string> tokens);
    std::string getToken(int i);
    std::map<std::string, int> getTokens();
    
    std::string getRandomToken();
    
    unsigned long size();
    
    void print();
    
protected:
    
private:
    
    std::map<std::string, int> mTokens;
    
    
};

#endif /* Token_hpp */
