//
// Created by Dawid on 12.05.2020.
//

#ifndef MAKAO_GAMEBOARD_H
#define MAKAO_GAMEBOARD_H


class GameBoard{
private:
    PlayersList playersInCurrentGame;       //gracze aktualnej rozgrywki
    Deck shuffledCards;                     //potasowane karty gotowe do rozdawania
    Stack thrownCards;                      //stos wyrzuconych kart
public:
    Board(){ std::cout << "Tworze nowa plansze.\n"; }
    ~Board(){ std::cout << "Niszcze plansze.\n"; }
};


#endif //MAKAO_GAMEBOARD_H
