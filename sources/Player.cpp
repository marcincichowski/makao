//
// Created by Dawid on 12.05.2020.
//

#include <iostream>
#include "../headers/Player.h"

Player::Player(std::string nicknameToSet) : nickname(nicknameToSet) { std::cout << "Tworze gracze o nicku " << nickname << std::endl; }
Player::~Player() { std::cout << "Usuwam gracze o nicku " << nickname << std::endl; }

std::string Player::getNickname() { return nickname; }