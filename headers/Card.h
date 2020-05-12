//
// Created by Dawid on 12.05.2020.
//
#ifndef MAKAO_CARD_H
#define MAKAO_CARD_H

#include <string>

class Card {
private:
    std::string sign;           //znak karty
    std::string color;          //kolor karty
    bool isSpecial;

public:
    Card(std::string, std::string);
    ~Card();

    std::string getSign();       //zwraca znak
    std::string getColor();        //zwraca kolor

    void displayCardInfo() const;
};

#endif //MAKAO_CARD_H
