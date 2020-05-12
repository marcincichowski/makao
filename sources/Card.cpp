//
// Created by Dawid on 12.05.2020.
//
#include <iostream>
#include "../headers/Card.h"

Card::Card(std::string signToSet, std::string colorToSet) : sign(signToSet), color(colorToSet) { std::cout << "Tworze " << sign << " " << color << "\n"; }
Card::~Card(){ std::cout << "Usuwam " << sign << " " << color << "\n"; }

std::string Card::getSign() { return sign; }          //zwraca znak
std::string Card::getColor(){ return color; }         //zwraca kolor

void Card::displayCardInfo() const { std::cout << color << " " << sign << "\n"; }