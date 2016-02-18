//
//  File.hpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>


class File {
public:
    
    std::vector<std::string> readTokens(const std::string);
    bool writeOut(const std::string filename, std::vector<std::string> tokens);
    bool copyFile(const std::string inFile, const std::string outFile);
    
    std::vector<std::string> initRand(int ngram);
    
    
protected:
    
private:
    std::vector<std::string> mTokens;
};
#endif /* File_hpp */
