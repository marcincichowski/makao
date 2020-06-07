//
// Created by Dawid on 14.05.2020.
//

#ifndef MAKAO_CARDS_H
#define MAKAO_CARDS_H

#include "Stack.h"
#include <SFML/Graphics.hpp>

class Stack;

class Card{
private:
    Color color;
    Value value;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Card();
    ~Card();

    virtual void initStack(Stack* stackToInitOn)=0;            //kazda karta ma inne "zadania" po wejsciu na stos

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
    virtual void initStack(Stack* stackToInitOn);
};

class Jack : public Card{
public:
    Jack(Color colorToSet);
    ~Jack();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
};

class Queen : public Card{
public:
    Queen(Color colorToSet);
    ~Queen();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
};

class King : public Card{
public:
    King(Color colorToSet);
    ~King();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
};

class Ace : public Card{
public:
    Ace(Color colorToSet);
    ~Ace();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
};

/*class Joker : public Card{
private:
    Value value;

public:
    Joker(Color colorToSet);
    ~Joker();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
};*/



#endif //MAKAO_CARDS_H
