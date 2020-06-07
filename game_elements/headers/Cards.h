//
// Created by Dawid on 14.05.2020.
//

#ifndef MAKAO_CARDS_H
#define MAKAO_CARDS_H

#include <SFML/Graphics.hpp>
#include <memory>

class Stack;

enum Color{ pik = 0, kier, karo, trefl};
enum Value{ dwa = 0,
    trzy,
    cztery,
    piec,
    szesc,
    siedem,
    osiem,
    dziewiec,
    dziesiec,
    walet,
    dama,
    krol,
    as};

constexpr std::initializer_list<Value> all_Values = {dwa,trzy,cztery,piec,szesc,siedem,osiem,dziewiec,dziesiec,walet,dama,krol,as};
constexpr std::initializer_list<Color > all_Colors = {pik,kier,karo,trefl};

std::ostream& operator<< (std::ostream& out, const Color& color);
std::ostream& operator<< (std::ostream& out, const Value& color);

class Card{
private:
    Color color;
    Value value;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Card();
    ~Card();

    void printCard();

    std::string generatePath();
    sf::Sprite draw(float scale);
    sf::Sprite drawHidden(float scale);

    std::string printColor();
    std::string printValue();

    Color getColor()const;
    Value getValue()const;

    void setColor(Color);
    void setValue(Value);

};



class NumericCard : public Card{
public:
    NumericCard(Color colorToSet, Value valueToSet);
    ~NumericCard();

    virtual Value getValue()const;
};

class Jack : public Card{
public:
    Jack(Color colorToSet);
    ~Jack();

    virtual Value getValue()const;
};

class Queen : public Card{
public:
    Queen(Color colorToSet);
    ~Queen();

    virtual Value getValue()const;
};

class King : public Card{
public:
    King(Color colorToSet);
    ~King();

    virtual Value getValue()const;
};

class Ace : public Card{
public:
    Ace(Color colorToSet);
    ~Ace();

    virtual Value getValue()const;
};

#endif //MAKAO_CARDS_H
