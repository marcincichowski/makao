//
// Created by marci on 06.06.2020.
//

#include "../headers/Menu.h"
#include <iostream>
Menu::Menu(float width, float height){
    if(!font.loadFromFile("../assets/fonts/arial.TTF")){
        std::cout<<"error font loading";
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    sf::String option1(L"Nowa Gra");
    menu[0].setString(option1);
    menu[0].setPosition(sf::Vector2f(width / 2  - 50, height / (NUMBER_OF_ITEMS + 1) + 100));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    sf::String option2(L"Zasady gry");
    menu[1].setString(option2);
    menu[1].setPosition(sf::Vector2f(width / 2 - 55, height / (NUMBER_OF_ITEMS + 1) + 150));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    sf::String option3(L"Wyjście");
    menu[2].setString(option3);
    menu[2].setPosition(sf::Vector2f(width / 2 - 35, height / (NUMBER_OF_ITEMS + 1) + 200));

    title.setFont(font);
    title.setColor(sf::Color::White);
    title.setString(L"Makao");
    title.setCharacterSize(100);
    title.setOutlineColor(sf::Color::Red);
    title.setOutlineThickness(1);
    title.setPosition(sf::Vector2f(width / 2 - 120, height / (NUMBER_OF_ITEMS+ 1)-100));
    selectedItemIndex = 0;
}

Menu::~Menu(){}

void Menu::draw(sf::RenderWindow &window){
    window.draw(title);
    for(int i = 0; i < NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
}

void Menu::MoveUp(){
    if(selectedItemIndex -1 >= 0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){
    if(selectedItemIndex + 1 < NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

int Menu::getPressedItem() {
    return selectedItemIndex;
}