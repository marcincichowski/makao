//
// Created by Dawid on 12.05.2020.
//

#include "../headers/Stack.h"

Stack::Stack() {
    roundsToWait = 0;
    cardsToPull = 0;
    emptyStack = true;

}
Stack::~Stack() {}

int Stack::getCardCount() { return getBoardStack()->size(); }

void Stack::addCardsToPull(int amountToAdd) { cardsToPull+=amountToAdd; war=true;}
void Stack::addRoundsToWait(int amountToAdd) { roundsToWait+=amountToAdd; }

void Stack::pushCard(std::shared_ptr<Card> toAdd) { getBoardStack()->push_back(toAdd); }

std::shared_ptr<Card> Stack::pullCard() {
    return getBoardStack()->back();
    getBoardStack()->pop_back();
}

int Stack::getCardsToPull(){
    return cardsToPull;
}

int Stack::getRoundsToWait() const {
    return roundsToWait;
}

void Stack::resetRoundsToWait(){
    roundsToWait = 0;
}

void Stack::reset() {
    cardsToPull = 0;
    war=false;
}

std::shared_ptr<Card> Stack::topCard() {
   if(getBoardStack()->size()>0){return getBoardStack()->back();}
   else{ return nullptr; }
}

void Stack::setDesiredColor(Color colorToSet) {
    Stack::desiredColor = colorToSet;
}

void Stack::setDesiredValue(Value colorToSet) {
    Stack::desiredValue = colorToSet;
}

void Stack::drawStack(sf::RenderWindow &window) {
    if(getBoardStack()->empty()){
        return;
    }
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 5;
    float distance = 5;
    float scale = 0.15;
    int n = getBoardStack()->size();
    int total = (n < 5 ? n = getBoardStack()->size() : 5);
    int x = (getBoardStack()->size() - 1) >= 5 ? 5 : getBoardStack()->size() - 1;
    if (getBoardStack()->size() - 1 > 0) {
        for (int i = 0; i < x; i++) {
            sf::Sprite toDraw = boardStack[i + 1]->draw(scale);
            toDraw.setPosition(sf::Vector2f(width / 2 + distance - 50, height / 2 + distance - 140));
            window.draw(toDraw);
            distance += widthBetween;
        }
    }
    getBoardStack()->back()->draw(scale);
    sf::Sprite toDraw = getBoardStack()->back()->draw(scale);
    toDraw.setPosition(sf::Vector2f(width / 2 +distance- 50, height / 2+distance - 140));

    window.draw(toDraw);
}


bool Stack::isLegit(std::shared_ptr<Card> &cardToCheck) {
    std::string valueToCheck = cardToCheck->printValue();
    std::string colorToCheck = cardToCheck->printColor();

    if(emptyStack==true){ return true;}
    if (war == true) {
        if ((valueToCheck == "2") || (valueToCheck == "3") || (valueToCheck == "K" && colorToCheck == "H") ||
            (valueToCheck == "Q" && colorToCheck == "H")) {
            //std::cout << "Wojna git";
            return true;
        } else {
            //std::cout << "Wojna zle";
            return false;
        }
    } else {
        if (this->topCard()->getValue() == cardToCheck->getValue() ||
            this->topCard()->getColor() == cardToCheck->getColor()) {
            //std::cout << "Nie wojna git";
            return true;
        } else {
            //std::cout << "Nie wojna zle";
            return false;
        }
    }
}


bool Stack::throwToStack(std::shared_ptr<Card> cardToCheck){
    if(isLegit(cardToCheck)){
        getBoardStack()->push_back(cardToCheck);
        return true;
    }else{
        //std::cout << "Ta karta nie moze zostac wyrzucona na stos!\n";
        return false;
    }
}

void Stack::update() {
    if(getBoardStack()->empty()){
        emptyStack = true;
    }else{
        emptyStack = false;
    }
    if(this->getBoardStack()->back()->printValue()=="2"){
        addCardsToPull(2);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->getBoardStack()->back()->printValue()=="3"){
        addCardsToPull(3);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->getBoardStack()->back()->printValue()=="K" && this->topCard()->printColor()=="H"){
        addCardsToPull(5);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->getBoardStack()->back()->printValue()=="Q"&& this->topCard()->printColor()=="H"){
        reset();
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->getBoardStack()->back()->printValue()=="4"){
        if(freshFour) { addRoundsToWait(1); }
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else{
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    if(cardsToPull==0){
        war=false;
    }else{
        war = true;
    }

}

Color Stack::getDesideredColor() const {
    return desiredColor;
}

Value Stack::getDesideredValue() const {
    return desiredValue;
}

bool Stack::getWar() const {
    return war;
}

void Stack::cancelWar() {
    war = false;
    cardsToPull = 0;
}

bool Stack::isEmpty() {
    return emptyStack;
}

void Stack::setWar() {
    war = true;
}

std::vector<std::shared_ptr<Card>> *Stack::getBoardStack() {
    return &boardStack;
}

bool Stack::getThrownFour() {
    return freshFour;
}

void Stack::unsetFreshFour() {
    freshFour =false;
}

void Stack::setFreshFour() {
    freshFour = true;
}

