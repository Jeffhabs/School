//
//  ngrams.cpp
//  Babbler
//
//  Created by Jeffrey Haberle on 11/24/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "ngrams.hpp"
#include <fstream>
#include <deque>
#include <string>

/* Check if deque is member of table */

bool isMemberTable(Table &t, std::deque<std::string> k) {
    return (t.find(k) != t.end());
}

/* Check if string is member of counter */

bool isMemberCounter(Counter &t, std::string k) {
    return (t.find(k) != t.end());
}

/* Give ngrams check all words after ngrams */

Table makeNgrams(int n, char *filename) {
    std::ifstream in(filename);
    Table counters;
    
    
    //represnt ngrams in deuque
    std::deque<std::string> ngram;
    
    
    //iterate through ngrams
    //update frequency
    std::string word;
    while (in) {
        in >> word;
        
        if( isMemberTable(counters, ngram )) {
            if( isMemberCounter(counters[ngram], word)) {
                counters[ngram][word] += 1;
            }
            else {
                counters[ngram][word] = 1;
            }
        }
        else {
            Counter newCounter;
            newCounter[word] = 1;
            counters[ngram] = newCounter;
        }
        
        //update ngram
        //make sure it is always size 'n'
        if( ngram.size() == n ) {
            ngram.pop_front();
        }
        
        ngram.push_back(word);
    }
    
    return counters;
}