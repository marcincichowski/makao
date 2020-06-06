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
    std::shared_ptr<Player> activePlayer;
    std::shared_ptr<Player> previousPlayer;
    std::shared_ptr<Stack> stack;
    std::shared_ptr<Deck> deck;
    int playerCount;
    sf::Texture background;
    sf::Sprite backgroundSprite;
public:
    Board(float width, float height,int playerCount);
    ~Board();
    void draw(sf::RenderWindow &window);
    void nextPlayer();
    int getPlayerCount() const;
    void giveaway();
    Deck *getDeck()const;
};
#endif //MAKAO_BOARD_H
