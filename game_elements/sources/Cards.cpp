//
// Created by Dawid on 14.05.2020.
//

#include "../headers/Cards.h"
#include <iostream>

///==================================================================================/
///                                    Card
///==================================================================================/

Card::Card(){

}
Card::~Card(){}

Color Card::getColor() const{ return color; }
std::string printColor();
Value Card::getValue() const { return value; }
std::string printValue();

void Card::setValue(Value valueToSet) {
    value = valueToSet;
}

void Card::setColor(Color colorToSet){
    color = colorToSet;
}

void Card::printCard() {
    std::cout  << this->getValue() << this->getColor() << std::endl;
}

std::string Card::generatePath() {
    std::string col = this->printColor();
    std::string val = this->printValue();
    return ("../resources/cards/"+val+col+".png");
}

std::string Card::printColor() {
    switch (color) {
        case pik: return "S";
        case kier: return "H";
        case karo: return "D";
        case trefl: return "C";
    }
}

std::string Card::printValue() {
    switch (value) {
        case dwa: return "2";
        case trzy: return "3";
        case cztery: return "4";
        case piec: return "5";
        case szesc: return "6";
        case siedem: return "7";
        case osiem: return "8";
        case dziewiec: return "9";
        case dziesiec: return "10";
        case walet: return "J";
        case dama: return "Q";
        case krol: return "K";
        case as: return "A";
    }
}

void Card::setImage() {
    return;
}

sf::Sprite Card::draw() {
    texture.loadFromFile(this->generatePath());
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.15,0.15);
    return sprite;
}

//==================================================================================//
//                                NumericCard
//==================================================================================//

NumericCard::NumericCard(Color colorToSet, Value valueToSet) {
    Card::setColor(colorToSet);
    Card::setValue(valueToSet);
    this->setImage();
    //std::cout << "Stworzono Karte o kolorze " << colorToSet << " oraz wartosci " << valueToSet << std::endl;
};
NumericCard::~NumericCard(){}

void NumericCard::initStack(Stack *stackToInitOn) {
      if(this->getValue() == 2 || this->getValue() == 3){
          stackToInitOn->addCardsToPull(this->getValue());
      }else if(this->getValue() == 4){
          stackToInitOn->addRoundsToWait(1);
      }else{
          return;
      }
}

Value NumericCard::getValue() const{
    return this->getValue();
}

//==================================================================================//


///==================================================================================/
///                                    Jack
///==================================================================================/

Jack::Jack(Color colorToSet) {
    Card::setColor(colorToSet);
    Card::setValue(Value::walet);
    this->setImage();
    //std::cout << "Stworzono Waleta o kolorze " << colorToSet << std::endl;
};
Jack::~Jack(){}

Value Jack::getValue() const{
    return this->getValue();
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
    Card::setValue(Value::dama);
    this->setImage();
    //std::cout << "Stworzono Dame o kolorze " << colorToSet << std::endl;
};
Queen::~Queen(){}

Value Queen::getValue() const{
    return this->getValue();
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
    Card::setValue(Value::krol);
    this->setImage();
    //std::cout << "Stworzono Krola o kolorze " << colorToSet << std::endl;
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
    return this->getValue();
}
///==================================================================================/

//==================================================================================//
//                                     Ace
//==================================================================================//

Ace::Ace(Color colorToSet) {
    Card::setColor(colorToSet);
    Card::setValue(Value::as);
    this->setImage();
    //std::cout << "Stworzono Asa o kolorze " << colorToSet << std::endl;
};
Ace::~Ace(){}

Value Ace::getValue() const{
    return this->getValue();
}

void Ace::initStack(Stack *stackToInitOn) {
    //TODO                                       //okno wyboru zadanego koloru, zadajacy musi go miec
    //stackToInitOn->setDesiredColor(colorToSet);
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