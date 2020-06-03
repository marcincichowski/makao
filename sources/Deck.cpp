//
// Created by Dawid on 12.05.2020.
//

#include <algorithm>
#include <random>
#include <iostream>
#include "../headers/Deck.h"

class Card;

Deck::Deck() {
    std::cout << "Tworze karty..\n";
    createCards();

    std::cout << "Tasuje karty..\n";
    shuffleDeck();
}

Deck::~Deck(){ std::cout << "Niszcze talie..\n"; }

void Deck::createCards(){               //tworzenie wszystkich kart
    for(auto color : all_Colors){
        cardCollection.push_back(new Jack(color));
        std::cout << "Stworzono Waleta o kolorze " << color << std::endl;
    }
    for(auto color : all_Colors){
        cardCollection.push_back(new Queen(color));
        std::cout << "Stworzono Dame o kolorze " << color << std::endl;
    }
    for(auto color : all_Colors){
        cardCollection.push_back(new King(color));
        std::cout << "Stworzono Krola o kolorze " << color << std::endl;
    }
    for(auto color : all_Colors){
        cardCollection.push_back(new Ace(color));
        std::cout << "Stworzono Asa o kolorze " << color << std::endl;
    }

}

void Deck::shuffleDeck() {
    if(!cardCollection.empty()) {
        std::shuffle(std::begin(cardCollection), std::end(cardCollection), std::default_random_engine{});
    }else{
        std::cout << "Talia jest pusta.\n";
        return;
    }
}