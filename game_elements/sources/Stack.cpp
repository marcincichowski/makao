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

void Stack::pushCard(std::shared_ptr<Card> toAdd) { boardStack.push(toAdd); }

std::shared_ptr<Card> Stack::pullCard() {
    return boardStack.top();
    boardStack.pop();
}

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

std::shared_ptr<Card> Stack::topCard() {
   if(cardCount>0){return boardStack.top();}
   else{ return nullptr; }
}

void Stack::setDesiredColor(Color colorToSet) {
    Stack::desiredColor = colorToSet;
}

void Stack::setDesiredValue(Value colorToSet) {
    Stack::desiredValue = colorToSet;
}

std::ostream& operator<< (std::ostream& out, const Color& color)
{
    switch(color)
    {
        case pik: out << "pik"; break;
        case kier: out << "kier"; break;
        case karo: out << "karo"; break;
        case trefl: out << "trefl"; break;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const Value& value)
{
    switch(value)
    {
        case dwa: out << "dwa"; break;
        case trzy: out << "trzy"; break;
        case cztery: out << "cztery"; break;
        case piec: out << "piec"; break;
        case szesc: out << "szesc"; break;
        case siedem: out << "siedem"; break;
        case osiem: out << "osiem"; break;
        case dziewiec: out << "dziewiec"; break;
        case dziesiec: out << "dziesiec"; break;
        case walet: out << "walet"; break;
        case dama: out << "dama"; break;
        case krol: out << "krol"; break;
        case as: out << "as"; break;
    }
    return out;
}


