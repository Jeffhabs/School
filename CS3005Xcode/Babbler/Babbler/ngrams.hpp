//
//  ngrams.hpp
//  Babbler
//
//  Created by Jeffrey Haberle on 11/24/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef ngrams_hpp
#define ngrams_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <utility>
#include <deque>
#include <string>
#include <map>

//#include "random.h"

typedef std::map<std::string, int> Counter;
typedef std::map<std::deque<std::string>, Counter> Table;

bool isMemberTable(Table &t, std::deque<std::string> k);
bool isMemberCounter(Counter &t, std::string k);

Table makeNgrams(int n, char *filename);




#endif /* ngrams_hpp */
