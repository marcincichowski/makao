//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
Board::Board(float width, float height, int playerCount){
    for(int i = 0;i<playerCount;i++) {

    }
    giveaway();
}

void Board::giveaway() {
    for(auto player : players){
        for(int i = 0;i<5;i++){
            player->hand.push_back(deck->cardCollection.back());
            deck->cardCollection.pop_back();
        }
    }
}

int Board::getPlayerCount() const {
    return players.capacity();
}

void Board::draw(sf::RenderWindow &window) {
    int width = window.getSize().x;
    int height = window.getSize().y;
    int count = 1;
    for(auto card : activePlayer->hand){
        sf::Sprite toDraw = card->draw();
        toDraw.setPosition(sf::Vector2f(width / count * count, height / 5));
        window.draw(toDraw);
        count++;
    }
}

Board::~Board() {

}
