//
//  File.cpp
//  Babble
//
//  Created by Jeffrey Haberle on 11/28/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "File.hpp"

std::vector<std::string> File::readTokens(const std::string fileName)
{
    std::vector<std::string> tokens;
    std::ifstream fin(fileName);
    if(!fin)
    {
        std::cerr << " Unable to open file " << fileName << std::endl;
    }
    
    std::string temp;
    
    while(fin)
    {
        fin >> temp;
        if(fin)
        {
            //remove punc
            temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
            //remove digits
            temp.erase(std::remove_if(temp.begin(), temp.end(), isdigit), temp.end());
            if(temp.size() >= 1)
            {
                //make lower-case
                std::transform(temp.begin(), temp.end(), temp.begin(), tolower);
                
                mTokens.push_back(temp);
                tokens.push_back(temp);
            }
        }
    }
    fin.close();
    return tokens;
}

std::vector<std::string> File::initRand(int ngram)
{
    int rand = std::rand() % mTokens.size() - ngram ;
    int i;
    std::vector<std::string> gather;
    for( i = 0; i < ngram; i++ )
    {
        gather.push_back(mTokens[rand + i]);
    }
    
    return gather;
}

bool File::writeOut(const std::string filename, std::vector<std::string> tokens)
{
    std::ofstream fout(filename);
    if(!fout)
    {
        std::cerr << "Unable to open " << filename << std::endl;
        return false;
    }
   
    //1 per line
    int i;
    int size = int(tokens.size());
    
    for( i = 0; i < size; i++ )
    {
        fout << tokens[i] << " ";
    }
    
    fout.close();
    return true;
}

bool File::copyFile(const std::string inFile, const std::string outFile)
{
    std::vector<std::string> input = readTokens(inFile);
    
    
    bool flag = writeOut(outFile, input);
    if(!flag)
    {
        return false;
    }
    
    return true;
}
