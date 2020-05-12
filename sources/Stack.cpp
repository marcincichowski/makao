//
// Created by Dawid on 12.05.2020.
//

#include "../headers/Stack.h"

Stack::Stack() { cardCount = boardStack.size(); }

void Stack::pushCart(Card toAdd) { boardStack.push(toAdd); }
Card Stack::pullCard() { return boardStack.top(); boardStack.pop(); }