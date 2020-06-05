#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_elements/headers/Cards.h"
#include "game_elements/headers/Player.h"
#include "game_elements/headers/Deck.h"
#include "game_elements/headers/Stack.h"
#include "resources/gui/headers/Menu.h"
void debug(){

}

int main(){


    Deck nowy;
    nowy.cardCollection.back()->printCard();

    sf::RenderWindow window(sf::VideoMode(800,600),"Makao");

    Menu menu(window.getSize().x, window.getSize().y);
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
                                std::cout<<"Rozpoczecie gry!!!";
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

        menu.draw(window);
        window.display();
    }
    return 0;
}
