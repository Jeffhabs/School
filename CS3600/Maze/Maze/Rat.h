//
//  Rat.h
//  Maze
//
//  Created by Jeffrey Haberle on 2/17/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#ifndef Rat_h
#define Rat_h
#include "maze.hpp"

const double MOVE_SPEED = 150;
const double SPIN_SPEED = 25;

class Rat
{
public:
    Rat();
    Maze * getMaze();
    double getX();
    double getY();
    double getDegrees();
    void setMaze(Maze *maze);
    void setX(double x);
    void setY(double y);
    void setDegrees(double degrees);
    void draw(double invisible);
    void move(double dt);
    void spinLeft(double dt);
    void spinRight(double dt);
    
private:
    double x, y, degrees;
    Maze *maze;
};

#endif /* Rat_h */
