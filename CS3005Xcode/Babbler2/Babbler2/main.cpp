//
//  main.cpp
//  Babbler2
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>

void display_stats(std::map<std::string, std::map<std::string,int> > prevs, std::map<std::string,int> words)
{
    std::map<std::string, std::map<std::string,int> >::iterator it;
    for (it = prevs.begin(); it != prevs.end(); it++)
    {
        std::map<std::string, int>::iterator wit;
        wit = words.find(it->first);
        std::cout << it->first << ":: " << wit->second;
        std::map<std::string,int>::iterator sit;
        for (sit = it->second.begin(); sit != it->second.end(); sit++)
        {
            std::cout << "\t" << sit->first << ":" << sit->second << " ";
        }
        std::cout << std::endl;
    }
}

void display_the(std::map<std::string, std::map<std::string,int> > prevs)
{
    std::map<std::string, int>::iterator it;
    std::cout << "The:" << std::endl;
    for (it = prevs["the"].begin(); it!= prevs["the"].end(); it++)
    {
        std::cout << "\t" << it->first << ":" << it->second << " ";
    }
    std::cout << std::endl;
    std::cout << prevs["the"].size() << " words following the word 'the'." << std::endl;
}

std::string new_key(std::map<std::string,int> prevwords)
{
    std::vector<std::string> l;
    std::map<std::string,int>::iterator it;
    for (it = prevwords.begin(); it != prevwords.end(); it++)
    {
        int i = 0;
        for (i=0; i < it->second; i++)
        {
            l.push_back(it->first);
        }
    }
    if (l.size() == 0)
    {
        return "NULL";
    }
    //std::advance(it, std::rand() % choices.size() );
    return l[std::rand() % l.size()];
}

void babble(std::map<std::string,int> words, std::map<std::string, std::map<std::string, int> > p, int num)
{
    std::map<std::string, std::map<std::string,int> >::iterator itr;
    itr = p.begin();
    std::string key = new_key(words);
    for (int i = 0; i < num; i++)
    {
        std::cout << key << " ";
        itr = p.find(key);
        key = new_key(itr->second);
        if (key == "NULL")
        {
            key = new_key(words);
        }
    }
    std::cout << std::endl;
}

void toLower(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void remove_punct(std::string &s)
{
    for (int c = 0, len = s.size(); c < len; c++)
    {
        if (std::ispunct(s[c]) )
        {
            s.erase(c--, 1);
            len = s.size();
        }
    }
}

int main(int argc, char ** argv)
{
    if (argc < 2 || argc > 3)
    {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        std::cout <<"or" <<std::endl<< "Usage: " << argv[0] << " <filename> <output length(words)>" << std::endl;
        exit(0);
    }
    int num = 15;
    if (argc == 3)
    {
        num = std::atoi(argv[2]);
    }
    
    std::ifstream fin (argv[1]);
    if (!fin)
    {
        std::cout << argv[1] << " not found." << std::endl;
        exit(1);
    }
    
    std::srand((unsigned)std::time(0));
    std::map<std::string,int> words;
    std::map<std::string, std::map<std::string, int> > prevs;
    std::string prevword = "NULL";
    std::string w;
    while(fin)
    {
        fin >> w;
        if (!fin)
        {
            break;
        }
        //Let's add some extra parsing here, moving all to lower case and removing puncuation if we can.
        remove_punct(w);
        toLower(w);
        //increment word of create entry
        if (words.find(w) != words.end() )
        {
            words[w]++;
        }
        else
        {
            words[w] = 1;
            prevs[w] = std::map<std::string, int>();
        }
        // add to prevwords list of followers.
        if (prevword == "NULL")
        {
            prevword = w;
            continue;
        }
        std::map<std::string, std::map<std::string,int> >::iterator fit;
        fit = prevs.find(prevword);
        if (fit != prevs.end() )
        {
            std::map<std::string,int>::iterator git;
            git = fit->second.find(w);
            if (git != fit->second.end() )
            {
                git->second++;
            }
            else
            {
                fit->second[w] = 1;
            }
        }
        prevword = w;
    }
    display_the(prevs);
    display_stats(prevs, words);
    babble(words,prevs, num);
    return 0;
}
