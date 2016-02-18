//
//  Tile.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Tile.hpp"


Tile::Tile(double x, double y, double size)
:   Square(x, y, size), mOccupiedBy(-1)
{
    
}

Tile::Tile(Square square)
:   Tile(square.getLeft(), square.getBottom(), square.getSize())
{
    
}

void Tile::draw(int claimPlayer)
{
    if (mOccupiedBy >= 0) {
        char letter = mOccupiedBy == 0 ? 'O': 'X';
        void *font = GLUT_BITMAP_HELVETICA_18;
        if (claimPlayer < 0) {
            //            glColor3d(0, mOccupiedBy, !mOccupiedBy);
            if (mOccupiedBy) {
                glColor3d(0, .5, 0); // Player X
            } else {
                glColor3d(0, 0, .8); // Player O
            }
        } else {
            glColor3d(0, claimPlayer, !claimPlayer); // Grid color after it has been won by player
        }
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        
        int offset = (mSize - 12) / 2;
        glRasterPos2d(mLeft + offset, mBottom + offset);
        
        glutBitmapCharacter(font, letter);
        
        glDisable(GL_BLEND);
    }
    
}

bool Tile::click(double x, double y, int currentPlayer)
{
    if (mOccupiedBy < 0 && Square::contains(x, y)) {
        mOccupiedBy = currentPlayer;
        return true;
    }
    return false;
}

int Tile::getOccupiedBy() const
{
    return this->mOccupiedBy;
}