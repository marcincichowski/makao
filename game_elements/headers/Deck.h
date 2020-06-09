#ifndef MAKAO_DECK_H
#define MAKAO_DECK_H


#include <stack>
#include "Cards.h"

class Deck {
private:
    std::vector<std::shared_ptr<Card>> cardCollection;      //zbior kart

public:
    Deck();
    ~Deck();

    void createCards();                         //tworzenie kart
    void shuffleDeck();                         //tasowanie kart
    void drawDeck(sf::RenderWindow &window);
    std::vector<std::shared_ptr<Card>>* getCardCollection();
};


#endif //MAKAO_DECK_H
