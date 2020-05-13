cmake_minimum_required(VERSION 3.14)
project(makao)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(makao main.cpp)

target_link_libraries(makao sfml-system sfml-window sfml-graphics)