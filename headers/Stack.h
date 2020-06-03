//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_STACK_H
#define MAKAO_STACK_H

#include <stack>
#include <iostream>

class Card;

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

class Stack {
private:
    std::stack<Card*> boardStack;           //karty lezace na stole
    int cardCount;                         //liczba kart na stosie
    int cardsToPull;                       //liczba kart to pociagniecia, w przypadku 2,3 i krola kier
    int roundsToWait;                     //liczba tur ktore musi przeczekac kolejny gracz bez karty ochronnej gdy >0
    Color desiredColor;
    Value desiredValue;

public:
    Stack();
    ~Stack();

    int getCardCount();

    void addCardsToPull(int amountToAdd);
    void addRoundsToWait(int amountToAdd);

    int getCardsToPull() const;
    int getRoundsToWait() const;

    void setDesiredColor(Color desiredColor);
    void setDesiredValue(Value desiredValue);

    Card* pullCard();
    void pushCard(Card *toAdd);
    Card* topCard();


    void reset();                             //dama blokuje wojny i tury do odczekania

};


#endif //MAKAO_STACK_H
