#include "UpdateRow.h"

void removeFullRows(std::vector<std::vector<std::pair<int, sf::Color>>>& playfield) {
    for (int i = PLAYFIELD_HEIGHT - 1; i >= 0; i--) {
        bool isFull = true;
        for (int j = 0; j < PLAYFIELD_WIDTH; j++) {
            if (playfield[i][j].first== 0) {
                isFull = false;
                break;
            }
        }
        if (isFull) {
            playfield.erase(playfield.begin() + i);
            playfield.insert(playfield.begin(), std::vector<std::pair<int, sf::Color>>(PLAYFIELD_WIDTH, { 0, sf::Color::White }));
        }
    }
}