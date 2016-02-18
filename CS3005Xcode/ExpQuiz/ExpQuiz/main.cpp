//
//  main.cpp
//  ExpQuiz
//
//  Created by Jeffrey Haberle on 10/23/15.
//  Copyright © 2015 Rocketmade. All rights reserved.
//

#include <iostream>

#include "ExpQuiz.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>



long long powerFunc(const int exp)
{
    int t;
    long long base =2;
    long long ba = 2;
    if (exp <= 0)
    {
        return 1;
    }
    for (t = 0; t < exp-1; t++)
    {
        base *= ba;
    }
    return base;
}

bool isSame(long long correct, long long answer)
{
    if (correct == answer)
    {
        return 1;
    }
    else{
        return 0;
    }
}
long long initAnswer(const char a[])
{
    int i;
    long long total = 0;
    long long k = 1024;
    long long h = 2*2*2*2*2*2*2;
    long long d = 2*2*2;
    for (i = 0; a[i] >= '0' && a[i] <= '9'; i++)
    {
        total = total * 10 + (a[i] - '0');
    }
    if (a[i] == 'k' || a[i] == 'K')
    {
        total = total * k;
    }
    if (a[i] == 'm' || a[i] == 'M')
    {
        total = total * k * k;
    }
    if (a[i] == 'b' || a[i] == 'B')
    {
        total = total * k * k * k;
    }
    if (a[i] == 't' || a[i] == 'T')
    {
        total = total * k * k * k * k;
    }
    
    if (a[i] == 'd' || a[i] == 'D')
    {
        total = total * d;
    }
    if (a[i] == 'h' || a[i] == 'H')
    {
        total = total * h;
    }
       return total;
}

int main()
{
    char finish;
    char answer[32];
    
    // start;
    // Seed time
    time_t start = std::time(0);
    std::srand((unsigned)std::time(0));
    
    int i, j;
    int a[50];
    //populate array
    for (i = 0; i <= 49; i++)
    {
        a[i] = i;
    }
    //randomize our array
    for (j = 0; j < i; j++)
    {
        int temp = 0, num;
        num = std::rand() % i;
        temp =  a[j];
        a[j] = a[num];
        a[num] = temp;
        
    }
    
    int base, exponent, time = 0;
    bool flag;
    long long ans = 0;
    long long exp = 0;
    base = 2;
    
    
    for (finish = 0; finish < 49; finish++)
    {
        exponent = a[finish];
        j = 1+finish;
        
        std::cout << "What is " << base << "^" << exponent << " = ";
        std::cin >> answer;
        ans = initAnswer(answer);
        exp = powerFunc(exponent);
        flag = isSame(ans, exp);
        while (!flag)
        {
            time += 5;
            std::cout << "Wrong answer.Try Again! "<< std::endl;
            std::cout << "What is " << base << "^" << exponent << " = ";
            std::cin >> answer;
            ans = initAnswer(answer);
            flag = isSame(ans, exp);
            
        }
        std::cout << "Correct" << std::endl;
        
        
    }
    std::cout << (std::time(0) + time)-start << " seconds to complete quiz" << std::endl;
    std::cout << "Press enter to quit.";
    std::cin >> finish;
    return 0;
}