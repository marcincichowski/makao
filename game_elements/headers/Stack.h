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
    int cardsToPull;                       //liczba kart to pociagniecia, w przypadku 2,3 i krola kier
    int roundsToWait;                     //liczba tur ktore musi przeczekac kolejny gracz bez karty ochronnej gdy >0
    std::vector<std::shared_ptr<Card>> boardStack;           //karty lezace na stole
    Color desiredColor;
    Value desiredValue;
    bool emptyStack;
    bool war;
    bool thrownFour;
    bool givenRounds;
public:

    Stack();
    ~Stack();
    std::vector<std::shared_ptr<Card>>* getBoardStack();
    std::shared_ptr<Card> topCard();
    int getCardCount();
    Color getDesideredColor() const;
    Value getDesideredValue() const;
    void addCardsToPull(int amountToAdd);
    void addRoundsToWait(int amountToAdd);
    int getCardsToPull();
    int getRoundsToWait() const;
    void setDesiredColor(Color desiredColor);
    void setDesiredValue(Value desiredValue);
    std::shared_ptr<Card> pullCard();
    void pushCard(std::shared_ptr<Card> toAdd);
    void reset();                             //dama blokuje wojny i tury do odczekania
    void drawStack(sf::RenderWindow &window);
    bool isLegit(std::shared_ptr<Card>&);
    bool throwToStack(std::shared_ptr<Card>);
    void update();
    bool getWar() const;
    void cancelWar();
    void setWar();
    bool isEmpty();
    bool getThrownFour();
    bool getGivenRounds();
    void setGivenRounds();
    void unsetGivenRounds();
    void resetRoundsToWait();
    void unsetThrownFour();
    void setThrownFour();
};


#endif //MAKAO_STACK_H
