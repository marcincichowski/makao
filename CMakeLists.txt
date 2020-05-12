cmake_minimum_required(VERSION 3.14)
project(makao)

set(CMAKE_CXX_STANDARD 14)

add_executable(makao main.cpp sources/Card.cpp headers/Card.h sources/Player.cpp headers/Player.h)