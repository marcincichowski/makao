//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
Board::Board(float width, float height, int playerCount){
    deck = std::make_shared<Deck>();
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i)));
        std::cout << "+ Gracz " << i << std::endl;
    }
    activePlayer = *(players.begin());
    //previousPlayer = *(players.end());

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
    float widthBetween = 30;
    float distance = 0;
    for(auto card : activePlayer->hand){
        card->printCard();
        card->setImage();
        sf::Sprite toDraw = card->draw();
        toDraw.setPosition(sf::Vector2f((150+distance), height*0.75));
        window.draw(toDraw);
        distance += widthBetween;
    }
    /*for(auto card : previousPlayer->hand){
        card->printCard();
        card->setImage();
        sf::Sprite toDraw = card->draw();
        toDraw.setPosition(sf::Vector2f((150+distance), height*0.75));
        window.draw(toDraw);
        distance += widthBetween;
    }*/
}

Board::~Board() {}

/*std::shared_ptr<Player> Board::nextPlayer(std::shared_ptr<Player> current) {
    if(current==players.back()){
        return players.front();
    }else{
        return ;
    }
}*/
