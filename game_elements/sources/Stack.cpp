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

int Stack::getCardCount() { return boardStack.size(); }

void Stack::addCardsToPull(int amountToAdd) { cardsToPull+=amountToAdd; war=true;}
void Stack::addRoundsToWait(int amountToAdd) { roundsToWait+=amountToAdd; }

void Stack::pushCard(std::shared_ptr<Card> toAdd) { boardStack.push_back(toAdd); }

std::shared_ptr<Card> Stack::pullCard() {
    return boardStack.back();
    boardStack.pop_back();
}

int Stack::getCardsToPull(){
    return cardsToPull;
}

int Stack::getRoundsToWait() const {
    return roundsToWait;
}

void Stack::reset() {
    cardsToPull = 0;
    roundsToWait = 0;
    war=false;
}

std::shared_ptr<Card> Stack::topCard() {
   if(boardStack.size()>0){return boardStack.back();}
   else{ return nullptr; }
}

void Stack::setDesiredColor(Color colorToSet) {
    Stack::desiredColor = colorToSet;
}

void Stack::setDesiredValue(Value colorToSet) {
    Stack::desiredValue = colorToSet;
}

void Stack::drawStack(sf::RenderWindow &window) {
    if(boardStack.empty()){
        return;
    }
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 5;
    float distance = 5;
    float scale = 0.15;
    int n = boardStack.size();
    int total = (n < 5 ? n = boardStack.size() : 5);
    int x = (boardStack.size() - 1) >= 5 ? 5 : boardStack.size() - 1;
    if (boardStack.size() - 1 > 0) {
        for (int i = 0; i < x; i++) {
            sf::Sprite toDraw = boardStack[i + 1]->draw(scale);
            toDraw.setPosition(sf::Vector2f(width / 2 + distance - 50, height / 2 + distance - 140));
            window.draw(toDraw);
            distance += widthBetween;
        }
    }
    boardStack.back()->draw(scale);
    sf::Sprite toDraw = boardStack.back()->draw(scale);
    toDraw.setPosition(sf::Vector2f(width / 2 +distance- 50, height / 2+distance - 140));

    window.draw(toDraw);
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

bool Stack::isLegit(std::shathred_ptr<Card> &cardToCheck) {
    std::string valueToCheck = cardToCheck->printValue();
    std::string colorToCheck = cardToCheck->printColor();

    /*if(this->topCard()->getValue()!=valueToCheck && this->topCard()->getColor()!=colorToCheck && war){
        return false;
    }else if(war){
        if(this->topCard()->printValue()!="2" || this->topCard()->printValue()!="3" || this->topCard()->printValue()!="K"){
            return false;
        }else{
            return true;
        }
    }else{
        return true;
    }*/
    if(emptyStack==true){ return  true;}
    if (war == true) {
        if ((valueToCheck == "2") || (valueToCheck == "3") || (valueToCheck == "K" && colorToCheck == "D") ||
            (valueToCheck == "Q" && colorToCheck == "H")) {
            std::cout << "Wojna git";
            return true;
        } else {
            std::cout << "Wojna zle";
            return false;
        }
    } else {
        if (this->topCard()->getValue() == cardToCheck->getValue() ||
            this->topCard()->getColor() == cardToCheck->getColor()) {
            std::cout << "Nie wojna git";
            return true;
        } else {
            std::cout << "Nie wojna zle";
            return false;
        }
    }
}


bool Stack::throwToStack(std::shared_ptr<Card> cardToCheck){
    if(isLegit(cardToCheck)){
        boardStack.push_back(cardToCheck);
        return true;
    }else{
        std::cout << "Ta karta nie moze zostac wyrzucona na stos!\n";
        return false;
    }
}

void Stack::update() {
    if(boardStack.empty()){
        emptyStack = true;
    }else{
        emptyStack = false;
    }
    if(this->boardStack.back()->printValue()=="2"){
        addCardsToPull(2);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->boardStack.back()->printValue()=="3"){
        addCardsToPull(3);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->boardStack.back()->printValue()=="K" && this->topCard()->printColor()=="H"){
        addCardsToPull(5);
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->boardStack.back()->printValue()=="Q"&& this->topCard()->printColor()=="D"){
        reset();
        setDesiredValue(topCard()->getValue());
        setDesiredColor(topCard()->getColor());
    }
    else if(this->boardStack.back()->printValue()=="4"){
        addRoundsToWait(1);
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

