//
// Created by marci on 06.06.2020.
//

#include "../headers/Menu.h"
#include <iostream>
Menu::Menu(float width, float height){
    if(!font.loadFromFile("../assets/fonts/arial.TTF")){
        //std::cout<<"error font loading";
    }

    for(int i = 0;i<NUMBER_OF_ITEMS;i++){
        menu[i].setFont(font);
        menu[i].setFillColor(sf::Color(255,255,255));
    }

    menu[0].setFillColor(sf::Color(255, 51, 51));

    sf::String option1(L"Nowa Gra");
    menu[0].setString(option1);
    menu[0].setPosition(sf::Vector2f(width / 2  - 250, height / (NUMBER_OF_ITEMS + 1) + 100));

    sf::String option2(L"Zasady gry");
    menu[1].setString(option2);
    menu[1].setPosition(sf::Vector2f(width / 2 - 255, height / (NUMBER_OF_ITEMS + 1) + 150));

    sf::String option3(L"Wyjście");
    menu[2].setString(option3);
    menu[2].setPosition(sf::Vector2f(width / 2 - 235, height / (NUMBER_OF_ITEMS + 1) + 200));

    title.setFont(font);
    title.setFillColor(sf::Color(255,255,255));
    title.setString(L"Makao");
    title.setCharacterSize(100);
    title.setOutlineColor(sf::Color(255,51,51));
    title.setOutlineThickness(1);
    title.setPosition(sf::Vector2f(width / 2 - 320, height / (NUMBER_OF_ITEMS+ 1)-100));
    selectedItemIndex = 0;

    logo.loadFromFile("../resources/cards/cards.png");
    logo.setSmooth(true);
    logoImage.setTexture(logo);
    logoImage.setScale(0.2,0.2);

    title2.setString(L"Wybierz ilość graczy");
    title2.setFont(font);
    title2.setFillColor(sf::Color(255,255,255));
    title2.setPosition(sf::Vector2f(width / 2 - 320, height / (NUMBER_OF_ITEMS+ 1)+100));
}

void Menu::changeString(sf::RenderWindow &window){
    int height = window.getSize().y;
    int width = window.getSize().x;
    menu[0].setString(L"2 graczy");
    menu[1].setString(L"3 graczy");
    menu[2].setString(L"4 graczy");
    menu[0].setPosition(sf::Vector2f(width / 2  - 250, height / (NUMBER_OF_ITEMS + 1) + 150));
    menu[1].setPosition(sf::Vector2f(width / 2 - 250, height / (NUMBER_OF_ITEMS + 1) + 200));
    menu[2].setPosition(sf::Vector2f(width / 2 - 250, height / (NUMBER_OF_ITEMS + 1) + 250));
    window.draw(title2);
    draw(window);
}
Menu::~Menu(){}

void Menu::draw(sf::RenderWindow &window){
    window.draw(title);
    for(int i = 0; i < NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
    logoImage.setPosition(sf::Vector2f(window.getSize().x/2+70, window.getSize().y/2-200));
    window.draw(logoImage);
}

void Menu::MoveUp(){
    if(selectedItemIndex -1 >= 0){
        menu[selectedItemIndex].setFillColor(sf::Color(255,255,255));
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color(255,51,51));
    }
}

void Menu::MoveDown(){
    if(selectedItemIndex + 1 < NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setFillColor(sf::Color(255,255,255));
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color(255,51,51));
    }
}

int Menu::getPressedItem() {
    return selectedItemIndex;
}