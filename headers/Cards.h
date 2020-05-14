//
// Created by Dawid on 14.05.2020.
//

#ifndef MAKAO_CARDS_H
#define MAKAO_CARDS_H

#include "Stack.h"

enum Color{ pik, kier, karo, trefl };
enum Value{ dwa = 2,
            trzy = 3,
            cztery = 4,
            piec = 5,
            szesc = 6,
            siedem = 7,
            dsiem = 8,
            dziewiec = 9,
            dziesiec = 10,
            walet = 11,
            dama = 12,
            krol = 13,
            as = 14,
            joker = 15};

class Card{
private:
    Color color;
public:
    Card();
    ~Card();

    virtual void initStack()=0;                 //kazda karta ma inne "zadania" po wejsciu na stos
    virtual void printCard()=0;
    void setColor(Color colorToSet);
    Color getColor();
};

class NumericCard : public Card{
private:
    Value value;

public:
    NumericCard(Color colorToSet, Value valueToSet);
    ~NumericCard();

    virtual void initStack(Stack* stackToInitOn);
};

class Jack : public Card{
private:
    Value value;

public:
    Jack(Color colorToSet);
    ~Jack();
};

class Queen : public Card{
private:
    Value value;

public:
    Queen(Color colorToSet);
    ~Queen();
};

class King : public Card{
private:
    Value value;

public:
    King(Color colorToSet);
    ~King();
};

class Ace  : public Card{
private:
    Value value;

public:
    Ace(Color colorToSet);
    ~Ace();
};

class Joker : public Card{
private:
    Value value;

public:
    Joker(Color colorToSet);
    ~Joker();
};



#endif //MAKAO_CARDS_H
