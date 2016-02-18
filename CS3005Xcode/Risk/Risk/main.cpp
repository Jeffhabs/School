//
//  main.cpp
//  Risk
//
//  Created by Jeffrey Haberle on 10/30/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//

#include <iostream>
#include "Risk.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main(int argc, const char * argv[])
{
    if(argc !=4)
    {
        //in  3 2 1000000
        //out 3 vs 2 = 54.2%
        std::cout<<"attack defense trials" << std::endl;
        return 1;
    }
    
    int a, d, t, i;
    
    a = std::atoi(argv[1]);
    d = std::atoi(argv[2]);
    t = std::atoi(argv[3]);
    
    //create Risk objects
    Risk r(a, d, t);
    std::srand((unsigned)std::time(0));
    for(i = 0; i < r.getTrials(); i++)
    {
        r.rollDice();
        r.Compare();
    }
    r.Total();
    
    return 0;
    
}

/*
 int main()
 {
 int i;
 
 Risk r(1, 1, 1000);
 std::srand((unsigned)std::time(0));
 for(i = 0; i < r.getTrials(); i++)
 {
 r.rollDice();
 r.Compare();
 }
 r.Total();
 
 }
 */