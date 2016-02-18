//
//  main.cpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <iostream>
#include "Babbler.hpp"

int main(int argc, const char * argv[]) {
    
    std::srand(int(time(0)));
    
    const std::string inFile = "input.txt";
    const std::string outFile = "ouput.txt";
    
    long length = 30;
    int ngram = 1;
    
    Babbler *b = new Babbler(length, ngram, inFile, outFile);
    
    if(!b->babble())
    {
        std::cout << "Error babbling file" << std::endl;
    }
    
    if(!b->print())
    {
        std::cout << "Error printing text" << std::endl;
    }
    
    delete b;
    
}
