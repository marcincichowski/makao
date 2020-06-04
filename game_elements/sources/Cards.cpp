//
// Created by Dawid on 14.05.2020.
//

#include "../headers/Cards.h"
#include <iostream>

///==================================================================================/
///                                    Card
///==================================================================================/

Card::Card(){}
Card::~Card(){}

void Card::setColor(Color colorToSet){
    color = colorToSet;
}
Color Card::getColor() const{ return color; }

//==================================================================================//
//                                NumericCard
//==================================================================================//

NumericCard::NumericCard(Color colorToSet, Value valueToSet) : value(valueToSet) {
    Card::setColor(colorToSet);
    std::cout << "Stworzono Karte o kolorze " << colorToSet << " oraz wartosci " << valueToSet << std::endl;
};
NumericCard::~NumericCard(){}

void NumericCard::initStack(Stack *stackToInitOn) {
      if(value == 2 || value == 3){
          stackToInitOn->addCardsToPull(value);
      }else if(value == 4){
          stackToInitOn->addRoundsToWait(1);
      }else{
          return;
      }
}

Value NumericCard::getValue() const{
    return value;
}

void NumericCard::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}

//==================================================================================//


///==================================================================================/
///                                    Jack
///==================================================================================/

Jack::Jack(Color colorToSet) {
    Card::setColor(colorToSet);
    value = walet;
    std::cout << "Stworzono Waleta o kolorze " << colorToSet << std::endl;
};
Jack::~Jack(){}

Value Jack::getValue() const{
    return value;
}

void Jack::initStack(Stack *stackToInitOn) {
    //TODO                                                      //okno wyboru żądanej wartosci karty od 5 do 10, krole karo i trefl
    //stackToInitOn->setDesiredValue(valueToSet);
}

void Jack::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}

///==================================================================================/

//==================================================================================//
//                                    Queen
//==================================================================================//

Queen::Queen(Color colorToSet) {
    Card::setColor(colorToSet);
    value = dama;
    std::cout << "Stworzono Dame o kolorze " << colorToSet << std::endl;
};
Queen::~Queen(){}

Value Queen::getValue() const{
    return value;
}

void Queen::initStack(Stack *stackToInitOn) {
    stackToInitOn->reset();
}

void Queen::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}

//==================================================================================//

///==================================================================================/
///                                    King
///==================================================================================/

King::King(Color colorToSet) {
    Card::setColor(colorToSet);
    value = krol;
    std::cout << "Stworzono Krola o kolorze " << colorToSet << std::endl;
};
King::~King(){}

void King::initStack(Stack *stackToInitOn) {
    if(this->getColor()==kier){
        stackToInitOn->addCardsToPull(5);
    }else if(this->getColor()==pik){
        //TODO                                              //ciagniecie kart przez poprzedniego
    }else{
        return;
    }
}

Value King::getValue() const{
    return value;
}

void King::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}

///==================================================================================/

//==================================================================================//
//                                     Ace
//==================================================================================//

Ace::Ace(Color colorToSet) {
    Card::setColor(colorToSet);
    value = as;
    std::cout << "Stworzono Asa o kolorze " << colorToSet << std::endl;
};
Ace::~Ace(){}

Value Ace::getValue() const{
    return value;
}

void Ace::initStack(Stack *stackToInitOn) {
    //TODO                                       //okno wyboru zadanego koloru, zadajacy musi go miec
    //stackToInitOn->setDesiredColor(colorToSet);
}

void Ace::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}

//==================================================================================//

///==================================================================================/
///                                    Joker
///==================================================================================/

/*Joker::Joker(Color colorToSet) {
    Card::setColor(colorToSet);
    value = joker;
};
Joker::~Joker(){}

Value Joker::getValue() const{
    return value;
}

void Joker::initStack(Stack *stackToInitOn) {
    return;
}

void Joker::printCard() {
    std::cout << this->getValue() << " " << this->getColor() << std::endl;
}*/

///==================================================================================/