//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
#include <iostream>
#include <iterator>
#include <unordered_set>

Board::Board(float width, float height, int playerCount){
    round=0;
    IS_NEW_ROUND = true;
    deck = std::make_shared<Deck>();
    stack = std::make_shared<Stack>();

    stack->boardStack.push_back(deck->cardCollection.back());
    deck->cardCollection.pop_back();
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i+1)));
        players.back()->setNo(i);
        std::cout << "+ Gracz " << i << std::endl;
    }
    activePlayer = players.at(0);
    previousPlayer = players.at(3);
    nextPlayer = players.at(1);
    lastPlayer = players.at(2);
    giveaway();

    //SET PROPERTIES OF BUTTONS
    if(!font.loadFromFile("../assets/fonts/arial.TTF")){
        std::cout<<"error font loading";
    }

    buttons[0].setFont(font);
    buttons[0].setColor(sf::Color::White);
    buttons[0].setString(L"Dobierz kartę i zakończ turę");
    buttons[0].setPosition(sf::Vector2f(width/1.5,10+160*3));
/*
    buttons[1].setFont(font);
    buttons[1].setColor(sf::Color::White);
    buttons[1].setString(L"Koniec Tury");
    buttons[1].setPosition(sf::Vector2f(width/1.5,height*0.75 + 60));*/

    for(int i = 0; i < 4; i++){
        nicknames[i].setFont(font);
        nicknames[i].setColor(sf::Color::White);
        nicknames[i].setString(players.at(i)->getNickname());

    }
    nicknames[0].setPosition(sf::Vector2f(20, 10 + 160 * 3));
    nicknames[1].setPosition(sf::Vector2f(20, 10 + 160 * 0));
    nicknames[2].setPosition(sf::Vector2f(20, 10 + 160 * 1));
    nicknames[3].setPosition(sf::Vector2f(20, 10 + 160 * 2));

    newRoundText.setFont(font);
    newRoundText.setColor(sf::Color::White);
    newRoundText.setString(L"Naciśnij spację aby przejść do następnego gracza");
    newRoundText.setPosition(sf::Vector2f(width/2 - 350, height/2 - 20));

    activeButton = 0;
    activeOption = 0;
    option = false;

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

int Board::getActivePlayerHandSize(){
    return activePlayer->hand.size();
}

void Board::draw(sf::RenderWindow &window) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    float widthBetween = 30;
    float distance = 0;
    int no = 0;
    if(!IS_NEW_ROUND){
        activePlayer->drawHand(window, activeOption);
        for(auto player : players){
            if(player==activePlayer){ continue;}
            else{
                player->drawHiddenHand(window,no);
            }
            no++;
        }
        updateNicknames();
        deck->drawDeck(window);
        //std::cout << stack->getCardCount();
        stack->drawStack(window);

        for(int i = 0; i < 4; i++){
            window.draw(nicknames[i]);
        }

        window.draw(buttons[0]);
        window.draw(buttons[1]);
    }
    else{
        window.draw(newRoundText);
    }



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
    if(activeOption + 1 < activePlayer->hand.size())
        activeOption++;
    else{
        activeOption = activePlayer->hand.size() + 1;
        if(activeButton == 0){
            if(option){
                buttons[activeButton].setColor(sf::Color::White);
                buttons[activeButton].setColor(sf::Color::Red);
            }
            else{
                option = true;
                buttons[activeButton].setColor(sf::Color::Red);
            }
        }
        else{
            if(activeButton == 1){
                buttons[0].setColor(sf::Color::White);
                buttons[1].setColor(sf::Color::Red);
            }
        }
    }
}

void Board::pressSpace() {
    IS_NEW_ROUND = false;
}

void Board::moveLeft() {
    if(activeOption - 1 >= 0 && activeOption != activePlayer->hand.size() + 1)
        activeOption--;
    if(activeOption == activePlayer->hand.size() + 1){
        if(activeButton - 1 >= 0){
            buttons[activeButton].setColor(sf::Color::White);
            buttons[activeButton].setColor(sf::Color::Red);
        }
        else{
            buttons[activeButton].setColor(sf::Color::White);
            option = false;
            activeOption = activePlayer->hand.size() - 1;
        }
    }
}

int Board::getPressedOption(){
    if(activeOption < activePlayer->hand.size() + 1){
        return activeOption;
    }
    else{
        return activePlayer->hand.size() + activeButton;
    }
}

std::shared_ptr<Card> Board::getPressedCard() {
    if(activeOption != activePlayer->hand.size() + 1){
        return activePlayer->hand.at(activeOption);
    }
    else{

    }
}

void Board::throwCard() {

    std::cout << "Runda numer: " << round << std::endl;
    if(getPressedOption() < getActivePlayerHandSize()){
        //getPressedCard();
        std::cout<<"Wyrzucono: ";
        getPressedCard()->printCard();

        if(stack->throwToStack(getPressedCard())){
            activePlayer->hand.erase(std::find(activePlayer->hand.begin(),activePlayer->hand.end(),getPressedCard()));
            newRound();
        }else{
            return;
        }
    }
    else{
        if(getPressedOption() == getActivePlayerHandSize()){
            drawCard();
            newRound();
            std::cout<<"draw"<<std::endl;
        }
    }
}

void Board::newRound() {
    IS_NEW_ROUND = true;
    round++;
    bool found = false;
    stack->update();
    std::cout << "KOLOR: " << stack->getDesideredColor() << " WARTOSC: " << stack->getDesideredValue() << std::endl;
    /*for(auto player : players){
        std::shared_ptr<Player> current = player;
        if(found){previousPlayer = activePlayer; activePlayer = current;}
        if(player==activePlayer){found=true;}
    }*/

    auto oldAct = activePlayer;
    auto oldPrev = previousPlayer;
    auto oldNext = nextPlayer;
    auto oldLast = lastPlayer;

    activePlayer = oldNext;
    nextPlayer = oldLast;
    lastPlayer = oldPrev;
    previousPlayer = oldAct;

    std::cout << "Aktywny gracz:" << activePlayer->getNickname();

}

void Board::updateNicknames() {
    nicknames[0].setString(players.at((0+round)%4)->getNickname());
    nicknames[1].setString(players.at((1+round)%4)->getNickname());
    nicknames[2].setString(players.at((2+round)%4)->getNickname());
    nicknames[3].setString(players.at((3+round)%4)->getNickname());
}

void Board::drawCard() {
    activePlayer->hand.push_back(deck->cardCollection.back());
    deck->cardCollection.pop_back();
}
