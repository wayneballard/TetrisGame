#pragma once
#ifndef UPDATEROW_H
#define UPDATEROW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Figure.h"

void removeFullRows(std::vector<std::vector<std::pair<int, sf::Color>>>& playfield);


#endif

