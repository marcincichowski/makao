//
// Created by Dawid on 12.05.2020.
//

#include <algorithm>
#include <random>
#include <memory>
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
        cardCollection.push_back(std::make_shared<Jack>(color));
        cardCollection.push_back(std::make_shared<Queen>(color));
        cardCollection.push_back(std::make_shared<King>(color));
        cardCollection.push_back(std::make_shared<Ace>(color));
    }
    for (int i = 0; i < Value::walet; ++i) {
        for (auto color : all_Colors) {
            cardCollection.push_back(std::make_shared<NumericCard>(color, (Value) i));
            std::cout << "Stworzono karte o kolorze " << color << " oraz wartosci " << (Value) i << std::endl;
        }
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