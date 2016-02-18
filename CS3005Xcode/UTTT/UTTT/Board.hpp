//
//  Board.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include "Grid.hpp"
#include "Tile.hpp"

class Board : public Grid {
public:
    Board(double x, double y, double size);
    Board(Square square);
    ~Board();
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

#endif /* Board_hpp */
