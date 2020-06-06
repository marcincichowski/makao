//
// Created by marci on 06.06.2020.
//
#include "SFML/Graphics.hpp"

#ifndef MAKAO_BOARD_H
#define MAKAO_BOARD_H
class Board{
public:
    Board(float width, float height);
    ~Board();
    void draw(sf::RenderWindow &window);
private:

};
#endif //MAKAO_BOARD_H
