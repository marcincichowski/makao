//
// Created by marci on 06.06.2020.
//

#ifndef MAKAO_MENU_H
#define MAKAO_MENU_H
#include "SFML/Graphics.hpp"

#define NUMBER_OF_ITEMS 3

class Menu{
private:
    int selectedItemIndex;
    sf::Text title;
    sf::Font font;
    sf::Text menu[NUMBER_OF_ITEMS];
    sf::Texture logo;
    sf::Sprite logoImage;
    sf::Text title2;
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int getPressedItem();
    void changeString(sf::RenderWindow &window);
};

#endif //MAKAO_MENU_H
