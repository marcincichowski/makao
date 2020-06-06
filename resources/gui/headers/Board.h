//
// Created by marci on 06.06.2020.
//
#include "SFML/Graphics.hpp"
#include "../../../game_elements/headers/Player.h"
#include "../../../game_elements/headers/Deck.h"

#ifndef MAKAO_BOARD_H
#define MAKAO_BOARD_H


class Board{
private:
    Player *activePlayer;
    Player *previousPlayer;
    Stack *stack;
    Deck *deck;
    sf::Texture background;
    sf::Sprite backgroundSprite;
public:
    Board(float width, float height);
    ~Board();
    void draw(sf::RenderWindow &window);
};
#endif //MAKAO_BOARD_H
