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

    stack->getBoardStack()->push_back(deck->getCardCollection()->back());
    deck->getCardCollection()->pop_back();
    stack->update();
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i+1), i+1));
        //std::cout << "+ Gracz " << i << std::endl;
    }
    activePlayer = players.at((round)%4);
    giveaway();

    //SET PROPERTIES OF BUTTONS
    if(!font.loadFromFile("../assets/fonts/arial.TTF")){
        //std::cout<<"error font loading";
    }

    buttons[0].setFont(font);
    buttons[0].setColor(sf::Color::White);
    buttons[0].setString(L"Dobierz kartę i zakończ turę");
    buttons[0].setPosition(sf::Vector2f(800,10 + 160 * 3));

    buttons[1].setFont(font);
    buttons[1].setColor(sf::Color::White);
    buttons[1].setPosition(sf::Vector2f(800,10 + 160 * 3));

    nickname.setFont(font);
    nickname.setColor(sf::Color::White);


    newRoundText.setFont(font);
    newRoundText.setColor(sf::Color::White);
    newRoundText.setString(L"Rozpoczyna Gracz 1. Naciśnij spację aby rozpocząć grę...");
    newRoundText.setPosition(sf::Vector2f(width/2 - 350, height/2 - 20));

    activeButton = 0;
    activeOption = 0;
    option = false;

    //load choose cards
    shapesTextures[0].loadFromFile("../resources/cards/color_D.png");
    shapesTextures[1].loadFromFile("../resources/cards/color_C.png");
    shapesTextures[2].loadFromFile("../resources/cards/color_H.png");
    shapesTextures[3].loadFromFile("../resources/cards/color_S.png");
    numbersTextures[0].loadFromFile("../resources/cards/value_5.png");
    numbersTextures[1].loadFromFile("../resources/cards/value_6.png");
    numbersTextures[2].loadFromFile("../resources/cards/value_7.png");
    numbersTextures[3].loadFromFile("../resources/cards/value_8.png");
    numbersTextures[4].loadFromFile("../resources/cards/value_9.png");
    numbersTextures[5].loadFromFile("../resources/cards/value_10.png");
    for(int i = 0; i < 4; i++){
        shapes[i].setTexture(shapesTextures[i]);
        shapes[i].setScale(0.15,0.15);
        shapes[i].setPosition(sf::Vector2f(920 + 25*i,300));
    }
    for(int i = 0; i < 6; i++){
        numbers[i].setTexture(numbersTextures[i]);
        numbers[i].setScale(0.15, 0.15);
        numbers[i].setPosition(sf::Vector2f(920 + 25*i,300));
    }

    //load choose Text;

    chooseShape.setFont(font);
    chooseShape.setColor(sf::Color::White);
    chooseShape.setString(L"Wybierz żądany kolor:");
    chooseShape.setPosition(sf::Vector2f(850, 250));

    chooseNumber.setFont(font);
    chooseNumber.setColor(sf::Color::White);
    chooseNumber.setString(L"Wybierz żądaną liczbę:");
    chooseNumber.setPosition(sf::Vector2f(880, 250));

}
Board::~Board() {}

void Board::draw(sf::RenderWindow &window) {
    int no = 0;
     if(!IS_NEW_ROUND){
        for(auto player : players) {
            if (player == activePlayer) {
                player->drawHand(window, 3);
                nickname.setString(player->getNickname());
                nickname.setPosition(sf::Vector2f(20, 10 + 160 * 3));
                window.draw(nickname);
            }
            else {
                player->drawHiddenHand(window, no);
                nickname.setString(player->getNickname());
                nickname.setPosition(sf::Vector2f(20, 10 + 160 * no));
                window.draw(nickname);
                no++;
            }
        }

        activePlayer->drawHand(window, activeOption);
        deck->drawDeck(window);
        stack->drawStack(window);

        if(stack->getWar()){
            buttons[0].setString("Pobierz karne karty: "+std::to_string(stack->getCardsToPull()));
            window.draw(buttons[0]);

        }
        else{
            buttons[0].setString(L"Dobierz kartę i zakończ turę");
            window.draw(buttons[0]);
        }

    }
    else{
        window.draw(newRoundText);
    }

    //choose window draw
    //shapes


    //numbers


}

int Board::getPlayerCount() const {
    return players.capacity();
}

void Board::giveaway() {
    for(auto player : players){
        for(int i = 0;i<5;i++){
            player->getHand()->push_back(deck->getCardCollection()->back());
            deck->getCardCollection()->pop_back();
        }
    }
}

void Board::moveRight() {
    if(activeOption + 1 < activePlayer->getHand()->size())
        activeOption++;
    else{
        activeOption = activePlayer->getHand()->size() + 1;
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

void Board::moveLeft() {
    if(activeOption - 1 >= 0 && activeOption != activePlayer->getHand()->size() + 1)
        activeOption--;
    if(activeOption == activePlayer->getHand()->size() + 1){
        if(activeButton - 1 >= 0){
            buttons[activeButton].setColor(sf::Color::White);
            buttons[activeButton].setColor(sf::Color::Red);
        }
        else{
            buttons[activeButton].setColor(sf::Color::White);
            option = false;
            activeOption = activePlayer->getHand()->size() - 1;
        }
    }
}

void Board::newRound() {
    IS_NEW_ROUND = true;

    round++;
    stack->update();
    buttons[0].setColor(sf::Color::White);
    activeOption = 0;
    activeButton = 0;
    activePlayer = players.at((round)%4);

    std::string toDisplay = "Tura Gracza "+(std::to_string(activePlayer->getPlayerNo()))+". Nacisnij spacje aby kontynuowac...";
    newRoundText.setString(toDisplay);

    //std::cout << "Aktywny gracz:" << activePlayer->getNickname();
}



void Board::throwCard() {

    //std::cout << "Runda numer: " << round << std::endl;
    if (getPressedOption() < getActivePlayerHandSize()) {
        //std::cout<<"Wyrzucono: ";
        getPressedCard()->printCard();

        if (stack->throwToStack(getPressedCard())) {
            activePlayer->getHand()->erase(
                    std::find(activePlayer->getHand()->begin(), activePlayer->getHand()->end(), getPressedCard()));
            newRound();
        } else {
            return;
        }
    } else {
        if (getPressedOption() == getActivePlayerHandSize()) {
            if (!(stack->getWar())) {
                drawCard();
                newRound();
                stack->cancelWar();
            } else {
                //std::cout<<"draw"<<std::endl;}
                for (int i = 0; i < stack->getCardsToPull(); i++) {
                    drawCard();
                }
                newRound();
                stack->cancelWar();
            }
        }
    }
}

std::shared_ptr<Card> Board::getPressedCard() {
    if(activeOption != activePlayer->getHand()->size() + 1){
        return activePlayer->getHand()->at(activeOption);
    }
    else{

    }
}

void Board::pressSpace() {
    IS_NEW_ROUND = false;
}

int Board::getPressedOption(){
    if(activeOption < activePlayer->getHand()->size() + 1){
        return activeOption;
    }
    else{
        return activePlayer->getHand()->size() + activeButton;
    }
}

int Board::getActivePlayerHandSize(){
    return activePlayer->getHand()->size();
}

void Board::drawCard() {
    checkDeck();
    activePlayer->getHand()->push_back(deck->getCardCollection()->back());
    deck->getCardCollection()->pop_back();
    checkDeck();
}

bool Board::checkDeck() {
    if(deck->getCardCollection()->size()==0 && stack->getBoardStack()->size()<=1){return false;}
    else if(deck->getCardCollection()->size()==0) {
        std::shared_ptr<Card> topCard = stack->topCard();
        stack->getBoardStack()->pop_back();

        while (!(stack->getBoardStack()->empty())) {
            deck->getCardCollection()->push_back(stack->getBoardStack()->back());
            stack->getBoardStack()->pop_back();
        }
        stack->getBoardStack()->push_back(topCard);

        //std::cout << "\nsPrzelozone karty, teraz:" << deck->getCardCollection()->size();
        return true;
    }else{
        //std::cout << "Deck jest git";
        return true;
    }
}

bool Board::getIsNewRound() const {
    return IS_NEW_ROUND;
}

void Board::drawChooseShape(sf::RenderWindow window){
    for(int i = 0; i < 4; i++)
      window.draw(shapes[i]);
    window.draw(chooseShape);
}

void Board::drawChooseNumber(sf::RenderWindow window){
    for(int i = 0; i < 6; i++)
        window.draw(numbers[i]);
    window.draw(chooseNumber);
}


























