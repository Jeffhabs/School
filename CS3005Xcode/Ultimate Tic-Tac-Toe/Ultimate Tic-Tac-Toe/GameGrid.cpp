//
//  GameGrid.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "GameGrid.hpp"

GameGrid::GameGrid(int size, Square square)
:   mSize(size),
mSquare(square)
{
    addSquares(mSquares);
}

void GameGrid::addSquares(std::vector<Square *> squares)
{
    squares.clear();
    int row, col;
    double left = mSquare.getLeft();
    double bottom = mSquare.getBottom();
    double width = mSquare.getWidth();
    double height = mSquare.getHeight();
    double colWidth = width / mSize;
    double rowHeight = height / mSize;
    
    for (row = 1; row <= mSize; row++) {
        for (col = 1; col <= mSize; col++) {
            double x1 = (col * colWidth) + left;
            double x2 = x1 + colWidth;
            double y1 = (row * rowHeight) + bottom;
            double y2 = ((row - 1) * rowHeight) + bottom;
            Point p1 = Point(x1, y1);
            Point p2 = Point(x2, y2);
            
            squares.push_back(new Square(p1, p2));
        }
    }
}

void GameGrid::draw()
{
    for (auto itr : mSquares) {
        itr->draw();
    }
}

void GameGrid::resize(int width, int height)
{
    
}

/*
GameGrid::GameGrid(double x, double y, double size)
: Square(x, y, size)
{
    int i, j;
    int count = 0;
    for (i = 0; i < mBoardSize * 2; i++) {
        for (j = 0; j < mBoardSize; j++) {
            if (i >= mBoardSize) {
                // Colums
                mWinningCombos[i][j] = (i - mBoardSize) + (j * mBoardSize);
            } else {
                // Rows
                mWinningCombos[i][j] = count;
            }
            count++;
        }
    }
    // Only check diagonals if size in an odd number
    if (mBoardSize % 2) {
        // Top Left to Bottom Right
        for (j = 0; j < mBoardSize; j++) {
            mWinningCombos[(mBoardSize * 2)][j] = j * (mBoardSize + 1);
        }
        // Top Right to Bottom Left
        for (j = 0; j < mBoardSize; j++) {
            mWinningCombos[1 + (mBoardSize * 2)][j] = (mBoardSize - 1) + (j * (mBoardSize - 1));
        }
    }
}


std::vector<Square *> GameGrid::getLocations() const
{
    std::vector<Square *> squares;
    double size = mSize / mBoardSize;
    
    Square * sq;
    int i, xOffset, yOffset;
    double x, y;
    for(i = 0; i < (mBoardSize * mBoardSize); i++) {
        xOffset = i % mBoardSize;
        yOffset = i / mBoardSize;
        
        x = mLeft + xOffset * size;
        y = mBottom + yOffset * size;
        
        sq = new Square(x, y, size);
        squares.push_back(sq);
    }
    return squares;
}

void GameGrid::draw() const
{
    std::vector<Square *> squares = this->getLocations();
    for (auto itr : squares) {
        itr->draw();
    }
}
*/