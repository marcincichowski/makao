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
    int freezedRounds;                   //pozostala liczba rund do odczekania
    int playerNo;
    std::vector<std::shared_ptr<Card>> hand; //reka gracza
    bool win;
    int place;
public:
    Player(std::string nicknameToSet, int index);
    ~Player();

    void setFreezedRounds(int freezedRounds);
    std::string getNickname() const;
    void drawHand(sf::RenderWindow&, int activeOption, sf::Time, sf::Clock);
    void drawHiddenHand(sf::RenderWindow &window, int);
    int getPlayerNo()const;
    std::vector<std::shared_ptr<Card>>* getHand();
    int getFreezedRounds() const;
    bool getWin() const;
    void setWin();
    void setPlace(int number);
    int getPlace() const;
};


#endif //MAKAO_PLAYER_H
