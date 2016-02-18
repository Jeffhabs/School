//
//  Risk.cpp
//  Assignment3
//
//  Created by Jeffrey Haberle on 10/1/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Risk.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Risk::Risk()
:mTrial(0), mAdice(0), mDdice(0), mAttackResult(0.0), mDefenderResult(0.0), mTotalArmiesLost(0.0)
{
    mAttackArray[0] = 0;
    mDefenseArray[0] = 0;
}

Risk::Risk(const int attackDice, const int defenseDice, const int trials)
:mTrial(trials)
{
    setAttack(attackDice);
    setDefense(defenseDice);
    setTrials(trials);
}


void Risk::setAttack(int attack_size)
{

    if(attack_size <= 3)
    {
        mAdice = attack_size;
    }
    else{
        mAdice = 0;
    }
    
}

const int Risk::getAttack() const
{
    return mAdice;
}

void Risk::setDefense(int defense_size)
{
    if(defense_size <= 2)
    {
        mDdice = defense_size;
    }
    else{
        mDdice = 0;
    }
}

const int Risk::getDefense() const
{
    return mDdice;
}

void Risk::setTrials(int trial_size)
{
    mTrial = trial_size;
}


const int Risk::getTrials() const
{
    return mTrial;
}



void Risk::rollDice()
{
    //local variables
    //int i;
    /*
     This should loop through the number
     of attackdice input (mAdice) and
     assign i a random num from 1-6 in
     mAttackArray and sort in descending
     order
     */

    int  j;

    for(j = 0; j < mAdice; j++)
    {
        mAttackArray[j] = rand() % 6 + 1;
    }
    
    for(j = 0; j < mDdice; j++)
    {
        mDefenseArray[j] = rand() % 6 + 1;
    }
    
    

}

void Risk::Compare()
{
    
    int size;
    int i, k;
    
    for(i = 0; i < mAdice; i++)
    {
        std::sort(mAttackArray, mAttackArray + mAdice, std::greater<int>());
    }
    
    for(i = 0; i < mDdice; i++)
    {
        std::sort(mDefenseArray, mDefenseArray + mDdice, std::greater<int>());
    }

    if(mAdice >= mDdice)
    {
        size = mDdice;
    }
    else{
        size = mAdice;
    }


    for(k = 0; k < size; k++)
    {
        if(mAttackArray[k] > mDefenseArray[k])
        {
            mDefendersLost++;
        }
        if(mDefenseArray[k] >= mAttackArray[k])
        {
            mAttackersLost++;
        }
    }
    
}

void Risk::Total()
{
    int size;
    
    if(mAdice >= mDdice)
    {
        size = mDdice;
    }
    else{
        size = mAdice;
    }

    mAttackResult = (mDefendersLost / (mTrial * size))*100;
    
    std::cout<<"The odds of the attacker winning in a "<<mAdice<<" vs "<<mDdice<<" battle are about %"<<mAttackResult<<std::endl;
}















