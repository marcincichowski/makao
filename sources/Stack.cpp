//
// Created by Dawid on 12.05.2020.
//

#include "../headers/Stack.h"

Stack::Stack() {
    roundsToWait = 0;
    cardCount = 0;
    cardsToPull = 0;
}
Stack::~Stack() {}

int Stack::getCardCount() { return cardCount; }

void Stack::addCardsToPull(int amountToAdd) { cardsToPull+=amountToAdd; }
void Stack::addRoundsToWait(int amountToAdd) { roundsToWait+=amountToAdd; }

void Stack::pushCard(Card *toAdd) { boardStack.push(toAdd); }
Card* Stack::pullCard() { return boardStack.top(); boardStack.pop(); }

int Stack::getCardsToPull() const {
    return cardsToPull;
}

int Stack::getRoundsToWait() const {
    return roundsToWait;
}

void Stack::reset() {
    cardsToPull = 0;
    roundsToWait = 0;
}

Card *Stack::topCard() {
   if(cardCount>0){return boardStack.top();}
   else{ return nullptr; }
}

void Stack::setDesiredColor(Color colorToSet) {
    Stack::desiredColor = colorToSet;
}

void Stack::setDesiredValue(Value colorToSet) {
    Stack::desiredValue = colorToSet;
}



