#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
#include <iostream>
Board::Board(float width, float height, int playerCount){
    deck = std::make_shared<Deck>();
    stack = std::make_shared<Stack>();

    stack->boardStack.push_back(deck->cardCollection.back());
    deck->cardCollection.pop_back();
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i+1)));
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

    for(int i = 0; i < 4; i++){
        nicknames[i].setFont(font);
        nicknames[i].setColor(sf::Color::White);
        nicknames[i].setString(players.at(i)->getNickname());

    }
    nicknames[0].setPosition(sf::Vector2f(20, 10 + 160 * 3));

    nicknames[1].setPosition(sf::Vector2f(20, 10 + 160 * 0));
    nicknames[2].setPosition(sf::Vector2f(20, 10 + 160 * 1));
    nicknames[3].setPosition(sf::Vector2f(20, 10 + 160 * 2));

    activeOption = 0;
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
    activePlayer->drawHand(window, activeOption);
    for(auto player : players){
        if(player==activePlayer){ continue;}
        else{
            player->drawHiddenHand(window);
        }
    }
    deck->drawDeck(window);
    //std::cout << stack->getCardCount();
    stack->drawStack(window);

    for(int i = 0; i < 4; i++){
        window.draw(nicknames[i]);
    }

    //buttons nastepna tura + dobierz
    window.draw(buttons[0]);
    window.draw(buttons[1]);
}

Board::~Board() {}

/*std::shared_ptr<Player> Board::nextPlayer(std::shared_ptr<Player> current) {
    if(current==players.back()){
        return players.front();
    }else{
        return ;
    }
}*/
void Board::moveRight() {
    if(activeOption + 1 < activePlayer->hand.capacity())
        activeOption++;
}

void Board::moveLeft() {
    if(activeOption - 1 >= 0)
        activeOption--;
}

void Board::getPressed() {

}