//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
#include <iostream>
#include <iterator>

Board::Board(float width, float height){
    round=0;
    IS_NEW_ROUND = true;
    deck = std::make_shared<Deck>();
    stack = std::make_shared<Stack>();
    skippedRound =false;
    stack->getBoardStack()->push_back(deck->getCardCollection()->back());
    deck->getCardCollection()->pop_back();
    stack->update(stack->getFreezedBefore());

    //SET PROPERTIES OF BUTTONS
    font.loadFromFile("../assets/fonts/arial.TTF");


    buttons[0].setFont(font);
    buttons[0].setFillColor(sf::Color::White);
    buttons[0].setString(L"Dobierz kartę i zakończ turę");
    buttons[0].setPosition(sf::Vector2f(800,10 + 160 * 3));

    buttons[1].setFont(font);
    buttons[1].setFillColor(sf::Color::White);
    buttons[1].setPosition(sf::Vector2f(800,10 + 160 * 3));

    nickname.setFont(font);
    nickname.setFillColor(sf::Color::White);


    newRoundText.setFont(font);
    newRoundText.setFillColor(sf::Color::White);
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
    shapes[0].setColor(sf::Color(100,255,100));
    numbers[0].setColor(sf::Color(100,255,100));
    //load choose Text;

    shape_texture[0].loadFromFile("../resources/cards/karo_icon.png");
    shape_texture[1].loadFromFile("../resources/cards/trefl_icon.png");
    shape_texture[2].loadFromFile("../resources/cards/kier_icon.png");
    shape_texture[3].loadFromFile("../resources/cards/pik_icon.png");

    shape_icon.setScale(0.32,0.32);
    shape_icon.setPosition(sf::Vector2f(600, 5+160 * 3));

    for(auto texture : shape_texture){
        texture.setSmooth(true);
    }



    chooseShape.setFont(font);
    chooseShape.setFillColor(sf::Color::White);
    chooseShape.setString(L"Wybierz żądany kolor:");
    chooseShape.setPosition(sf::Vector2f(850, 250));

    chooseNumber.setFont(font);
    chooseNumber.setFillColor(sf::Color::White);
    chooseNumber.setString(L"Wybierz żądaną liczbę:");
    chooseNumber.setPosition(sf::Vector2f(880, 250));

    skippedRoundText[1].setFont(font);
    skippedRoundText[1].setFillColor(sf::Color::White);
    skippedRoundText[1].setString(L"Naciśnij spację aby kontynuować...");
    skippedRoundText[1].setPosition(sf::Vector2f(width/2 - 240, height/2 +20));


    skippedRoundText[0].setFont(font);
    skippedRoundText[0].setFillColor(sf::Color::White);
    skippedRoundText[0].setPosition(sf::Vector2f(width/2 - 260, height/2 - 20));


    background_texture.loadFromFile("../resources/background.jpg");
    game_background_texture.loadFromFile("../resources/game_background.jpg");
    background.setTexture(background_texture);
    game_background.setTexture(game_background_texture);

    zegar.restart();
    chooseWindowNumber = false;
    chooseWindowShape = false;

    activeChooseNumber = 0;
    activeChooseShape = 0;

    desiredColor = false;
    desiredNumber = false;

    desiredColorText.setFont(font);
    desiredColorText.setFillColor(sf::Color::White);
    desiredColorText.setPosition(sf::Vector2f(400,10 + 160 * 3));

    desiredNumberText.setFont(font);
    desiredNumberText.setFillColor(sf::Color::White);
    desiredNumberText.setPosition(sf::Vector2f(400, 10 + 160 * 3));

    places = 1;
    endGame = false;
}
Board::~Board() {}

void Board::initBoard(int playerCount){
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i+1), i+1));
    }
    activePlayer = players.at((round)%playerCount);
    giveaway();
}

void Board::draw(sf::RenderWindow &window) {
    int no = 0;
     if(!IS_NEW_ROUND){
         window.draw(game_background);
         if(activePlayer->getWin() && !chooseWindowNumber && !chooseWindowShape) {
             newRound();
         }
         if(activePlayer->getFreezedRounds()>0) {
            activePlayer->setFreezedRounds((activePlayer->getFreezedRounds()-1));
            newRound();
            return;
         }
        for(auto player : players) {
            if (player == activePlayer) {
                nickname.setFillColor(sf::Color::White);
                if (player->getWin()){
                    nickname.setString(player->getNickname() + " miejsce " + std::to_string(player->getPlace()) + ".");
                    switch (player->getPlace()) {
                        case 1: {
                            nickname.setOutlineThickness(1);
                            nickname.setFillColor(sf::Color(245, 209, 66));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                        case 2: {
                            nickname.setFillColor(sf::Color(115, 115, 115));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                        case 3: {
                            nickname.setFillColor(sf::Color(138, 87, 50));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                    }
                }
                else{
                    nickname.setString(player->getNickname());
                    nickname.setOutlineThickness(0);
                    nickname.setFillColor(sf::Color(255,255,255));
                }
                nickname.setPosition(sf::Vector2f(20, 10 + 160 * 3));
                window.draw(nickname);
            }
            else {
                if(player->getFreezedRounds()>0){
                    nickname.setFillColor(sf::Color(128, 223, 255));
                }else{nickname.setFillColor(sf::Color::White);}
                player->drawHiddenHand(window, no);
                if(!player->getWin()){
                    nickname.setString(player->getNickname());
                    nickname.setOutlineThickness(0);
                    nickname.setFillColor(sf::Color(255,255,255));
                }
                else{
                    nickname.setString(player->getNickname() + " miejsce " +std::to_string(player->getPlace()) + ".");
                    switch (player->getPlace()) {
                        case 1: {
                            nickname.setOutlineThickness(1);
                            nickname.setFillColor(sf::Color(245, 209, 66));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                        case 2: {
                            nickname.setFillColor(sf::Color(115, 115, 115));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                        case 3: {
                            nickname.setFillColor(sf::Color(138, 87, 50));
                            nickname.setOutlineColor(sf::Color::White);
                            break;
                        }
                    }
                }
                nickname.setPosition(sf::Vector2f(20, 10 + 160 * no));
                window.draw(nickname);
                no++;
            }
        }
        activePlayer->drawHand(window, activeOption,secondsWrong, zegar);
        deck->drawDeck(window);
        stack->drawStack(window);
        if(stack->getBoardStack()->size()==1 && deck->getCardCollection()->size()==0){
            buttons[0].setString(L"Zakończ turę");
            window.draw(buttons[0]);
        }else if(stack->getWar()){
            int count = (stack->getCardsToPull()>((stack->getBoardStack()->size()-1)+deck->getCardCollection()->size())?(stack->getBoardStack()->size()-1)+deck->getCardCollection()->size():stack->getCardsToPull());
            std::string cardsCount = std::to_string(count);
            buttons[0].setString("Pobierz karne karty: "+cardsCount);
            window.draw(buttons[0]);

        }
        else{
            buttons[0].setString(L"Dobierz kartę i zakończ turę");
            window.draw(buttons[0]);
        }

    }
    else{
        window.draw(background);
        if(skippedRound){window.draw(skippedRoundText[0]);window.draw(skippedRoundText[1]);return;}
        window.draw(newRoundText);
    }
    if(chooseWindowShape && !IS_NEW_ROUND){
        drawChooseShape(window);
    }
    if(chooseWindowNumber && !IS_NEW_ROUND){
        drawChooseNumber(window);
    }

    if(desiredColor && !IS_NEW_ROUND){
        window.draw(desiredColorText);
        window.draw(shape_icon);
    }
    if(desiredNumber && !IS_NEW_ROUND){
        window.draw(desiredNumberText);
    }

    //choose window draw
    //shapes


    //numbers


}

int Board::getPlayerCount() const {
    return players.size();
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
                buttons[activeButton].setFillColor(sf::Color::White);
                buttons[activeButton].setFillColor(sf::Color::Red);
            }
            else{
                option = true;
                buttons[activeButton].setFillColor(sf::Color::Red);
            }
        }
        else{
            if(activeButton == 1){
                buttons[0].setFillColor(sf::Color::White);
                buttons[1].setFillColor(sf::Color::Red);
            }
        }
    }
}

void Board::moveLeft() {
    if(activeOption - 1 >= 0 && activeOption != activePlayer->getHand()->size() + 1)
        activeOption--;
    if(activeOption == activePlayer->getHand()->size() + 1){
        if(activeButton - 1 >= 0){
            buttons[activeButton].setFillColor(sf::Color::White);
            buttons[activeButton].setFillColor(sf::Color::Red);
        }
        else{
            buttons[activeButton].setFillColor(sf::Color::White);
            option = false;
            activeOption = activePlayer->getHand()->size() - 1;
        }
    }
}

void Board::newRound() {
    IS_NEW_ROUND = true;

    round++;
    buttons[0].setFillColor(sf::Color::White);
    activeOption = 0;
    activeButton = 0;

    activePlayer = players.at((round)%getPlayerCount());
    if(activePlayer->getWin())
        round++;
    if(winners.size() >= 2 && activePlayer->getWin())
        round++;
    activePlayer = players.at((round)%getPlayerCount());

    if(activePlayer->getFreezedRounds()>0){
        skippedRound=true;
    }else{
        skippedRound = false;}
    if(!skippedRound) {
        std::string toDisplay =
                "Tura Gracza " + (std::to_string(activePlayer->getPlayerNo())) + ". Nacisnij spacje aby kontynuowac...";
        newRoundText.setString(toDisplay);
    }else{
        std::string toDisplay ="Gracz " + (std::to_string(activePlayer->getPlayerNo())) + " musi czekac. Pozostalo tur: "+(std::to_string(activePlayer->getFreezedRounds()));
        skippedRoundText[0].setString(toDisplay);
        skippedRoundText[0].setString(toDisplay);
        stack->setFreezedBefore();
    }
    stack->update(stack->getFreezedBefore());
    stack->unsetFreezenBefore();
    zegar.restart();
}

void Board::throwCard() {
    if (getPressedOption() < getActivePlayerHandSize()) {

        if (stack->throwToStack(getPressedCard())) {

            if(getPressedCard()->printValue()=="4"){stack->setFreshFour();}
            if(getPressedCard()->printValue() == "J" && !chooseWindowNumber)
                chooseWindowNumber = true;
            if(getPressedCard()->printValue() == "A" && !chooseWindowShape)
                chooseWindowShape = true;
            if(desiredColor){
                desiredColor = false;
                stack->unsetWantedColor();
            }
            if(desiredNumber){
                desiredNumber = false;
                stack->unsetWantedValue();
            }
            activePlayer->getHand()->erase(std::find(activePlayer->getHand()->begin(), activePlayer->getHand()->end(), getPressedCard()));
            if(activePlayer->getHand()->size() == 0){
                activePlayer->setWin();
                activePlayer->setPlace(places);
                places++;

                winners.push_back(activePlayer->getPlayerNo());
                if(winCheck())
                    return;
            }
            if(!chooseWindowNumber && !chooseWindowShape)
                newRound();
        } else {
            zegar.restart();
            secondsWrong = zegar.getElapsedTime();
            return;
        }
    } else {
        if (getPressedOption() == getActivePlayerHandSize()) {
            if(stack->getBoardStack()->size()==1 && deck->getCardCollection()->size()==0){
                newRound();
            }else if (!(stack->getWar())) {
                drawCard();
                if(stack->getRoundsToWait()>0 && activePlayer->getFreezedRounds()==0){
                    stack->unsetFreshFour();
                    activePlayer->setFreezedRounds(stack->getRoundsToWait());
                    stack->resetRoundsToWait();
                }
                newRound();
                stack->cancelWar();
            } else {
                for (int i = 0; i < stack->getCardsToPull(); i++) {
                    drawCard();
                }
                newRound();
                stack->cancelWar();
            }
        }
    }
}
bool Board::winCheck(){
    int winCount = 0;
    int maxPlayers = getPlayerCount();

    for(auto player : players){
        if(player->getWin())
            winCount++;
    }
    if(winCount+1 == maxPlayers){
        winners.push_back(players.at((round+1)%getPlayerCount())->getPlayerNo());
        endGame = true;
        return true;
    }
    else{
        endGame = false;
        return false;
    }
}
std::shared_ptr<Card> Board::getPressedCard() {
    if(activeOption != activePlayer->getHand()->size() + 1){
        return activePlayer->getHand()->at(activeOption);
    }else{
        return nullptr;
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
    if(!(stack->getBoardStack()->size()==1 && deck->getCardCollection()->size()==0)){
        checkDeck();
        activePlayer->getHand()->push_back(deck->getCardCollection()->back());
        deck->getCardCollection()->pop_back();
        checkDeck();
    }else{
        return;
    }
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
        return true;
    }else{
        return true;
    }
}

bool Board::getIsNewRound() const {
    return IS_NEW_ROUND;
}

void Board::drawChooseShape(sf::RenderWindow &window){
    for(int i = 0; i < 4; i++)
        window.draw(shapes[i]);
    window.draw(chooseShape);
}

void Board::drawChooseNumber(sf::RenderWindow &window) {
    for (int i = 0; i < 6; i++)
        window.draw(numbers[i]);
    window.draw(chooseNumber);
}

sf::Sprite Board::getBackground() {
    return background;
}

void Board::chooseMoveLeftShape() {
    if(activeChooseShape > 0){
        shapes[activeChooseShape].setColor(sf::Color(255,255,255));
        activeChooseShape--;
        shapes[activeChooseShape].setColor(sf::Color(100,255,100));
    }
}

void Board::chooseMoveRightShape() {
    if(activeChooseShape + 1 < 4){
        shapes[activeChooseShape].setColor(sf::Color(255,255,255));
        activeChooseShape++;
        shapes[activeChooseShape].setColor(sf::Color(100,255,100));
    }

}

void Board::chooseMoveRightNumber() {
    if(activeChooseNumber + 1 < 6){
        numbers[activeChooseNumber].setColor(sf::Color(255,255,255));
        activeChooseNumber++;
        numbers[activeChooseNumber].setColor(sf::Color(100,255,100));
    }
}

void Board::chooseMoveLeftNumber() {
    if(activeChooseNumber > 0){
        numbers[activeChooseNumber].setColor(sf::Color(255,255,255));
        activeChooseNumber--;
        numbers[activeChooseNumber].setColor(sf::Color(100,255,100));
    }
}

bool Board::getChooseWindowShape() const{
    return chooseWindowShape;
}

bool Board::getChooseWindowNumber() const {
    return chooseWindowNumber;
}

void Board::getSelectedWindowNumber(sf::RenderWindow &window) {
    chooseWindowNumber = false;
    desiredNumber = true;
    stack->setWantedValue();
    switch(activeChooseNumber){
        case 0:{
            stack->setDesiredValue(piec);
            desiredNumberText.setString(L"Żądana wartość: 5");
            break;
        }
        case 1:{
            stack->setDesiredValue(szesc);
            desiredNumberText.setString(L"Żądana wartość: 6");
            break;
        }
        case 2:{
            stack->setDesiredValue(siedem);
            desiredNumberText.setString(L"Żądana wartość: 7");
            break;
        }
        case 3:{
            stack->setDesiredValue(osiem);
            desiredNumberText.setString(L"Żądana wartość: 8");
            break;
        }
        case 4:{
            stack->setDesiredValue(dziewiec);
            desiredNumberText.setString(L"Żądana wartość: 9");
            break;
        }
        case 5:{
            stack->setDesiredValue(dziesiec);
            desiredNumberText.setString(L"Żądana wartość: 10");
            break;
        }

    }
    newRound();
}

void Board::getSelectedWindowShape(sf::RenderWindow &window) {
    chooseWindowShape = false;
    desiredColor = true;
    stack->setWantedColor();
    switch(activeChooseShape) {
        case 0: {
            stack->setDesiredColor(karo);
            desiredColorText.setString(L"Żądany kolor:");
            shape_icon.setTexture(shape_texture[0]);
            break;
        }
        case 1: {
            stack->setDesiredColor(trefl);
            desiredColorText.setString(L"Żądany kolor:");
            shape_icon.setTexture(shape_texture[1]);
            break;
        }
        case 2: {
            stack->setDesiredColor(kier);
            desiredColorText.setString(L"Żądany kolor:");
            shape_icon.setTexture(shape_texture[2]);
            break;
        }
        case 3: {
            stack->setDesiredColor(pik);
            desiredColorText.setString(L"Żądany kolor:");
            shape_icon.setTexture(shape_texture[3]);
            break;
        }
    }
    newRound();
}



Board::Board() {}

std::vector<int> *Board::getWinners() {
    return &winners;
}

bool Board::getWinCheck() const {
    return endGame;
}


