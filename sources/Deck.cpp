//
// Created by Dawid on 12.05.2020.
//

#include <algorithm>
#include <random>
#include <iostream>
#include "../headers/Deck.h"

Deck::Deck() {
    std::cout << "Tworze karty..\n";
    createCards();

    std::cout << "Tasuje karty..\n";
    shuffleDeck();
}

Deck::~Deck(){ std::cout << "Niszcze talie..\n"; }

void Deck::createCards(){               //tworzenie wszystkich kart
    //TODO
}

void Deck::shuffleDeck() {
    if(!cardCollection.empty()) {
        std::shuffle(std::begin(cardCollection), std::end(cardCollection), std::default_random_engine{});
    }else{
        std::cout << "Talia jest pusta.\n";
        return;
    }
}