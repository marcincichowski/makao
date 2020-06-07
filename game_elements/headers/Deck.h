#ifndef MAKAO_DECK_H
#define MAKAO_DECK_H


#include <stack>
#include "Cards.h"

class Deck {
public:
    std::vector<std::shared_ptr<Card>> cardCollection;        //zbior kart

    Deck();
    ~Deck();

    void createCards();                         //tworzenie kart
    void shuffleDeck();                         //tasowanie kart
    void drawDeck(sf::RenderWindow &window);
};


#endif //MAKAO_DECK_H
