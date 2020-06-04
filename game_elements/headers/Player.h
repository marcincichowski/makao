//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_PLAYER_H
#define MAKAO_PLAYER_H

#include <string>
#include <vector>
#include "Cards.h"

class Player {
private:
    std::string nickname;               //nazwa gracza
    std::vector<std::shared_ptr<Card>> hand;             //reka gracza

    int freezedRounds;                   //pozostala liczba rund do odczekania

public:
    Player(std::string nicknameToSet);
    ~Player();

    void setFreezedRounds(int freezedRounds);

    std::string getNickname() const;
};


#endif //MAKAO_PLAYER_H
