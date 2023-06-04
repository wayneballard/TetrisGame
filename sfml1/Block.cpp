#include "Block.h"

bool Block::loadTexture(const std::string& filename) { //load texture of the block
    if (texture.loadFromFile(filename)) {
        return true;
    }
    return false;
}

Texture& Block::getTexture() { //get texture of the block
    return texture;
}

void Block::setColor(const Color& c) { //set color of the block
    color = c;  
}

Color Block::getColor() const { //get color of the block
    return color;
}

