//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_STACK_H
#define MAKAO_STACK_H

#include <stack>

class Card;

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
