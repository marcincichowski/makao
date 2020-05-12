//
// Created by Dawid on 12.05.2020.
//
#include <string>

#ifndef MAKAO_PLAYER_H
#define MAKAO_PLAYER_H


class Player {
private:
    std::string nickname;           //nazwa gracza
    PlayerDeck hand;                //akutalna reka, domyslnie pusta przed rozdaniem
public:
    Player(std::string nicknameToSet) : nickname(nicknameToSet){}
};


#endif //MAKAO_PLAYER_H
