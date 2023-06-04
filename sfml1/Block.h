#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Block {
private:
    Texture texture; //texture of the block 
    Color color;  //color of the block

public:
    bool loadTexture(const std::string& filename);  
    Texture& getTexture();
    void setColor(const Color& c);
    Color getColor() const;
};

#endif  // BLOCK_H

