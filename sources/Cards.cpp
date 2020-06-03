//
// Created by Dawid on 14.05.2020.
//

#include "../headers/Cards.h"

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
};
NumericCard::~NumericCard(){}

void NumericCard::initStack(Stack* stackToInitOn){
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

//==================================================================================//


///==================================================================================/
///                                    Jack
///==================================================================================/

Jack::Jack(Color colorToSet) {
    Card::setColor(colorToSet);
    value = walet;
};
Jack::~Jack(){}

Value Jack::getValue() const{
    return value;
}

void Jack::initStack(Stack *stackToInitOn) {
    //TODO                                                      //okno wyboru żądanej wartosci karty od 5 do 10, krole karo i trefl
    //stackToInitOn->setDesiredValue(valueToSet);
}

///==================================================================================/

//==================================================================================//
//                                    Queen
//==================================================================================//

Queen::Queen(Color colorToSet) {
    Card::setColor(colorToSet);
    value = dama;
};
Queen::~Queen(){}

Value Queen::getValue() const{
    return value;
}

void Queen::initStack(Stack *stackToInitOn) {
    stackToInitOn->reset();
}

//==================================================================================//

///==================================================================================/
///                                    King
///==================================================================================/

King::King(Color colorToSet) {
    Card::setColor(colorToSet);
    value = krol;
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

///==================================================================================/

//==================================================================================//
//                                     Ace
//==================================================================================//

Ace::Ace(Color colorToSet) {
    Card::setColor(colorToSet);
    value = as;
};
Ace::~Ace(){}

Value Ace::getValue() const{
    return value;
}

void Ace::initStack(Stack *stackToInitOn) {
    //TODO                                       //okno wyboru zadanego koloru, zadajacy musi go miec
    //stackToInitOn->setDesiredColor(colorToSet);
}

//==================================================================================//

///==================================================================================/
///                                    Joker
///==================================================================================/

Joker::Joker(Color colorToSet) {
    Card::setColor(colorToSet);
    value = joker;
};
Joker::~Joker(){}

Value Joker::getValue() const{
    return value;
}

///==================================================================================/