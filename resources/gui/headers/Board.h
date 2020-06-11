//
// Created by marci on 06.06.2020.
//
#include "SFML/Graphics.hpp"
#include "../../../game_elements/headers/Player.h"
#include "../../../game_elements/headers/Deck.h"
#include "../../../game_elements/headers/Stack.h"
#include <iostream>

#ifndef MAKAO_BOARD_H
#define MAKAO_BOARD_H

#define NUMBER_OF_BUTTONS 2

class Board{
private:
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Player> activePlayer;
    std::shared_ptr<Stack> stack;
    std::shared_ptr<Deck> deck;
    sf::Text buttons[NUMBER_OF_BUTTONS];
    sf::Font font;
    sf::Text nickname;
    sf::Sprite shapes[4];
    sf::Sprite numbers[6];
    sf::Texture shapesTextures[4];
    sf::Texture numbersTextures[6];
    sf::Text chooseNumber;
    sf::Text chooseShape;
    sf::Text newRoundText;
    sf::Text skippedRoundText[2];
    sf::Text desiredColorText;
    sf::Text desiredNumberText;
    sf::Time secondsWrong;
    sf::Clock zegar;
    sf::Texture background_texture;
    sf::Texture game_background_texture;
    sf::Sprite background;
    sf::Sprite game_background;
    bool skippedRound;
    int activeOption;
    bool option;
    int activeButton;
    bool IS_NEW_ROUND;
    int round;
    int activeChooseNumber;
    int activeChooseShape;
    bool chooseWindowNumber;
    bool chooseWindowShape;
    bool desiredColor;
    bool desiredNumber;

public:
    Board();
    Board(float width, float height);
    ~Board();
    void draw(sf::RenderWindow &window);
    int getPlayerCount() const;
    void giveaway();
    void moveRight();
    void moveLeft();
    void newRound();
    void throwCard();
    std::shared_ptr<Card> getPressedCard();
    void pressSpace();
    int getPressedOption();
    int getActivePlayerHandSize();
    void drawCard();
    bool checkDeck();
    bool getIsNewRound() const;
    void moveStackToDeck();
    void drawChooseShape(sf::RenderWindow &window);
    void drawChooseNumber(sf::RenderWindow &window);
    void chooseMoveLeftShape();
    void chooseMoveRightShape();
    void chooseMoveRightNumber();
    void chooseMoveLeftNumber();
    bool getChooseWindowShape() const;
    bool getChooseWindowNumber() const;
    void getSelectedWindowNumber();
    void getSelectedWindowShape();
    sf::Sprite getBackground();
    void initBoard(int playerCount);

};
#endif //MAKAO_BOARD_H