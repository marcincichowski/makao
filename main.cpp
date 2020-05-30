#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/Cards.h"
#include "headers/Player.h"
#include "headers/Deck.h"
#include "headers/Stack.h"

int main(){

    sf::RenderWindow window(sf::VideoMode(800,600),"Makao");
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
               window.close();
            }
        }
    }
    return 0;
}
