//
// Created by Dawid on 12.05.2020.
//

#include "../headers/Stack.h"

Stack::Stack() { cardCount = boardStack.size(); }

int Stack::getCardCount() { return cardCount; }

void Stack::addCardsToPull(int amountToAdd) { cardsToPull+=amountToAdd; }
void Stack::addRoundsToWait(int amountToAdd) { roundsToWait+=amountToAdd; }

void Stack::pushCard(Card *toAdd) { boardStack.push(toAdd); }
Card* Stack::pullCard() { return boardStack.top(); boardStack.pop(); }