//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_DECK_H
#define MAKAO_DECK_H


#include <vector>
#include "Cards.h"

class Deck {
public:
    std::vector<std::shared_ptr<Card>> cardCollection;           //zbior kart

    Deck();
    ~Deck();

    void createCards();                         //tworzenie kart
    void shuffleDeck();                         //tasowanie kart
};


#endif //MAKAO_DECK_H
