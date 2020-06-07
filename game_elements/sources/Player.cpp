//
// Created by Dawid on 12.05.2020.
//

#include <iostream>
#include "../headers/Player.h"

Player::Player(std::string nicknameToSet) : nickname(nicknameToSet) {
    //std::cout << "Tworze gracze o nicku " << nickname << std::endl;
    freezedRounds = 0;
}
Player::~Player() { std::cout << "Usuwam gracze o nicku " << nickname << std::endl; }

std::string Player::getNickname() const{ return nickname; }

void Player::setFreezedRounds(int roundsToSet) {
    Player::freezedRounds = roundsToSet;
}

int Player::getCardCount() const {
    return hand.capacity();
}

void Player::drawHand(sf::RenderWindow &window) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    for(auto card : this->hand){
        card->printCard();
        sf::Sprite toDraw = card->draw();
        toDraw.setPosition(sf::Vector2f((width/2 - 100 + distance), height*0.75));
        window.draw(toDraw);
        distance += widthBetween;
    }
}

void Player::drawHiddenHand(sf::RenderWindow &window) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    for(auto card : this->hand){
        card->printCard();
        sf::Sprite toDraw = card->draw();
        toDraw.setPosition(sf::Vector2f((width/2 - 100 + distance), height*0.75));
        window.draw(toDraw);
        distance += widthBetween;
    }
}
