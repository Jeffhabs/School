//
//  Random.hpp
//  Babbler
//
//  Created by Jeffrey Haberle on 11/24/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Random_hpp
#define Random_hpp

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <map>

void initRand();
int randUpTo(int min, int max);
std::string choice(std::map<std::string, int> choices);

#endif /* Random_hpp */
