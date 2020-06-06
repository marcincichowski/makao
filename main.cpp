#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_elements/headers/Cards.h"
#include "game_elements/headers/Player.h"
#include "game_elements/headers/Deck.h"
#include "game_elements/headers/Stack.h"
#include "resources/gui/headers/Menu.h"
#include "resources/gui/headers/Board.h"
void debug(){

}

int main(){


    Deck nowy;

    sf::RenderWindow window(sf::VideoMode(1280,720),"Makao");

    int STATE = 0;
    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture background_texture;
    sf::Sprite background;
    background_texture.loadFromFile("../resources/background.jpg");
    background.setTexture(background_texture);
    background.setScale(window.getSize().x, window.getSize().y);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type){
                case sf::Event::Closed:{
                    window.close();
                    break;
                }
                case sf::Event::KeyReleased:{
                    switch(event.key.code){
                        case sf::Keyboard::Up:{
                            menu.MoveUp();
                            break;
                        }
                        case sf::Keyboard::Down:{
                            menu.MoveDown();
                            break;
                        }
                        case sf::Keyboard::Return:{
                            if(menu.getPressedItem() == 0){
                                STATE = 1;

                            }
                            if(menu.getPressedItem() == 1){
                                window.close();
                            }
                            break;
                        }
                    }
                    break;
                }

            }
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Up){
                    menu.MoveUp();
                }
                if(event.key.code == sf::Keyboard::Down){
                    menu.MoveDown();
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(background);
        if(STATE == 0){
            menu.draw(window);
        }
        else{
            sf::Texture tekstura;
            tekstura.loadFromFile("../resources/cards/card_back_red.png");
            sf::Sprite sprite = nowy.cardCollection.back()->draw();
            sprite.setTexture(tekstura);
            sprite.setScale(0.15,0.15);
            sprite.setPosition(640,250);
            window.draw(sprite);
        }
        window.display();
    }
    return 0;
}
