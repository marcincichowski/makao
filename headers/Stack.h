//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_STACK_H
#define MAKAO_STACK_H

#include <stack>
#include "Cards.h"

class Stack {
private:
    std::stack<Card*> boardStack;           //karty lezace na stole
    int cardCount;                         //liczba kart na stosie
    int cardsToPull;                       //liczba kart to pociagniecia, w przypadku 2,3
    int roundsToWait;                     //liczba tur ktore musi przeczekac kolejny gracz bez karty ochronnej gdy >0

public:
    Stack();
    ~Stack();

    int getCardCount();

    void addCardsToPull(int amountToAdd);
    void addRoundsToWait(int amountToAdd);

    Card* pullCard();
    void pushCard(Card *toAdd);
};


#endif //MAKAO_STACK_H
