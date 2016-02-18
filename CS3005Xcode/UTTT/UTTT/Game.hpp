//
//  Game.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include <vector>
#include "Grid.hpp"
#include "Board.hpp"

class Game : public Grid {
public:
    Game(double x, double y, double size);
    Game(Square square);
    ~Game();
    void setSize();
    void draw()const;
    bool click(double x, double y);
    void setPlayableBoard(int index);
    void checkWin();
    
protected:
    std::vector<Board *> mBoards;
    bool mActive;
    int mCurrentPlayer;
    
};

#endif /* Game_hpp */
