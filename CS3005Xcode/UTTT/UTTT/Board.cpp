//
//  Board.cpp
//  UTTT
//
//  Created by Jeffrey Haberle on 12/13/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "Board.hpp"

Board::Board(double x, double y, double size)
:   Grid(x, y, size),
mOccupied(0),
mPlayable(true),
mLatestTile(-1),
mClaimedBy(-1)
{
    std::vector<Square *> locations = Board::getLocations();
    Tile *tilePtr;
    for (auto itr : locations) {
        tilePtr = new Tile(*itr);
        mTiles.push_back(tilePtr);
        delete itr;
    }
}

Board::Board(Square square)
:   Board(square.getLeft(), square.getBottom(), square.getSize())
{
    
}

Board::~Board()
{
    for (auto itr : mTiles) {
        delete itr;
    }
}


void Board::draw(bool colorsToSkip) const
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
    Grid::draw();
    for (auto itr : mTiles) {
        itr->draw(mClaimedBy);
    }
}

bool Board::click(double x, double y, int currentPlayer)
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

int Board::getLatestTile()
{
    return mLatestTile;
}

void Board::setPlayable(bool value)
{
    mPlayable = value && mOccupied < 9;
}

bool Board::isFull()
{
    return mOccupied >= 9;
}

void Board::checkWin()
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
int Board::getOccupied()
{
    return mClaimedBy;
}