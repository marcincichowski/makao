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
    sf::Image icon;
    icon.loadFromFile("../resources/icon.png");
    sf::RenderWindow window(sf::VideoMode(1280,720),"Makao");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit( 30 );

    int STATE = 0;
    Menu menu(window.getSize().x, window.getSize().y);


    Board plansza(window.getSize().x, window.getSize().y);
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
                            if(plansza.getChooseWindowNumber())
                                plansza.chooseMoveLeftNumber();
                            else if(plansza.getChooseWindowShape())
                                plansza.chooseMoveLeftShape();
                            else if(!plansza.getIsNewRound())
                                plansza.moveLeft();
                            break;
                        }
                        case sf::Keyboard::Right:{
                            if(plansza.getChooseWindowNumber())
                                plansza.chooseMoveRightNumber();
                            else if(plansza.getChooseWindowShape())
                                plansza.chooseMoveRightShape();
                            else if(!plansza.getIsNewRound())
                                plansza.moveRight();
                            break;
                        }
                        case sf::Keyboard::Space:{
                            plansza.pressSpace();
                            break;
                        }
                        case sf::Keyboard::Return:{
                            //if(plansza.getChooseWindowShape())
                                //choose
                            //if(plansza.getChooseWindowNumber())
                                //choose
                            if(plansza.getChooseWindowNumber())
                                plansza.getSelectedWindowNumber();
                            else if(plansza.getChooseWindowShape())
                                plansza.getSelectedWindowShape();
                            else if(STATE == 2){
                                plansza.throwCard();
                            }
                            else if(STATE == 3){
                                plansza.initBoard(menu.getPressedItem()+2);
                                STATE = 2;
                            }
                            else if(STATE == 4){
                                STATE = 0;
                            }
                            else{
                                if(menu.getPressedItem() == 0){
                                    STATE = 3;                              //gra
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
        window.draw(plansza.getBackground());
        if(STATE == 0){
            menu.draw(window);
        }else if(STATE == 1) {
            //zasady.draw(window);

        }else if(STATE == 2){
            plansza.draw(window);
        }
        else if(STATE == 3){
            menu.changeString(window);
        }
        else if(STATE == 4){
            menu.changeString(window);
        }
        window.display();
    }
    return 0;
}
