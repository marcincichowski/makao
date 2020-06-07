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
        }
    }
}

void Deck::shuffleDeck() {
    if(!cardCollection.empty()) {
        auto rng = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(std::begin(cardCollection), std::end(cardCollection), rng);
    }else{
        std::cout << "Talia jest pusta.\n";
        return;
    }
}

void Deck::drawDeck(sf::RenderWindow &window) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 5;
    float distance = 0;
    int counter = 0;
    float scale = 0.15;
    for(auto card : this->cardCollection){
        if(counter>=5 || card==cardCollection.back()) {break;}else{ counter++; }
        sf::Sprite toDraw = card->drawHidden(scale);
        toDraw.setPosition(sf::Vector2f((1100 + distance), 50+distance));
        window.draw(toDraw);
        distance += widthBetween;
    }
}
