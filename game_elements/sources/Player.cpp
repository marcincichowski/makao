//
// Created by Dawid on 12.05.2020.
//

#include <iostream>
#include "../headers/Player.h"

Player::Player(std::string nicknameToSet, int index) : nickname(nicknameToSet),playerNo(index), freezedRounds(0){}
Player::~Player() {}

void Player::setFreezedRounds(int roundsToSet) {
    Player::freezedRounds = roundsToSet;
}

std::string Player::getNickname() const{ return nickname; }

void Player::drawHand(sf::RenderWindow &window, int activeOption, sf::Time czas, sf::Clock zegar) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    float scale = 0.15;
    int i = 0;
    for(auto &card : this->hand){
        sf::Sprite toDraw = card->draw(scale);
        toDraw.setPosition(sf::Vector2f((20 + distance), height*0.75));
        if(activeOption == i) {
            if((zegar.getElapsedTime().asMilliseconds()-czas.asMilliseconds()) > 250){
                toDraw.setColor(sf::Color(100, 255, 100));
            }
            else{
                toDraw.setColor(sf::Color(255, 100, 100));
            }
        }
        window.draw(toDraw);
        distance += widthBetween;
        i++;
    }
}

void Player::drawHiddenHand(sf::RenderWindow &window, int no) {
    float widthBetween = 30;
    float distance = 0;
    float scale = 0.1;
    int counter = 0;
    for(auto &card : this->hand){
        if(counter>=15){return;}else{counter++;}
        sf::Sprite toDraw = card->drawHidden(scale);
        toDraw.setPosition(sf::Vector2f((20 + distance), 50+160*(no)));
        window.draw(toDraw);
        distance += widthBetween;
    }
}

int Player::getPlayerNo() const {
    return playerNo;
}

std::vector<std::shared_ptr<Card>> *Player::getHand() {
    return &hand;
}

int Player::getFreezedRounds() {
    return freezedRounds;
}
