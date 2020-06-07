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

sf::Sprite Card::draw(float scale) {
    texture.loadFromFile(this->generatePath());
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(scale,scale);
    return sprite;
}

sf::Sprite Card::drawHidden(float scale) {
    texture.loadFromFile("../resources/cards/reverse.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(scale,scale);
    return sprite;
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

//==================================================================================//
//                                NumericCard
//==================================================================================//

NumericCard::NumericCard(Color colorToSet, Value valueToSet) {
    Card::setColor(colorToSet);
    Card::setValue(valueToSet);
    //std::cout << "Stworzono Karte o kolorze " << colorToSet << " oraz wartosci " << valueToSet << std::endl;
};
NumericCard::~NumericCard(){}


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
    //std::cout << "Stworzono Waleta o kolorze " << colorToSet << std::endl;
};
Jack::~Jack(){}

Value Jack::getValue() const{
    return this->getValue();
}


///==================================================================================/

//==================================================================================//
//                                    Queen
//==================================================================================//

Queen::Queen(Color colorToSet) {
    Card::setColor(colorToSet);
    Card::setValue(Value::dama);
    //std::cout << "Stworzono Dame o kolorze " << colorToSet << std::endl;
};
Queen::~Queen(){}

Value Queen::getValue() const{
    return this->getValue();
}



//==================================================================================//

///==================================================================================/
///                                    King
///==================================================================================/

King::King(Color colorToSet) {
    Card::setColor(colorToSet);
    Card::setValue(Value::krol);
    //std::cout << "Stworzono Krola o kolorze " << colorToSet << std::endl;
};
King::~King(){}



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
    //std::cout << "Stworzono Asa o kolorze " << colorToSet << std::endl;
};
Ace::~Ace(){}

Value Ace::getValue() const{
    return this->getValue();
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