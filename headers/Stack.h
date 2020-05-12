//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_STACK_H
#define MAKAO_STACK_H

#include <stack>
#include "Card.h"

class Stack {
private:
    std::stack<Card> boardStack;           //karty lezace na stole
    int cardCount;                         //liczba kart na stosie
public:
    Stack();
    ~Stack();

    int getCardCount();
    void pushCart(Card toAdd);
    Card pullCard();
};


#endif //MAKAO_STACK_H
