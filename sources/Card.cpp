//
// Created by Dawid on 12.05.2020.
//
#include <iostream>
#include "../headers/Card.h"

Card::Card(std::string signToSet, std::string colorToSet) : sign(signToSet), color(colorToSet) { std::cout << "Tworze " << sign << " " << color << std::endl; }
Card::~Card(){ std::cout << "Niszcze " << sign << " " << color << std::endl; }

std::string Card::getSign() { return sign; }          //zwraca znak
std::string Card::getColor(){ return color; }         //zwraca kolor