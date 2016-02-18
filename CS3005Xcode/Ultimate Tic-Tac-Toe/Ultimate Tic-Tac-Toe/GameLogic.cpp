//
//  GameLogic.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Jeffrey Haberle on 12/8/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include "GameLogic.hpp"


GameLogic::GameLogic(double x, double y, double size)
:   GameGrid(x, y, size),
mActive(true),
mCurrentPlayer(0)
{
    std::vector<Square *> locations = getLocations();
    GameBoard *board;
    for (auto itr : locations) {
        board = new GameBoard(*itr);
        board->adjust(1, 1, -2);
        mBoards.push_back(board);
        delete itr;
    }
}

GameLogic::GameLogic(Square square)
: GameLogic(square.getLeft(), square.getBottom(), square.getSize())
{
    
}

GameLogic::~GameLogic()
{
    for (auto itr : mBoards) {
        delete itr;
    }
}


void GameLogic::draw() const
{
    if (mActive) {
        std::string title = "Player ";
        title += mCurrentPlayer == 0 ? "O": "X";
        title += "'s turn";
        glutSetWindowTitle(title.c_str());
    } else if(mCurrentPlayer >= 0) {
        std::string title = "Player ";
        title += mCurrentPlayer == 0 ? "O": "X";
        title += " Won!";
        glutSetWindowTitle(title.c_str());
    } else {
        glutSetWindowTitle("Tie Game");
    }
    
    glColor3d(0, 0, 0); // forground color
    GameGrid::draw();
    for (auto itr : mBoards) {
        itr->draw(!mActive);
    }
}

bool GameLogic::click(double x, double y)
{
    if (mActive && Square::contains(x, y)) {
        for (auto itr : mBoards) {
            if(itr->click(x, y, mCurrentPlayer)) {
                int index = itr->getLatestTile();
                setPlayableBoard(index);
                mCurrentPlayer = ++mCurrentPlayer % 2;
                checkWin();
                return true;
            }
        }
    }
    return false;
}

void GameLogic::setPlayableBoard(int index)
{
    GameBoard * currentBoard = mBoards.at(index);
    bool allBoardsPlayable = currentBoard->isFull();
    for (auto itr : mBoards) {
        itr->setPlayable(allBoardsPlayable);
    }
    currentBoard->setPlayable(true);
}

void GameLogic::checkWin()
{
    if (mActive) {
        int i;
        GameBoard * board1Ptr, * board2Ptr, * board3Ptr;
        for (i = 0; i < 8; i++) {
            board1Ptr = mBoards.at(mWinningCombos[i][0]);
            board2Ptr = mBoards.at(mWinningCombos[i][1]);
            board3Ptr = mBoards.at(mWinningCombos[i][2]);
            
            if (board1Ptr->getOccupied() >= 0 &&
                board1Ptr->getOccupied() == board2Ptr->getOccupied() &&
                board2Ptr->getOccupied() == board3Ptr->getOccupied())
            {
                mActive = false;
                mCurrentPlayer = board1Ptr->getOccupied();
                return;
            }
        }
        for (auto itr : mBoards) {
            if( !itr->isFull() ) { return; }
        }
        mActive = false;
        mCurrentPlayer = -1;
    }
}