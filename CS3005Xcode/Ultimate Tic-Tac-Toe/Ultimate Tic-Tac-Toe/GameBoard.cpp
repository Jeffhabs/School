//
//  GameBoard.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "GameBoard.hpp"

GameBoard::GameBoard(double x, double y, double size)
:   GameGrid(x, y, size),
mOccupied(0),
mPlayable(true),
mLatestTile(-1),
mClaimedBy(-1)
{
    std::vector<Square *> locations = GameBoard::getLocations();
    Tile *tilePtr;
    for (auto itr : locations) {
        tilePtr = new Tile(*itr);
        mTiles.push_back(tilePtr);
        delete itr;
    }
}

GameBoard::GameBoard(Square square)
:   GameBoard(square.getLeft(), square.getBottom(), square.getSize())
{
    
}

GameBoard::~GameBoard()
{
    for (auto itr : mTiles) {
        delete itr;
    }
}


void GameBoard::draw(bool colorsToSkip) const
{
    if (mPlayable || colorsToSkip) {
        switch (mClaimedBy) {
            case 0:
            case 1:
                glColor3d(0, mClaimedBy, !mClaimedBy); // forground color
                //                glClearColor(.5, .5, .5, 0); // background color
                break;
            default:
                glColor3d(1, colorsToSkip, 0); // forground color
                break;
        }
    } else if(!colorsToSkip) {
        glColor3d(.5, .5, .5); // forground color
    }
    GameGrid::draw();
    for (auto itr : mTiles) {
        itr->draw(mClaimedBy);
    }
}

bool GameBoard::click(double x, double y, int currentPlayer)
{
    if (mPlayable && mOccupied < 9 && Square::contains(x, y)) {
        std::vector<Tile *>::iterator it;
        for (it = mTiles.begin(); it != mTiles.end(); it++) {
            if((*it)->click(x, y, currentPlayer)) {
                mOccupied++;
                mPlayable = mOccupied < 9;
                mLatestTile = (int)(it - mTiles.begin());
                checkWin();
                return true;
            }
        }
    }
    mLatestTile = -1;
    return false;
}

int GameBoard::getLatestTile()
{
    return mLatestTile;
}

void GameBoard::setPlayable(bool value)
{
    mPlayable = value && mOccupied < 9;
}

bool GameBoard::isFull()
{
    return mOccupied >= 9;
}

void GameBoard::checkWin()
{
    if (mClaimedBy < 0) {
        int i;
        Tile * tile1Ptr, * tile2Ptr, * tile3Ptr;
        for (i = 0; i < 8; i++) {
            tile1Ptr = mTiles.at(mWinningCombos[i][0]);
            tile2Ptr = mTiles.at(mWinningCombos[i][1]);
            tile3Ptr = mTiles.at(mWinningCombos[i][2]);
            
            if (tile1Ptr->getOccupiedBy() >= 0 && tile1Ptr->getOccupiedBy() == tile2Ptr->getOccupiedBy() &&  tile2Ptr->getOccupiedBy() == tile3Ptr->getOccupiedBy())
            {
                mClaimedBy = tile1Ptr->getOccupiedBy();
                return;
            }
        }
    }
}
int GameBoard::getOccupied()
{
    return mClaimedBy;
}
