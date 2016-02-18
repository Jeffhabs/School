//
//  GameLogic.hpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef GameLogic_hpp
#define GameLogic_hpp

#include <stdio.h>
#include <vector>
#include "GameGrid.hpp"
#include "GameBoard.hpp"

class GameLogic : public GameGrid {
public:
    GameLogic(double x, double y, double size);
    GameLogic(Square square);
    ~GameLogic();
    void setSize();
    void draw()const;
    bool click(double x, double y);
    void setPlayableBoard(int index);
    void checkWin();
    
protected:
    std::vector<GameBoard *> mBoards;
    bool mActive;
    int mCurrentPlayer;
    
};

#endif /* GameLogic_hpp */
