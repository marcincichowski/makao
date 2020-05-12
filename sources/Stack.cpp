//
// Created by Dawid on 12.05.2020.
//

#include "../headers/Stack.h"

int Stack::getCardCount() { return cardCount; }

void Stack::pushCart(Card toAdd) { boardStack.push(toAdd); }
Card Stack::pullCard() { return boardStack.top(); boardStack.pop(); }