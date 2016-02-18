//
//  Babbler.cpp
//  Babbler
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <utility>
#include <deque>
#include <string>
#include <map>

#include "Random.hpp"
#include "ngrams.hpp"

#define MAX_WORDS 100

using namespace std;


/*
 * Given a map of ngram -> word -> frequency, and the length of an n-gram,
 * print MAX_WORDS words.
 */
void babble(Table &counters, int n) {
    // current n-gram
    deque<string> ngram;
    // Number of words printed
    int word_count = 0;
    
    while (word_count < MAX_WORDS) {
        // get next word to print
        string next_word = choice(counters[ngram]);
        
        // if next_word is empty, we have don't have any words to print
        if (next_word == "") {
            break;
        }
        
        // Update n-gram and print word
        if (ngram.size() == n) {
            ngram.pop_front();
        }
        ngram.push_back(next_word);
        
        cout << next_word << " ";
        
        word_count++;
    }
    cout << endl;
}


/*
 * Print up to MAX_WORDS words based on ngrams of length n.
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "usage: ngram n corpus" << endl;
        return 1;
    }
    
    // Initialize random variable
    initRand();
    
    // Length of n-gram
    int n = atoi(argv[1]);
    // n-gram -> (word -> frequency)
    Table counters = makeNgrams(n, argv[2]);
    
    // Babble!
    babble(counters, n);
    
    return 0;
}