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
