//
// Created by Dawid on 12.05.2020.
//

#include <iostream>
#include "../headers/Player.h"

Player::Player(std::string nicknameToSet) : nickname(nicknameToSet) {
    //std::cout << "Tworze gracze o nicku " << nickname << std::endl;
    freezedRounds = 0;
}
Player::~Player() { //std::cout << "Usuwam gracze o nicku " << nickname << std::endl;
     }

std::string Player::getNickname() const{ return nickname; }

void Player::setFreezedRounds(int roundsToSet) {
    Player::freezedRounds = roundsToSet;
}

int Player::getCardCount() const {
    return hand.size();
}

void Player::drawHand(sf::RenderWindow &window, int activeOption) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    float scale = 0.15;
    int i = 0;
    for(auto &card : this->hand){
        sf::Sprite toDraw = card->draw(scale);
        toDraw.setPosition(sf::Vector2f((20 + distance), height*0.75));
        if(activeOption == i)
            toDraw.setColor(sf::Color(255,100,100));
        window.draw(toDraw);
        distance += widthBetween;
        i++;
    }
}

void Player::drawHiddenHand(sf::RenderWindow &window, int no) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    float scale = 0.1;
    for(auto &card : this->hand){
        sf::Sprite toDraw = card->drawHidden(scale);
        toDraw.setPosition(sf::Vector2f((20 + distance), 50+160*(no)));
        window.draw(toDraw);
        distance += widthBetween;
    }

}

void Player::setNo(int val) {
    playerNo = val;
}
