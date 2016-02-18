//
//  Shingle.hpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Shingle_hpp
#define Shingle_hpp

#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <map>
#include <string>
#include <vector>

class Shingles {
public:
    
    Shingles();
    Shingles(std::vector<std::string> tokens, int ngrams);
    
    bool setShingle(std::vector<std::string> tokens);
    bool addShingle(std::vector<std::string> tokens, std::string shingle);
    
    std::string getRandomShingle(std::vector<std::string> tokens);
    std::string selectRandom(std::map<std::string, int> shingle);
    
    
    void print();
    
protected:
    
private:
    
    std::map<std::vector<std::string>, std::map<std::string, int> > mShingles;
    int mNgram;
    
};

#endif /* Shingle_hpp */
