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
    std::vector<std::shared_ptr<Player>> players;
    Player *activePlayer;
    Player *previousPlayer;
    Stack *stack;
    Deck *deck;
    int playerCount;
    sf::Texture background;
    sf::Sprite backgroundSprite;
public:
    Board(float width, float height);
    ~Board();
    void draw(sf::RenderWindow &window);
    void nextPlayer();
    int getPlayerCount() const;
    void giveaway();
};
#endif //MAKAO_BOARD_H
