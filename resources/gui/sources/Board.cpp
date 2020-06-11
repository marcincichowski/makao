//
// Created by marci on 06.06.2020.
//
#include "../headers/Board.h"
//#include "../game_elements/Deck.h"
#include <iostream>
#include <iterator>
#include <unordered_set>

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
    shapes[0].setColor(sf::Color(100,255,100));
    numbers[0].setColor(sf::Color(100,255,100));
    //load choose Text;

    shape_texture[0].loadFromFile("../resources/cards/karo_icon.png");
    shape_texture[1].loadFromFile("../resources/cards/trefl_icon.png");
    shape_texture[2].loadFromFile("../resources/cards/kier_icon.png");
    shape_texture[3].loadFromFile("../resources/cards/pik_icon.png");

    shape_icon.setScale(0.32,0.32);
    shape_icon.setPosition(sf::Vector2f(600, 5+160 * 3));



    chooseShape.setFont(font);
    chooseShape.setColor(sf::Color::White);
    chooseShape.setString(L"Wybierz żądany kolor:");
    chooseShape.setPosition(sf::Vector2f(850, 250));

    chooseNumber.setFont(font);
    chooseNumber.setColor(sf::Color::White);
    chooseNumber.setString(L"Wybierz żądaną liczbę:");
    chooseNumber.setPosition(sf::Vector2f(880, 250));

    skippedRoundText[1].setFont(font);
    skippedRoundText[1].setColor(sf::Color::White);
    skippedRoundText[1].setString(L"Naciśnij spację aby kontynuować...");
    skippedRoundText[1].setPosition(sf::Vector2f(width/2 - 240, height/2 +20));


    skippedRoundText[0].setFont(font);
    skippedRoundText[0].setColor(sf::Color::White);
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
    desiredColorText.setColor(sf::Color::White);
    desiredColorText.setPosition(sf::Vector2f(400,10 + 160 * 3));

    desiredNumberText.setFont(font);
    desiredNumberText.setColor(sf::Color::White);
    desiredNumberText.setPosition(sf::Vector2f(400, 10 + 160 * 3));
}
Board::~Board() {}

void Board::initBoard(int playerCount){
    for(int i = 0;i<playerCount;i++) {
        players.push_back(std::make_shared<Player>("Gracz "+std::to_string(i+1), i+1));
        //std::cout << "+ Gracz " << i << std::endl;
    }
    activePlayer = players.at((round)%playerCount);
    giveaway();
}

void Board::draw(sf::RenderWindow &window) {
    int no = 0;

     if(!IS_NEW_ROUND){
         window.draw(game_background);
         if(activePlayer->getFreezedRounds()>0) {
            activePlayer->setFreezedRounds((activePlayer->getFreezedRounds()-1));
            newRound();
            return;
         }
        for(auto player : players) {
            if (player == activePlayer) {
                //player->drawHand(window, 3,secondsWrong, zegar);

                nickname.setColor(sf::Color::White);
                nickname.setString(player->getNickname());
                nickname.setPosition(sf::Vector2f(20, 10 + 160 * 3));
                window.draw(nickname);
            }
            else {
                if(player->getFreezedRounds()>0){
                    nickname.setColor(sf::Color(128, 223, 255));
                }else{nickname.setColor(sf::Color::White);}
                player->drawHiddenHand(window, no);
                nickname.setString(player->getNickname());
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
    buttons[0].setColor(sf::Color::White);
    activeOption = 0;
    activeButton = 0;
    activePlayer = players.at((round)%getPlayerCount());
    if(activePlayer->getFreezedRounds()>0){
        skippedRound=true;
    }else{
        skippedRound = false;}
    if(!skippedRound) {
        std::string toDisplay =
                "Tura Gracza " + (std::to_string(activePlayer->getPlayerNo())) + ". Nacisnij spacje aby kontynuowac...";
        newRoundText.setString(toDisplay);
        std::cout << "NIE WCHODZE";
    }else{
        std::string toDisplay ="Gracz " + (std::to_string(activePlayer->getPlayerNo())) + " musi czekac. Pozostalo tur: "+(std::to_string(activePlayer->getFreezedRounds()));
        skippedRoundText[0].setString(toDisplay);
        skippedRoundText[0].setString(toDisplay);
        std::cout << "WCHODZE";
        stack->setFreezedBefore();
    }
    stack->update(stack->getFreezedBefore());
    stack->unsetFreezenBefore();
    zegar.restart();
    //std::cout << "Aktywny gracz:" << activePlayer->getNickname();
}

void Board::throwCard() {

    //std::cout << "Runda numer: " << round << std::endl;
    if (getPressedOption() < getActivePlayerHandSize()) {
        //std::cout<<"Wyrzucono: ";
        getPressedCard()->printCard();
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
    std::cout<<activeChooseNumber;
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
    std::cout<<activeChooseShape;
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

bool Board::wonCheck() {
    for(auto player : players){
        if(player->getHand()->size()==0){
            return true;
        }
    }
    return true;
}

