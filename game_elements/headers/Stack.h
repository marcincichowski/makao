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
#include "Player.h"

class Stack {
private:
    int cardsToPull;                       //liczba kart to pociagniecia, w przypadku 2,3 i krola kier
    int roundsToWait;                     //liczba tur ktore musi przeczekac kolejny gracz bez karty ochronnej gdy >0
    std::vector<std::shared_ptr<Card>> boardStack;           //karty lezace na stole
    Color desiredColor;
    Value desiredValue;
    bool emptyStack;
    bool war;
    bool freshFour;
    bool freezedBefore;
    bool wantedColor;
    bool wantedValue;
    sf::Sprite toDraw;
    std::string valueToCheck;
    std::string colorToCheck;
public:
    Stack();
    ~Stack();
    std::vector<std::shared_ptr<Card>>* getBoardStack();
    std::shared_ptr<Card> topCard();
    void addCardsToPull(int amountToAdd);
    void addRoundsToWait(int amountToAdd);
    int getCardsToPull();
    int getRoundsToWait() const;
    void setDesiredColor(Color desiredColor);
    void setDesiredValue(Value desiredValue);
    void reset();                             //dama blokuje wojny i tury do odczekania
    void drawStack(sf::RenderWindow &window);
    bool isLegit(std::shared_ptr<Card>&);
    bool throwToStack(std::shared_ptr<Card>);
    void update(bool);
    bool getWar() const;
    void cancelWar();
    void resetRoundsToWait();
    void unsetFreshFour();
    void setFreshFour();
    void setWantedColor();
    void setWantedValue();
    void unsetWantedColor();
    void unsetWantedValue();
    void setFreezedBefore();
    void unsetFreezenBefore();
    bool getFreezedBefore();
};


#endif //MAKAO_STACK_H
