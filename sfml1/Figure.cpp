#include "Figure.h"

void Figure::setFigure(int n) {  //set random figure
    for (int i = 0; i < 4; i++) {
        blocks.push_back({ figures[n][i] % 2, figures[n][i] / 2 });  
    }
}

void Figure::rotateby90() {  //rotate by 90
    if (!blocks.empty()) {
        Position pivot = blocks[0];
        for (size_t i = 1; i < blocks.size(); i++) {
            int X = blocks[i].x - pivot.x;
            int Y = blocks[i].y - pivot.y;
            blocks[i].x = pivot.x - Y;
            blocks[i].y = pivot.y + X;
        }
    }
}

void Figure::rotateby270() {  //rotate by 270
    if (!blocks.empty()) {
        Position pivot = blocks[0];
        for (size_t i = 1; i < blocks.size(); i++) {
            int X = blocks[i].x - pivot.x;
            int Y = blocks[i].y - pivot.y;
            blocks[i].x = pivot.x + Y;
            blocks[i].y = pivot.y - X;
        }
    }
}

void Figure::moveRight() {   //move right
    for (auto& block : blocks) {
        block.x++;
    }
}

void Figure::moveLeft() {    //move left
    for (auto& block : blocks) {
        block.x--;
    }
}

bool Figure::checkCollision(const vector<vector<pair<int, Color>>>& playfield, const vector<Figure>& figures) {  //check collision
    for (const auto& figure : figures) {                                                                         
        for (const auto& block : figure.blocks) {  
            int x = block.x;  //extracts the x-coordinate of the current block within the figure
            int y = block.y;  //extracts the y-coordinate of the current block within the figure
            if (x < 0 || x >= PLAYFIELD_WIDTH || y >= PLAYFIELD_HEIGHT || (y >= 0 && playfield[y][x].first != 0)) { //check collision with the bounds
                return true;
            }
        }
    }
    return false;
}

