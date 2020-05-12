//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_PLAYER_H
#define MAKAO_PLAYER_H

#include <string>

class Player {
private:
    std::string nickname;               //nazwa gracza
public:
    Player(std::string nicknameToSet);
    ~Player();

    std::string getNickname();
};


#endif //MAKAO_PLAYER_H
