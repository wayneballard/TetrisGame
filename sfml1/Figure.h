#pragma once
#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Block.h"

using namespace sf;
using namespace std;
const int PLAYFIELD_WIDTH = 16;
const int PLAYFIELD_HEIGHT = 31;
 const int blockSize = 15; // adjust this value to change the block size
 const int xOffset = 12; // adjust this value to set the horizontal offset
 const int yOffset = 133; // adjust this value to set the vertical offset
class Figure : public Block {
public:
    int figures[8][4] = { //array of figures, each represented by an array of four numbers
        {1, 3, 5, 7},
        {2, 4, 5, 7},
        {3, 5, 4, 6},
        {3, 5, 4, 7},
        {2, 3, 5, 7},
        {3, 5, 7, 6},
        {2, 3, 4, 5},
        {3, 4, 5, 7}
    };

    struct Position {  //Position of block in x and y direction
        int x, y;
    };

    vector<Position> blocks; //vector of blocks

    void setFigure(int n);
    void rotateby90();
    void rotateby270();
    void moveRight();
    void moveLeft();
    bool checkCollision(const vector<vector<pair<int, Color>>>& playfield, const vector<Figure>& figures);
};

#endif  

