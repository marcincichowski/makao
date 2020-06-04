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
    sf::Texture image;
public:
    Card();
    ~Card();

    virtual void initStack(Stack* stackToInitOn)=0;                 //kazda karta ma inne "zadania" po wejsciu na stos
    virtual void printCard()=0;
    virtual Value getValue()const=0;
    void setColor(Color colorToSet);
    Color getColor()const;

};



class NumericCard : public Card{
private:
    Value value;

public:
    NumericCard(Color colorToSet, Value valueToSet);
    ~NumericCard();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
};

class Jack : public Card{
private:
    Value value;

public:
    Jack(Color colorToSet);
    ~Jack();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
};

class Queen : public Card{
private:
    Value value;

public:
    Queen(Color colorToSet);
    ~Queen();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
};

class King : public Card{
private:
    Value value;

public:
    King(Color colorToSet);
    ~King();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
};

class Ace : public Card{
private:
    Value value;

public:
    Ace(Color colorToSet);
    ~Ace();

    virtual Value getValue()const;
    virtual void initStack(Stack* stackToInitOn);
    virtual void printCard();
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
