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

void Stack::pushCard(std::shared_ptr<Card> toAdd) { boardStack.push_back(toAdd); }

std::shared_ptr<Card> Stack::pullCard() {
    return boardStack.back();
    boardStack.pop_back();
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
   if(cardCount>0){return boardStack.back();}
   else{ return nullptr; }
}

void Stack::setDesiredColor(Color colorToSet) {
    Stack::desiredColor = colorToSet;
}

void Stack::setDesiredValue(Value colorToSet) {
    Stack::desiredValue = colorToSet;
}

void Stack::drawStack(sf::RenderWindow window) {
    if(this->getCardCount()==0){ return; }
    else {
        float width = window.getSize().x;
        float height = window.getSize().y;
        float widthBetween = 5;
        float distance = 0;
        int counter = 0;
        float scale = 0.15;
        for (auto &card : this->boardStack) {
            if (counter >= 5 || card == boardStack.back()) { break; } else { counter++; }
            sf::Sprite toDraw = card->draw(scale);
            toDraw.setPosition(sf::Vector2f((1100 + distance), 50 + distance));
            window.draw(toDraw);
            distance += widthBetween;
        }
    }
}

void Stack::initStack(NumericCard &card) {
    if(card.getValue() == 2 || card.getValue() == 3){
        addCardsToPull(card.getValue());
    }else if(card.getValue() == 4){

    }else{
        return;
    }
}
void Stack::initStack(Jack &card) {
    //TODO                                           //okno wyboru żądanej wartosci karty od 5 do 10, krole karo i trefl
    //stackToInitOn->setDesiredValue(valueToSet);
}
void Stack::initStack(Queen &card) {
    reset();
}

void Stack::initStack(King &card) {
    if(card.getColor()==kier){
        addCardsToPull(5);
    }else if(card.getColor()==pik){
        //TODO                                              //ciagniecie kart przez poprzedniego
    }else{
        return;
    }
}

void Stack::initStack(Ace &card) {
    //TODO                                       //okno wyboru zadanego koloru, zadajacy musi go miec
    //stackToInitOn->setDesiredColor(colorToSet);
}

