//
//  Risk.hpp
//  Assignment3
//
//  Created by Jeffrey Haberle on 10/1/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Risk_hpp
#define Risk_hpp

#include <stdio.h>

class Risk
{
public:
    Risk();
    Risk(const int attackDice, const int defenseDice, const int trials);
    void setAttack(int attack); //should I make this constant?
    void setDefense(int defense_size);
    void setTrials(int trial_size);
    void Compare();
    void Total();



    const int getAttack() const;
    const int getDefense() const;
    const int getTrials() const;


    void rollDice();
    
    
private:
    int mAdice;
    int mDdice;
    int mTrial;
    
    int mAttackArray[3];  //should I make this to a max of 3?
    int mDefenseArray[2]; //should I make thist o a max of 2?
    
    float mTotalArmiesLost;
    float mAttackResult;
    float mDefenderResult;
    
    float mDefendersLost;
    float mAttackersLost;
    
    
    
    
};

#endif /* Risk_hpp */
