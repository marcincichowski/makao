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

    sf::RenderWindow window(sf::VideoMode(1280,720),"Makao");

    int STATE = 0;
    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture background_texture;
    sf::Sprite background;
    background_texture.loadFromFile("../resources/background.jpg");
    background.setTexture(background_texture);
    Board plansza(window.getSize().x, window.getSize().y, 4);
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
                        case sf::Keyboard::Left:{
                            plansza.moveLeft();
                            break;
                        }
                        case sf::Keyboard::Right:{
                            plansza.moveRight();
                            break;
                        }
                        case sf::Keyboard::Return:{
                            if(STATE == 2){
                                plansza.throwCard();
                            }
                            else{
                                if(menu.getPressedItem() == 0){
                                    STATE = 2;                              //gra
                                }else if(menu.getPressedItem() == 1) {
                                    //STATE = 1;                              //zasady
                                }else{
                                    window.close();                         //wyjscie
                                }
                            }

                            break;
                        }
                    }
                    break;
                }

            }
        }
        window.clear();
        window.draw(background);
        if(STATE == 0){
            menu.draw(window);
        }else if(STATE == 1) {
            //zasady.draw(window);

        }else if(STATE == 2){
            plansza.draw(window);
        }
        window.display();
    }
    return 0;
}
