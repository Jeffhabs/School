//
//  GameGrid.hpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef GameGrid_hpp
#define GameGrid_hpp

#include <stdio.h>
#include "Square.hpp"


class GameGrid {
public:
    
    GameGrid(int size, Square square);
    
    void addSquares(std::vector<Square *> squares);
    
    void draw();
    void resize(int width, int height);
    
protected:
    
    int mSize;
    std::vector<Square *> mSquares;
    Square mSquare;
    
private:
    
    
};

/*
#include <vector>
#include "Square.hpp"


class GameGrid : public Square {
public:
    GameGrid(double x, double y, double size);
    std::vector<Square *> getLocations() const;
    void draw() const;
    
protected:
    int mWinningCombos[20][9];
};
*/
#endif /* GameGrid_hpp */
