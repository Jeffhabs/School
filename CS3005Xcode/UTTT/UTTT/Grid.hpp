//
//  Grid.hpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "Headers.h"
#include <vector>
#include "Square.hpp"


class Grid : public Square {
public:
    Grid(double x, double y, double size);
    std::vector<Square *> getLocations() const;
    void draw() const;
    
protected:
    int mWinningCombos[20][9];
};

/*
class Grid {
public:
    
    Grid(int size, Square square);
    
    void addSquares(std::vector<Square *> squares);
    
    void draw();
    void resize(int width, int height);
    
protected:
    
    int mSize;
    std::vector<Square *> mSquares;
    Square mSquare;
    
private:
    
    
};
*/
#endif /* Grid_hpp */
