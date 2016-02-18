//
//  Random.cpp
//  Babbler
//
//  Created by Jeffrey Haberle on 11/24/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Random.hpp"
#include <cstdlib>

void initRand()
{
    //std::srand((unsigned)time(0));
    std::srand((unsigned)time(0));
}

int randUpTo(int min, int max)
{
    return (std::rand() % max) + min;
}

std::string choice(std::map<std::string, int> choices) {
    
    int n;
    int weight1, weight2;
    std::string item1, item2;
    std::map<std::string, int>::iterator it;
    
    it = choices.begin();
    
    item1 = ""; weight1 = 0;
    while ( it != choices.end()) {
        item2 = it->first; weight2 = it->second;
        
        n = randUpTo(1, weight1 + weight2);
        
        if(n <= weight2) {
            item1 = item2;
        }
        
        weight1 = weight1 + weight2;
        
        it++;
    }
    
    return item1;
}