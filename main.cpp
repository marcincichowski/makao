#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_elements/headers/Cards.h"
#include "game_elements/headers/Player.h"
#include "game_elements/headers/Deck.h"
#include "game_elements/headers/Stack.h"

void debug(){

}

int main(){


    Deck nowy;
    nowy.cardCollection.back()->printCard();

    sf::RenderWindow window(sf::VideoMode(800,600),"Makao");
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
               window.close();
            }
        }
        window.clear(sf::Color::Black);
        sf::Font arial;
        if(!arial.loadFromFile("../assets/fonts/arial.ttf")){
            std::cout << "error loading font";
        }
        else{
            sf::Text title;
            title.setFont(arial);
            title.setString("Makao");
            title.setCharacterSize(24);
            title.setFillColor(sf::Color::White);
            title.setStyle(sf::Text::Bold);
            title.setPosition(370, 50);
            window.draw(title);
        }


        window.display();
    }
    return 0;
}
