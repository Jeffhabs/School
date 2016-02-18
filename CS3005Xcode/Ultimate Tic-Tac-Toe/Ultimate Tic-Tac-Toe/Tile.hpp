//
//  Tile.hpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "Square.hpp"

class Tile : public Square {
public:
    Tile(double x, double y, double size);
    Tile(Square square);
    void draw(int claimPlayer);
    bool click(double x, double y, int currentPlayer);
    int getOccupiedBy() const;
    
protected:
    int mOccupiedBy;
};
#endif /* Tile_hpp */
