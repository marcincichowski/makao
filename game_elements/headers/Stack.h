//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_STACK_H
#define MAKAO_STACK_H

#include <stack>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Cards.h"

class Stack {
private:
    int cardCount;                         //liczba kart na stosie
    int cardsToPull;                       //liczba kart to pociagniecia, w przypadku 2,3 i krola kier
    int roundsToWait;                     //liczba tur ktore musi przeczekac kolejny gracz bez karty ochronnej gdy >0
    Color desiredColor;
    Value desiredValue;
    bool war;

public:
    std::vector<std::shared_ptr<Card>> boardStack;           //karty lezace na stole
    Stack();
    ~Stack();
    std::shared_ptr<Card> topCard();

    int getCardCount();

    void addCardsToPull(int amountToAdd);
    void addRoundsToWait(int amountToAdd);

    int getCardsToPull() const;
    int getRoundsToWait() const;

    void setDesiredColor(Color desiredColor);
    void setDesiredValue(Value desiredValue);

    std::shared_ptr<Card> pullCard();

    void pushCard(std::shared_ptr<Card> toAdd);

    void reset();                             //dama blokuje wojny i tury do odczekania

    void drawStack(sf::RenderWindow &window);

    //INITS
    void initStack(NumericCard &card);
    void initStack(Jack &card);
    void initStack(Queen &card);
    void initStack(King &card);
    void initStack(Ace &card);

    bool isLegit(std::shared_ptr<Card>&);
    bool throwCard(std::shared_ptr<Card>&);
    void update();
};


#endif //MAKAO_STACK_H
