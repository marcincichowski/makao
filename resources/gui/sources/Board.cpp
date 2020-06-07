//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
Board::Board(float width, float height, int playerCount){
    deck = std::make_shared<Deck>();
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i)));
        players.back()->setNo(i);
        std::cout << "+ Gracz " << i << std::endl;
    }
    activePlayer = *(players.begin());
    //previousPlayer = *(players.end());
    giveaway();

    //SET PROPERTIES OF BUTTONS
    if(!font.loadFromFile("../assets/fonts/arial.TTF")){
        std::cout<<"error font loading";
    }

    buttons[0].setFont(font);
    buttons[0].setColor(sf::Color::White);
    buttons[0].setString(L"Dobierz Kartę");
    buttons[0].setPosition(sf::Vector2f(width/1.5,height*0.75));

    buttons[1].setFont(font);
    buttons[1].setColor(sf::Color::White);
    buttons[1].setString(L"Koniec Tury");
    buttons[1].setPosition(sf::Vector2f(width/1.5,height*0.75 + 60));

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
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    sf::Texture deckTexture;
    deckTexture.loadFromFile("../resources/cards/reverse.png");
    sf::Sprite deckSprite;
    deckSprite.setTexture(deckTexture);
    deckSprite.setScale(0.1,0.1);
    deckSprite.setPosition(sf::Vector2f(width/2, height/2 -100));
    window.draw(deckSprite);
    activePlayer->drawHand(window);
    for(auto player : players){
        if(player==activePlayer){ continue;}
        else{
            player->drawHiddenHand(window);
        }
    }


    //buttons nastepna tura + dobierz

    window.draw(buttons[0]);
    window.draw(buttons[1]);

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
