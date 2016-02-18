//
//  GameBoard.hpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include "GameGrid.hpp"
#include "Tile.hpp"
#include <vector>

class GameBoard : public GameGrid {
public:
    GameBoard(double x, double y, double size);
    GameBoard(Square square);
    ~GameBoard();
    void draw(bool mActive) const;
    bool click(double x, double y, int currentPlayer);
    int getLatestTile();
    void setPlayable(bool value);
    bool isFull();
    int getOccupied();
    
protected:
    std::vector<Tile *> mTiles;
    int mOccupied;
    bool mPlayable;
    int mLatestTile;
    int mClaimedBy;
    void checkWin();
    
};


#endif /* GameBoard_hpp */
