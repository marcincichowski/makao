cmake_minimum_required(VERSION 3.14)
project(makao)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(makao main.cpp game_elements/sources/Cards.cpp game_elements/headers/Cards.h game_elements/sources/Player.cpp game_elements/headers/Player.h game_elements/sources/Deck.cpp game_elements/headers/Deck.h game_elements/sources/Stack.cpp game_elements/headers/Stack.h resources/gui/headers/Menu.h resources/gui/sources/Menu.cpp)

target_link_libraries(makao sfml-system sfml-window sfml-graphics)