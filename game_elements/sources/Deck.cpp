//
// Created by Dawid on 12.05.2020.
//

#include <algorithm>
#include <random>
#include <memory>
#include <iostream>
#include <chrono>
#include "../headers/Deck.h"

class Card;

Deck::Deck() {
    createCards();
    shuffleDeck();
}

Deck::~Deck(){}

void Deck::createCards(){               //tworzenie wszystkich kart
    for(auto color : all_Colors){
        getCardCollection()->push_back(std::make_shared<Jack>(color));
        getCardCollection()->push_back(std::make_shared<Queen>(color));
        getCardCollection()->push_back(std::make_shared<King>(color));
        getCardCollection()->push_back(std::make_shared<Ace>(color));
    }
    for (int i = 0; i < Value::walet; ++i) {
        for (auto color : all_Colors) {
            getCardCollection()->push_back(std::make_shared<NumericCard>(color, (Value) i));
        }
    }
}

void Deck::shuffleDeck() {
    if(!getCardCollection()->empty()) {
        auto rng = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(std::begin(cardCollection), std::end(cardCollection), rng);
    }else{
        return;
    }
}

void Deck::drawDeck(sf::RenderWindow &window) {
    float widthBetween = 5;
    float distance = 0;
    int counter = 0;
    float scale = 0.15;
    for(auto &card : this->cardCollection){
        if(counter>=5) { return;}else{ counter++; }
        toDraw = card->drawHidden(scale);
        toDraw.setPosition(sf::Vector2f((1100 + distance), 50+distance));
        window.draw(toDraw);
        distance += widthBetween;
    }
}

std::vector<std::shared_ptr<Card>> *Deck::getCardCollection() {
    return &cardCollection;
}
