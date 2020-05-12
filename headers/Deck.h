//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_DECK_H
#define MAKAO_DECK_H


#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cardCollection;           //zbior kart
    Deck();
    ~Deck();

    void createCards();                         //tworzenie kart
    void shuffleDeck();                         //tasowanie kart
};


#endif //MAKAO_DECK_H
